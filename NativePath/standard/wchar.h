#ifndef wchar_h
#define wchar_h

#include "../NativePath.h"
#include "stddef.h"
#include "stdio.h"
#include "time.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef WEOF
#define WEOF npEOF

typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} mbstate_t;

extern int fwprintf(FILE* restrict stream, const wchar_t* restrict format, ...);
extern int fwscanf(FILE* restrict stream, const wchar_t* restrict format, ...);
extern int swprintf(wchar_t* restrict s, size_t n, const wchar_t* restrict format, ...);
extern int swscanf(const wchar_t* restrict s, const wchar_t* restrict format, ...);
extern int vfwprintf(FILE* restrict stream, const wchar_t* restrict format, va_list arg);
extern int vfwscanf(FILE* restrict stream, const wchar_t* restrict format, va_list arg);  // C99
extern int vswprintf(wchar_t* restrict s, size_t n, const wchar_t* restrict format, va_list arg);
extern int vswscanf(const wchar_t* restrict s, const wchar_t* restrict format, va_list arg);  // C99
extern int vwprintf(const wchar_t* restrict format, va_list arg);
extern int vwscanf(const wchar_t* restrict format, va_list arg);  // C99
extern int wprintf(const wchar_t* restrict format, ...);
extern int wscanf(const wchar_t* restrict format, ...);
extern wint_t fgetwc(FILE* stream);
extern wchar_t* fgetws(wchar_t* restrict s, int n, FILE* restrict stream);
extern wint_t fputwc(wchar_t c, FILE* stream);
extern int fputws(const wchar_t* restrict s, FILE* restrict stream);
extern int fwide(FILE* stream, int mode);
extern wint_t getwc(FILE* stream);
extern wint_t getwchar();
extern wint_t putwc(wchar_t c, FILE* stream);
extern wint_t putwchar(wchar_t c);
extern wint_t ungetwc(wint_t c, FILE* stream);
extern double wcstod(const wchar_t* restrict nptr, wchar_t** restrict endptr);
extern float wcstof(const wchar_t* restrict nptr, wchar_t** restrict endptr);         // C99
extern long double wcstold(const wchar_t* restrict nptr, wchar_t** restrict endptr);  // C99
extern long wcstol(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base);
extern long long wcstoll(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base);  // C99
extern unsigned long wcstoul(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base);
extern unsigned long long wcstoull(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base);  // C99
extern wchar_t* wcscpy(wchar_t* restrict s1, const wchar_t* restrict s2);
extern wchar_t* wcsncpy(wchar_t* restrict s1, const wchar_t* restrict s2, size_t n);
extern wchar_t* wcscat(wchar_t* restrict s1, const wchar_t* restrict s2);
extern wchar_t* wcsncat(wchar_t* restrict s1, const wchar_t* restrict s2, size_t n);
extern int wcscmp(const wchar_t* s1, const wchar_t* s2);
extern int wcscoll(const wchar_t* s1, const wchar_t* s2);
extern int wcsncmp(const wchar_t* s1, const wchar_t* s2, size_t n);
extern size_t wcsxfrm(wchar_t* restrict s1, const wchar_t* restrict s2, size_t n);
extern const wchar_t* wcschr(const wchar_t* s, wchar_t c);
extern size_t wcscspn(const wchar_t* s1, const wchar_t* s2);
extern size_t wcslen(const wchar_t* s);
extern const wchar_t* wcspbrk(const wchar_t* s1, const wchar_t* s2);
extern const wchar_t* wcsrchr(const wchar_t* s, wchar_t c);
extern size_t wcsspn(const wchar_t* s1, const wchar_t* s2);
extern const wchar_t* wcsstr(const wchar_t* s1, const wchar_t* s2);
extern wchar_t* wcstok(wchar_t* restrict s1, const wchar_t* restrict s2, wchar_t** restrict ptr);
extern const wchar_t* wmemchr(const wchar_t* s, wchar_t c, size_t n);
extern int wmemcmp(wchar_t* restrict s1, const wchar_t* restrict s2, size_t n);
extern wchar_t* wmemcpy(wchar_t* restrict s1, const wchar_t* restrict s2, size_t n);
extern wchar_t* wmemmove(wchar_t* s1, const wchar_t* s2, size_t n);
extern wchar_t* wmemset(wchar_t* s, wchar_t c, size_t n);
extern size_t wcsftime(wchar_t* restrict s, size_t maxsize, const wchar_t* restrict format, const tm* restrict timeptr);
extern wint_t btowc(int c);
extern int wctob(wint_t c);
extern int mbsinit(const mbstate_t* ps);
extern size_t mbrlen(const char* restrict s, size_t n, mbstate_t* restrict ps);
extern size_t mbrtowc(wchar_t* restrict pwc, const char* restrict s, size_t n, mbstate_t* restrict ps);
extern size_t wcrtomb(char* restrict s, wchar_t wc, mbstate_t* restrict ps);
extern size_t mbsrtowcs(wchar_t* restrict dst, const char** restrict src, size_t len, mbstate_t* restrict ps);
extern size_t wcsrtombs(char* restrict dst, const wchar_t** restrict src, size_t len, mbstate_t* restrict ps);
extern size_t	wcsnrtombs(char * , const wchar_t ** , size_t, size_t, mbstate_t *);
extern size_t	mbsnrtowcs(wchar_t * , const char ** , size_t, size_t, mbstate_t *);

#ifdef __cplusplus
}
#endif

#endif