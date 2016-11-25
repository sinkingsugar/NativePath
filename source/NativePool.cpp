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
//  NativePool.cpp
//  NativePath
//
//  Created by Giovanni Petrantoni on 11/25/16.
//  Copyright © 2016 Giovanni Petrantoni. All rights reserved.
//

#include <boost/pool/pool.hpp>

typedef void NpMemoryPool;

#ifdef __cplusplus
extern "C" {
#endif

NpMemoryPool* npMemoryPoolCreate(int chunkSize)
{
	boost::pool<>* p = new boost::pool<>(chunkSize);
	return (NpMemoryPool*)p;
}

void npMemoryPoolDestroy(NpMemoryPool* pool)
{
	boost::pool<>* p = (boost::pool<>*)pool;
	delete p;
}

void* npMemoryPoolAlloc(NpMemoryPool* pool, int numberOfChunks)
{
	boost::pool<>* p = (boost::pool<>*)pool;
	return p->ordered_malloc(numberOfChunks);
}

void npMemoryPoolFree(NpMemoryPool* pool, void* ptr, int numberOfChunks)
{
	boost::pool<>* p = (boost::pool<>*)pool;
	p->ordered_free(ptr, numberOfChunks);
}

#ifdef __cplusplus
}
#endif