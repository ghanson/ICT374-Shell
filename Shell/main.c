#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "directorywalk.h"
#include "fork.h"
#include "interpreter.h"
#include "tokeniser.h"

#define BUFSIZE 1024

#define CR 177583
#define CD 5863276
#define PROMPT 359559495
#define PWD 193502992
#define EXIT 2090237503
#define FORK 2090263927

char pwd[BUFSIZE];
char path[BUFSIZE];
char prompt[BUFSIZE];

const unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}


int main(int argc, char * argv[])
{
    strncpy(prompt, "@", sizeof(prompt)); //should use environment variable
    strncpy(path, "/home/", sizeof(path)); //should use environment variable
    strncpy(pwd, "/home/", sizeof(path)); //should use environment variable

    bool exit = false;
    char commandLine[BUFSIZE];
    char delimiters[2] = "\n ";
    char * tokens[MAX_NUM_TOKENS];

    /*char cd[] = "cd";
    char pwd2[] = "pwd";
    char car[] = "\n";
    char prompt[] = "prompt";
    char exit[] = "exit";
    char fork[] = "fork";

    printf("%lu\n", hash(cd));
    printf("%lu\n", hash(pwd2));
    printf("%lu\n", hash(car));
    printf("%lu\n", hash(prompt));
    printf("%lu\n", hash(exit));
    printf("%lu\n", hash(fork));*/

    while(!exit)
    {
        printf("%s: ", prompt);
        fgets(commandLine, BUFSIZE, stdin);
        tokeniser(tokens, commandLine, delimiters, false);

        for(int i = 0; i < strlen(*tokens); i++)
        {
            switch(hash(tokens[i]))
            {
                case CR:
                    break;
                case PROMPT:
                    strncpy(prompt, tokens[i+1], sizeof(prompt));
                    break;
                case PWD:
                    printf("%s", pwd);
                    break;
                case CD:
                    if(tokens[i+1])
                        break;
                    else
                    {
                        directoryWalk(tokens[i+1]);
                    }
                    break;
                case EXIT:
                    exit = true;
                    break;
                case FORK:
                    shellFork();
                    break;
                default:
                    interpreter(commandLine);
            }
        }
    }

    return 0;
}
