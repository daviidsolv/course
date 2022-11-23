#include "parsing.h"
#include "other.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "log.h"

int parseCommand(char *command, int debugMode){

    if (parseErrors(command, debugMode) != 0) {
        return -1;
    }

    if(strncmp(command, "cd", 2) == 0) {
        char *token = strtok(command, " ");
        token = strtok(NULL, " ");
        chdir(token);

        return 0;
    } else if (strncmp(command, "help", 4) == 0) {
        printHelp();

        return 0;
    }

    char *path = malloc(5+strlen(command)+1 * sizeof(char));
    strcpy(path, "/bin/");

    char *args[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    int i = 0;
    
    char *token = strtok(command, " ");

    //@Jordi: Evitem que si introduïm un espai buit com a comanda ens peti el programa amb segmentation fault
    if (token != NULL){

        strcat(path, token);

        while(token != NULL){
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }

        args[i] = NULL;    

        pid_t pid = fork();
        int status;

        if (pid == 0) {
            execv(path, args);
            exit(0);
        }
        else {
            waitpid(pid, &status, WUNTRACED | WCONTINUED);
            free(path);
            return status;
        }
    }

    free(path);
    return 0;
}

int parseLine(char *line, int debugMode){
    //char *delim = ";\n\0";
    //@Jordi: No cal, estàs igualant les @, per tant, aquesta variable res no és necessària
    //char *rest = line;

    char *command = NULL;
    while ( (command = strtok_r(line, ";\n\0", &line)) != NULL ) {

        //@Jordi:Per fer servir de forma segura: Sempre has de guardar una posició extra per fer strcpy()
        // Info del manual: The  strcpy()  function copies the string pointed to by src, including the terminating null byte ('\0'), to the buffer pointed to by dest. 
        // Error actual de gestió de memòria: Invalid write of size 1
        char *temp2 = malloc( ( strlen(command)+1) * sizeof(char) );
        strcpy(temp2, command);

        if(debugMode == 1) {
            log_debug("Executing command: %s", temp2);
        }
        
        parseCommand(temp2, debugMode);
        free(temp2);
    }
    return 0;
}

int parseErrors(char *command, int debugMode) {

    for(int i = 0; i < strlen(command); i++) {
        if( command[i] == '<' || command[i] == '>' 
            || command[i] == '|' || command[i] == '&') {
            //print error through stderr
            fprintf(stderr, "%sError: '%s' contains not allowed operators: [|<>&]%s\n", KRED, command, KNRM);
            return -1;
        }
    }

    return 0;
}
