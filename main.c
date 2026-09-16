#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char buff[100]; 
    char **argv; 
    char *token;

    int argc; 

    printf("%s","$ ");
        fgets(buff, sizeof(buff), stdin);

        // Get first token
        token = strtok(buff, " \n");

        argc = 0;

        argv = (char **)malloc(argc * sizeof(char *));
        argv[argc] = token;

        // Count first token
        argc++;

        // i love cats inside my house
        while((token = strtok(NULL, " \n")) != NULL) {
            // Adjust memory size for incoming token
            argv = realloc(argv, (argc + 1) * sizeof(char *)); 
            
            argv[argc] = token;      

            argc++;
        }

        // Null character for UNIX system calls
        argv[argc] = "\0";
        
    return 0;
}