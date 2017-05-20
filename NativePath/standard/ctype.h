#ifndef ctype_h
#define ctype_h

#include "../NativePath.h"

#ifdef __cplusplus
extern "C" {
#endif

#define _tolower(__c) ((unsigned char)(__c) - 'A' + 'a')
#define _toupper(__c) ((unsigned char)(__c) - 'a' + 'A')

#undef isdigit
inline int isdigit(int c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

extern int isalnum(int c);
extern int isalpha(int c);
extern int isblank(int c);  // C99
extern int iscntrl(int c);
extern int isdigit(int c);
extern int isgraph(int c);
extern int islower(int c);
extern int isprint(int c);
extern int ispunct(int c);
extern int isspace(int c);
extern int isupper(int c);
extern int isxdigit(int c);
extern int tolower(int c);
extern int toupper(int c);

#define isascii(__c)	((unsigned)(__c)<=0177)
#define toascii(__c)	((__c)&0177)

#ifdef __cplusplus
}
#endif

#endif