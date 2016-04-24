#ifndef assert_h
#define assert_h

#include <NativePath.h>
#include <stdbool.h>

inline void assert(bool condition)
{
    if(!condition)
    {
        printf("Assert condition failed");
        debugtrap();
        abort();
    }
}

#endif