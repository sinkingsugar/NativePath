#ifndef stdlib_h
#define stdlib_h

#include "../NativePath.h"
#include "../NativeMemory.h"

#ifdef __cplusplus
extern "C" {
#endif

//TODO more stdlib stuff

typedef struct
{
	int quot;			/* Quotient.  */
	int rem;			/* Remainder.  */
} div_t;

typedef struct
{
	long int quot;		/* Quotient.  */
	long int rem;		/* Remainder.  */
} ldiv_t;

typedef struct
{
	long long int quot;		/* Quotient.  */
	long long int rem;		/* Remainder.  */
} lldiv_t;

//TODO
extern double atof (const char* nptr);
extern int atoi (const char* nptr);
extern long atol (const char* nptr);
extern long long atoll(const char* nptr);                                        // C99
extern double strtod(const char* nptr, char** endptr);
extern float strtof  (const char* nptr, char** endptr); // C99
extern long double strtold (const char*  nptr, char**  endptr); // C99
extern long strtol  (const char*  nptr, char**  endptr, int base);
extern long long strtoll (const char*  nptr, char**  endptr, int base); // C99
extern unsigned long strtoul (const char*  nptr, char**  endptr, int base);
extern unsigned long long strtoull(const char*  nptr, char**  endptr, int base); // C99
extern void srand(unsigned int seed);
extern int atexit(void (*func)(void));
extern char* getenv(const char* name);
extern int system(const char* string);
void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
extern div_t div( int numer, int denom);
extern ldiv_t ldiv(long numer, long denom);
extern lldiv_t lldiv(long long numer, long long denom);                          // C99
extern int mblen(const char* s, size_t n);
extern int mbtowc(wchar_t*  pwc, const char*  s, size_t n);
extern int wctomb(char* s, wchar_t wchar);
extern size_t mbstowcs(wchar_t*  pwcs, const char*  s, size_t n);
extern size_t wcstombs(char*  s, const wchar_t*  pwcs, size_t n);
extern int at_quick_exit(void (*func)(void));                                     // C++11
extern void quick_exit(int status);                                              // C++11
extern void *aligned_alloc(size_t alignment, size_t size);                       // C11

#undef exit
#define exit npExit
#undef _Exit
#define _Exit npExit

extern void npExit(int code);

#undef qsort
#define qsort npQsort

extern void npQsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

#undef rand
#define rand npRand

extern int npRand();

#ifdef __cplusplus
}
#endif

#endif