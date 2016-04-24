#ifndef setjmp_h
#define setjmp_h

#include <NativePath.h>

//we oversize our jmp_buf for safety
typedef void* jmp_buf[64];

#endif