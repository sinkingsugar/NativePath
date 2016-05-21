#ifndef ctype_h
#define ctype_h

#include "../NativePath.h"

#ifdef __cplusplus
extern "C" {
#endif

inline int isdigit(int c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

#ifdef __cplusplus
}
#endif

#endif