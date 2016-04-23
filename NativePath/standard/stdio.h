#include <NativePath.h>

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