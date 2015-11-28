/*
Copyright (c) 2015 Giovanni Petrantoni

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
//  NativeMemory.c
//  NativePath
//
//  Created by Giovanni Petrantoni on 11/18/15.
//  Copyright © 2015 Giovanni Petrantoni. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

void* npMalloc(unsigned int size)
{
    return malloc(size);
}

void npFree(void* block)
{
    free(block);
}

void* npMemmove(void* dest, const void* src, unsigned int count)
{
	return memmove(dest, src, count);
}

void* npMemcpy(void *dest, const void *src, unsigned int count)
{
	return memcpy(dest, src, count);
}

void* npMemset(void *dest, int ch, unsigned int count)
{
	return memset(dest, ch, count);
}
