#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUM_TOKENS  100

int tokenise (char line[], char *token[], char delimiters[], bool keepDelimiters);
