#ifndef stdio_h
#define stdio_h

typedef void fpos_t;
typedef void FILE;

#include "../NativePath.h"
#include "stdarg.h"
#include "wchar.h"

#ifdef __cplusplus
extern "C" {
#endif

#undef stderr
#define stderr npGetStderr()
#undef stdin
#define stdin npGetStdin()
#undef stdout
#define stdout npGetStdout()

#define npEOF -1
#undef EOF
#define EOF npEOF

#undef fflush
#define fflush npFflush
#undef printf
#define printf npPrintf
#undef sprintf
#define sprintf npSprintf
#undef snprintf
#define snprintf npSnprintf
#undef fprintf
#define fprintf npFprintf
#undef vsnprintf
#define vsnprintf npVsnprintf

extern FILE* npGetStderr();
extern FILE* npGetStdin();
extern FILE* npGetStdout();
extern int npGetEof();

extern int npFflush(FILE* file);
extern int npPrintf(const char* format, ...);
extern int npSprintf(char* buffer, const char* format, ...);
extern int npSnprintf(char* buffer, size_t n, const char* format, ...);
extern int npFprintf(FILE *stream, const char *format, ...);
extern int npVsnprintf(char * s, size_t n, const char * format, va_list arg);

//TODO
extern int remove(const char* filename);
extern int rename(const char* old, const char* newName);
extern FILE* tmpfile(void);
extern char* tmpnam(char* s);
extern int fclose(FILE* stream);
extern FILE* fopen(const char*  filename, const char*  mode);
extern FILE* freopen(const char*  filename, const char *  mode, FILE *  stream);
extern void setbuf(FILE*  stream, char*  buf);
extern int setvbuf(FILE*  stream, char*  buf, int mode, size_t size);
extern int fscanf(FILE*  stream, const char *  format, ...);
extern int scanf(const char*  format, ...);
extern int snprintf(char*  s, size_t n, const char*  format, ...);    // C99
extern int sscanf(const char*  s, const char*  format, ...);
extern int vfprintf(FILE*  stream, const char*  format, va_list arg);
extern int vfscanf(FILE*  stream, const char*  format, va_list arg);  // C99
extern int vprintf(const char*  format, va_list arg);
extern int vscanf(const char*  format, va_list arg);                          // C99
extern int vsprintf(char*  s, const char*  format, va_list arg);
extern int vsscanf(const char*  s, const char*  format, va_list arg); // C99
extern int fgetc(FILE* stream);
extern char* fgets(char*  s, int n, FILE*  stream);
extern int fputc(int c, FILE* stream);
extern int fputs(const char*  s, FILE*  stream);
extern int getc(FILE* stream);
extern int getchar(void);
extern char* gets(char* s);  // removed in C++14
extern int putc(int c, FILE* stream);
extern int putchar(int c);
extern int puts(const char* s);
extern int ungetc(int c, FILE* stream);
extern size_t fread(void*  ptr, size_t size, size_t nmemb, FILE*  stream);
extern size_t fwrite(const void*  ptr, size_t size, size_t nmemb, FILE*  stream);
extern int fgetpos(FILE*  stream, fpos_t*  pos);
extern int fseek(FILE* stream, long offset, int whence);
extern int fsetpos(FILE*stream, const fpos_t* pos);
extern long ftell(FILE* stream);
extern void rewind(FILE* stream);
extern void clearerr(FILE* stream);
extern int feof(FILE* stream);
extern int ferror(FILE* stream);
extern void perror(const char* s);
extern int	vasprintf(char **, const char *, va_list);

#ifdef __cplusplus
}
#endif

#endif