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
//  NativeTime.cpp
//  NativePath
//
//  Created by Giovanni Petrantoni on 11/28/15.
//  Copyright © 2015 Giovanni Petrantoni. All rights reserved.
//

#ifndef WIN32
#include <sys/time.h>
#else
#include <windows.h>
#endif

class Timer
{
private:
#ifdef WIN32
	LARGE_INTEGER m_depart;
#else
	timeval m_depart;
#endif

public:
	Timer()
	{
		start();
	}

	inline void start()
	{
#ifdef WIN32
		QueryPerformanceCounter(&m_depart);
#else
		gettimeofday(&m_depart, 0);
#endif
	}

	inline double seconds() const
	{
#ifdef WIN32
		LARGE_INTEGER now;
		LARGE_INTEGER freq;

		QueryPerformanceCounter(&now);
		QueryPerformanceFrequency(&freq);

		return (now.QuadPart - m_depart.QuadPart) / static_cast<double>(freq.QuadPart);
#else
		timeval now;
		gettimeofday(&now, 0);

		return now.tv_sec - m_depart.tv_sec + (now.tv_usec - m_depart.tv_usec) / 1000000.0f;
#endif
	}
};

Timer __gTimer;

#ifdef __cplusplus
extern "C"
{
	double npSeconds()
	{
		return __gTimer.seconds();
	}
}
#endif
