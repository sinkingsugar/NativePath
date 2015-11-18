//
//  NativeMemory.h
//  NativePath
//
//  Created by Giovanni Petrantoni on 11/18/15.
//  Copyright © 2015 Giovanni Petrantoni. All rights reserved.
//

#ifndef NativeMemory_h
#define NativeMemory_h

extern void* npMalloc(unsigned int size);
extern void npFree(void* block);

#endif /* NativeMemory_h */
