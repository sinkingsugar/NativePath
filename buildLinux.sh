#!/bin/sh

mkdir -p build/Linux/x86
mkdir -p build/Linux/x86_64

sources="NativePath/NativeMath.c NativePath/NativeMemory.c NativePath/lol_trig.cpp NativePath/NativeTime.cpp NativePath/NativeDynamicLinking.c"

if [ "$CC" = "" ]; then
    CC=clang-3.6
fi

CFLAGS="-Wall -Wno-unused-const-variable -Wno-unused-function"

#Linux 64
$CC -fPIC -m64 $CFLAGS -c $sources
ar rcs libNativePath.a *.o
mv libNativePath.a build/Linux/x86_64/
rm *.o

#Linux 32
$CC -m32 $CFLAGS -c $sources
ar rcs libNativePath.a *.o
mv libNativePath.a build/Linux/x86/
rm *.o
