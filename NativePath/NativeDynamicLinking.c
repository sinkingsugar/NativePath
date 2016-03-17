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
   #ifdef _WIN64
      //define something for Windows (64-bit only)
   #endif
#elif __APPLE__
    #include "TargetConditionals.h"
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
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
    // linux
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#else
#   error "Unknown compiler"
#endif

void* LoadLibrary(const char* libraryPath)
{
	char nameBuffer[2048];
		
#ifdef NATIVE_PATH_LINUX
	sprintf(nameBuffer, "%s.so", libraryPath);
	return dlopen(nameBuffer, RTLD_NOW);
#endif

#ifdef NATIVE_PATH_WIN
	sprintf(nameBuffer, "%s.dll", libraryPath);
	return LoadLibraryA(nameBuffer);
#endif
}

void FreeLibrary(void* handle)
{
#ifdef NATIVE_PATH_LINUX
	dlclose(handle);
#endif
	
#ifdef NATIVE_PATH_WIN
	FreeLibrary(handle);
#endif
}

void* GetSymbolAddress(void* handle, const char* symbolName)
{
#ifdef NATIVE_PATH_LINUX
 return dlsym(handle, symbolName);
#endif
	
#ifdef NATIVE_PATH_WIN
	return GetProcAddressA(handle, symbolName);
#endif
}
