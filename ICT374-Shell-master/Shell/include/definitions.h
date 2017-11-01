#define MAX_ARGS 64

#define MAX_NUM_COMMANDS  1000

#define BUFSIZE 1024

// command separators
#define pipeSep  "|"                            // pipe separator "|"
#define conSep   "&"                            // concurrent execution separator "&"
#define seqSep   ";"                            // sequential execution separator ";"
#define inSep    "<"
#define outSep   ">"

//hash definitions for main switch case
#define CR 177583
#define CD 5863276
#define PROMPT 359559495
#define PWD 193502992
#define EXIT 2090237503
#define FORK 2090263927

char g_pwd[BUFSIZE];
char g_path[BUFSIZE];
char g_prompt[BUFSIZE];

struct CommandStruct {
   int first;      // index to the first token in the array "token" of the command
   int last;       // index to the first token in the array "token" of the command
   char *sep;	   // the command separator that follows the command,  must be one of "|", "&", and ";"

   // new fields
   char **argv; // an array of tokens that forms a command
   char *stdin_file; // if not NULL, points to the file name for stdin redirection
   char *stdout_file; // if not NULL, points to the file name for stdout redirection
};

typedef struct CommandStruct Command;  // command type
