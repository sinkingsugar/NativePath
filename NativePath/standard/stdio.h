#ifndef stdio_h
#define stdio_h

#include <NativePath.h>
#include <stdarg.h>

//TODO more stdio stuff

typedef void FILE;

#define stderr npGetStderr()
#define stdin npGetStdin()
#define stdout npGetStdout()
#define fflush npFflush

extern FILE* npGetStderr();
extern FILE* npGetStdin();
extern FILE* npGetStdout();
extern int npFflush(FILE* file);

inline int sprintf(char* buffer, const char* format, ...)
{
	va_list argList;
	va_start(argList, format);
	int len = vsprintf(buffer, format, argList);
	va_end(argList);
    return len;
}

#endif