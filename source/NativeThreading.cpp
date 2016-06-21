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
//  NativeThreading.cpp
//  NativePath
//
//  Created by Giovanni Petrantoni on 06/20/16.
//  Copyright © 2016 Giovanni Petrantoni. All rights reserved.
//

#include <thread>
#include <chrono>

namespace NativePath
{
    typedef void (*ThreadDelegate)(void);

    class Thread
    {
    public:
        Thread(ThreadDelegate func) : mThread(func)
        {
        }

        void Join()
        {
            mThread.join();
        }

        static void Sleep(int milliseconds)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
        }

        static void Yield()
        {
            std::this_thread::yield();
        }

    private:
        std::thread mThread;

    };

    extern "C"
    {
        Thread* npThreadStart(ThreadDelegate func)
        {
            return new Thread(func);
        }

        void npThreadJoin(Thread* thread)
        {
            thread->Join();
        }

        void npThreadSleep(int milliseconds)
        {
            Thread::Sleep(milliseconds);
        }

        void npThreadYield()
        {
            Thread::Yield();
        }
    }

}