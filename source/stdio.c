#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdarg.h>

void* npGetStderr()
{
	return stderr;
}

void* npGetStdin()
{
	return stdin;
}

void* npGetStdout()
{	
	return stdout;
}

int npFflush(void* file)
{
	return fflush((FILE*)file);
}

int npPrintf(const char *c, ...)
{
	char buf[1024];
	va_list ap;
	va_start(ap, c);
	vsprintf(buf, c, ap);
	va_end(ap);
	return printf("%s", buf);
}

int npSprintf(char* buffer, const char* format, ...)
{
	va_list argList;
	va_start(argList, format);
	int len = vsprintf(buffer, format, argList);
	va_end(argList);
    return len;
}

int npFprintf(FILE *stream, const char *format, ...)
{
	va_list argList;
	va_start(argList, format);
	int len = fprintf(stream, format, argList);
	va_end(argList);
    return len;
}

int npVsnprintf(char * s, size_t n, const char * format, va_list arg)
{
	return vsnprintf(s, n, format, arg);
}