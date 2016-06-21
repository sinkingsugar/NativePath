#!/bin/sh

mkdir -p build/Linux/x86
mkdir -p build/Linux/x86_64

sources="source/NativeMath.c source/NativeMemory.c source/lol_trig.cpp source/NativeTime.cpp source/NativeDynamicLinking.c source/stdio.c source/stdlib.c source/NEONvsSSE.c"

if [ "$CC" = "" ]; then
    CC=clang-3.6
fi

CFLAGS="-mssse3 -Wall -Wno-unused-const-variable -Wno-unused-function -Isource -Wno-unknown-attributes"

#Linux 64
$CC -fPIC -m64 $CFLAGS -c $sources
$CC -shared -m64 -Wl,-soname,libNativePath.so -o libNativePath.so *.o
ar rcs libNativePath.a *.o
mv libNativePath.so build/Linux/x86_64/
mv libNativePath.a build/Linux/x86_64/
rm *.o

#Linux 32
$CC -m32 $CFLAGS -c $sources
$CC -shared -m32 -Wl,-soname,libNativePath.so -o libNativePath.so *.o
ar rcs libNativePath.a *.o
mv libNativePath.so build/Linux/x86/
mv libNativePath.a build/Linux/x86/
rm *.o
