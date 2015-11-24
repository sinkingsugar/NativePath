//
//  NativeMemory.c
//  NativePath
//
//  Created by Giovanni Petrantoni on 11/18/15.
//  Copyright © 2015 Giovanni Petrantoni. All rights reserved.
//

#include <stdlib.h>

void* npMalloc(unsigned int size)
{
    return malloc(size);
}

void npFree(void* block)
{
    free(block);
}
