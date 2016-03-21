/*
Copyright (c) 2016 Giovanni Petrantoni

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

//
//  NativeDynamicLinking.c
//  NativePath
//
//  Created by Giovanni Petrantoni on 03/17/16.
//  Copyright © 2016 Giovanni Petrantoni. All rights reserved.
//

#ifdef _WIN32
   #define NATIVE_PATH_WIN
   //define something for Windows (32-bit and 64-bit, this part is common)
   #include <windows.h>
   #include <stdio.h>
   
   #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
   // This code is for Win32 desktop apps
   #define NATIVE_PATH_WIN_DESKTOP
   #else
   // This code is for WinRT Windows Store apps
   #define NATIVE_PATH_WIN_APP
   #endif

   #ifdef _WIN64
      //define something for Windows (64-bit only)
   #endif
#elif __APPLE__
    #include "TargetConditionals.h"
    #include <dlfcn.h>
    #if TARGET_IPHONE_SIMULATOR
    #define NATIVE_PATH_IOS
         // iOS Simulator
    #elif TARGET_OS_IPHONE
    #define NATIVE_PATH_IOS
        // iOS device
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
    #   error "Unknown Apple platform"
    #endif
#elif __linux__
	#define NATIVE_PATH_LINUX
    // linux
	#include <stdlib.h>
	#include <stdio.h>
	#include <dlfcn.h>	
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#elif defined(__ANDROID__)
	#define NATIVE_PATH_ANDROID
	#include <stdlib.h>
	#include <stdio.h>
	#include <dlfcn.h>
#else
#   error "Unknown compiler"
#endif

void* LoadDynamicLibrary(const char* libraryPath)
{
#ifndef NATIVE_PATH_IOS
	char nameBuffer[2048];
#endif
		
#if defined(NATIVE_PATH_LINUX) || defined(NATIVE_PATH_ANDROID)
	sprintf(nameBuffer, "%s.so", libraryPath);
	return dlopen(nameBuffer, RTLD_NOW);
#endif

#ifdef NATIVE_PATH_WIN_DESKTOP
	sprintf_s(nameBuffer, 2048, "%s.dll", libraryPath);
	return LoadLibraryA(nameBuffer);
#endif

#ifdef NATIVE_PATH_WIN_APP
	sprintf_s(nameBuffer, 2048, "%s.dll", libraryPath);
	wchar_t wString[2048];
	MultiByteToWideChar(CP_ACP, 0, nameBuffer, -1, wString, 2048);
	return LoadPackagedLibrary(wString, 0);
#endif

#ifdef NATIVE_PATH_IOS
    //under ios we try open the executable itself
    return dlopen(0, RTLD_NOW);
#endif
	
	return 0;
}

void FreeDynamicLibrary(void* handle)
{
#if defined(NATIVE_PATH_LINUX) || defined(NATIVE_PATH_ANDROID) || defined(NATIVE_PATH_IOS)
	dlclose(handle);
#endif
	
#ifdef NATIVE_PATH_WIN
	FreeLibrary(handle);
#endif
}

void* GetSymbolAddress(void* handle, const char* symbolName)
{
#if defined(NATIVE_PATH_LINUX) || defined(NATIVE_PATH_ANDROID) || defined(NATIVE_PATH_IOS)
    return dlsym(handle, symbolName);
#endif
	
#ifdef NATIVE_PATH_WIN
	return GetProcAddress(handle, symbolName);
#endif
	
	return 0;
}
