#include "tokeniser.h"
#include <string.h>
#include <stdbool.h>



int tokenise (char line[], char *token[], char delimiters[], bool keepDelimiters){
      char *tk;
      int i=0;
	  
	if(keepDelimiters==false){
      tk = strtok(line, delimiters);
      token[i] = tk;

      while (tk != NULL) {

          ++i;
          if (i>=MAX_NUM_TOKENS) {
              i = -1;
              break;
          }

          tk = strtok(NULL, tokenSeparators);
          token[i] = tk;
      }
      return i;
	}//end of If
	else if (keepDelimiters==true)
	{
		
		
	}//end of if


	
return 0;	
}
