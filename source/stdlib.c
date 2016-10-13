#include <stdlib.h>

void npExit(int code)
{
	exit(code);
}

void npQsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
	qsort(base, nitems, size, compar);
}
