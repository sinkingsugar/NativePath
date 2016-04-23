#include <NativePath.h>

typedef void FILE;

#define stderr npGetStderr()
#define stdin npGetStdin()
#define stdout npGetStdout()

extern FILE* npGetStderr();
extern FILE* npGetStdin();
extern FILE* npGetStdout();
extern int fflush(FILE* file);