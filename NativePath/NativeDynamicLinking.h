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
//  NativeDynamicLinking.h
//  NativePath
//
//  Created by Giovanni Petrantoni on 03/17/16.
//  Copyright © 2016 Giovanni Petrantoni. All rights reserved.
//

#ifndef NativeDynamicLinking_h
#define NativeDynamicLinking_h

#ifdef __cplusplus
extern "C" {
#endif

extern void* LoadDynamicLibrary(const char* libraryPath);
extern void FreeDynamicLibrary(void* handle);
extern void* GetSymbolAddress(void* handle, const char* symbolName);

#define NP_IMPORT(__xx_return_type, _xx_func_name, ...)		typedef __xx_return_type (*_xx_func_name ## _ptr)(__VA_ARGS__); \
															_xx_func_name ## _ptr _xx_func_name ## _func

#define NP_LOAD(_xx_library, _xx_func_name) _xx_func_name ## _func = (_xx_func_name ## _ptr)GetSymbolAddress(_xx_library, "_xx_func_name")

#define NP_CHECK(_xx_func_name) _xx_func_name ## _func != NULL

#define NP_CALL(_xx_func_name, ...) _xx_func_name_func(__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif /* NativeDynamicLinking_h */