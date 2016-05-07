#include <stdio.h>

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