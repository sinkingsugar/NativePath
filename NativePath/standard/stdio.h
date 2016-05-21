#ifndef stdio_h
#define stdio_h

#include "../NativePath.h"
#include "stdarg.h"

//TODO more stdio stuff

#ifdef __cplusplus
extern "C" {
#endif

typedef void FILE;

#define stderr npGetStderr()
#define stdin npGetStdin()
#define stdout npGetStdout()
#define fflush npFflush
#define printf npPrintf
#define sprintf npSprintf

extern FILE* npGetStderr();
extern FILE* npGetStdin();
extern FILE* npGetStdout();
extern int npFflush(FILE* file);
extern int npPrintf(const char* format, ...);
extern int npSprintf(char* buffer, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif