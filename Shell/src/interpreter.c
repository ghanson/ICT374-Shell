#include "interpreter.h"

void interpreter(char * tokens[], int ntok)
{
    int ncom = 0;
    Command commands[MAX_NUM_COMMANDS];
    char * com = "";
    char * lastsep = "";

    //ncom = seperateCommands(tokens, commands);

    for(int i = 0; i < ncom; i++)
    {
        if(strcmp(commands[i].sep, pipeSep))
        {
            pipe(tokens, commands, i, lastsep);
            strncpy(lastsep, pipeSep, sizeof(lastsep));
        }
        else if(strcmp(commands[i].sep, seqSep))
        {
            sequential(tokens, commands, i, lastsep);
            strncpy(lastsep, seqSep, sizeof(lastsep));
        }
        else if(strcmp(commands[i].sep, conSep))
        {
            background(tokens, commands, i, lastsep);
            strncpy(lastsep, conSep, sizeof(lastsep));
        }
    }
}

void wildcard(char * command)
{

}

void background(char * tokens[], Command commands[], int i, char * lastsep)
{

}

void sequential(char * tokens[], Command commands[], int i, char * lastsep)
{
    char * myargv[MAX_ARGS];
    int k = 1;
    char * mypath = "";

    strcat(mypath, g_path);
    strcat(mypath, ":");
    strcat(mypath, g_pwd);

    char * envargs[] = {mypath, (char*)0};

    if(strcmp(lastsep, pipeSep))

    if(tokens[i][0] == '.')
    {
        memmove(tokens[i], tokens[i]+2, strlen(tokens[i]));
    }

    //myargv[0] = strcat(path, tokens[i]);
    strcpy(myargv[0], tokens[i]);

    for(int j = commands[i].first+1; j <= commands[i].last; j++)
    {
        myargv[k] = tokens[j];
        k++;
    }

    myargv[k] = NULL;

    execvp(myargv[0], (char **)myargv);
}

void pipe(char * tokens[], Command commands[], int i, char * lastsep)
{

}

int execProg(const char **argv)
{
    pid_t   my_pid;

    if (0 == (my_pid = shellFork())) {
            if (-1 == execve(argv[0], (char **)argv , NULL)) {
                    perror("child process execve failed [%m]");
                    return -1;
            }
    }

    //if()

    return 0;
}
