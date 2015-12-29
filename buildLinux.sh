mkdir -p build/Linux/x86
mkdir -p build/Linux/x86_64

#Linux 64
gcc -c NativePath/NativeMath.c NativePath/NativeMemory.c NativePath/lol_trig.cpp NativePath/NativeTime.cpp -fPIC -m64
gcc -shared -Wl,-soname,libNativePath.so -o libNativePath.so *.o
mv libNativePath.so build/Linux/x86_64/
rm *.o

#Linux 32
#gcc -c NativePath/NativeMath.c NativePath/NativeMemory.c NativePath/lol_trig.cpp NativePath/NativeTime.cpp -fPIC -m32
#gcc -shared -Wl,-soname,libNativePath.so -o libNativePath.so *.o
#mv libNativePath.so build/Linux/x86/
#rm *.o

