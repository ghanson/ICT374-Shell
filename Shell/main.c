#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "directorywalk.h"
#include "fork.h"
#include "interpreter.h"
#include "tokeniser.h"


const unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}


int main(int argc, char * argv[])
{
    strncpy(g_prompt, "@", sizeof(g_prompt)); //should use environment variable
    strncpy(g_path, "PATH=/home/", sizeof(g_path)); //should use environment variable
    strncpy(g_pwd, "/home/", sizeof(g_pwd)); //should use environment variable

    bool exit = false;
    char commandLine[BUFSIZE];
    char delimiters[2] = "\n ";
    char * tokens[MAX_NUM_TOKENS];
    int ntok = 0;

    /*char cd[] = "cd";
    char pwd2[] = "pwd";
    char car[] = "\n";
    char g_prompt[] = "prompt";
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
        printf("%s: ", g_prompt);
        fgets(commandLine, BUFSIZE, stdin);
        tokeniser(tokens, commandLine, delimiters, false);

        for(int i = 0; i < strlen(*tokens); i++)
        {
            switch(hash(tokens[i]))
            {
                case CR:
                    break;
                case PROMPT:
                    strncpy(g_prompt, tokens[i+1], sizeof(g_prompt));
                    break;
                case PWD:
                    printf("%s", g_pwd);
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
                    interpreter(tokens, ntok);
            }
        }
    }

    return 0;
}
