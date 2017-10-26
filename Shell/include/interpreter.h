#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "definitions.h"

void interpreter(char * tokens[], int ntok);

void wildcard(char * command);

void background(char * tokens[], Command commands[], int i, char * lastsep);

void sequential(char * tokens[], Command commands[], int i, char * lastsep);

void pipe(char * tokens[], Command commands[], int i, char * lastsep);

int execProg(const char **argv);


