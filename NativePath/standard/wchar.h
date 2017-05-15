#ifndef wchar_h
#define wchar_h

#include "../NativePath.h"

typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} mbstate_t;

#endif