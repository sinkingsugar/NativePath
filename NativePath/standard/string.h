#ifndef string_h
#define string_h

#include "../NativePath.h"

// extern void* memcpy(void*  s1, const void*  s2, size_t n);
// extern void* memmove(void* s1, const void* s2, size_t n);
// extern char* strcpy (char*  s1, const char*  s2);
// extern char* strncpy(char*  s1, const char*  s2, size_t n);
// extern char* strcat (char*  s1, const char*  s2);
// extern char* strncat(char*  s1, const char*  s2, size_t n);
// extern int memcmp(const void* s1, const void* s2, size_t n);
// extern int strcmp (const char* s1, const char* s2);
// extern int strncmp(const char* s1, const char* s2, size_t n);
extern int strcoll(const char* s1, const char* s2);
extern size_t strxfrm(char*  s1, const char*  s2, size_t n);
// extern const void* memchr(const void* s, int c, size_t n);
// extern void* memchr(      void* s, int c, size_t n);
// extern const char* strchr(const char* s, int c);
// extern char* strchr(      char* s, int c);
// extern size_t strcspn(const char* s1, const char* s2);
// extern const char* strpbrk(const char* s1, const char* s2);
// extern char* strpbrk(      char* s1, const char* s2);
// extern const char* strrchr(const char* s, int c);
// extern char* strrchr(      char* s, int c);
// extern size_t strspn(const char* s1, const char* s2);
// extern const char* strstr(const char* s1, const char* s2);
// extern char* strstr(      char* s1, const char* s2);
extern char* strtok(char*  s1, const char*  s2);
// extern void* memset(void* s, int c, size_t n);
extern char* strerror(int errnum);
// extern size_t strlen(const char* s);

#endif