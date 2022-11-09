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
    }

    char *path = malloc(5+strlen(command));
    strcpy(path, "/bin/");

    char *args[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    int i = 0;
    
    char *token = strtok(command, " ");
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
        return status;
    }
}

int parseLine(char *line, int debugMode){
    char *delim = ";\n\0";
    char *rest = line;

    char *command;

    while ((command = strtok_r(rest, delim, &rest))) {
        char *temp2 = malloc(strlen(command));
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
        if(command[i] == '<' || command[i] == '>' || command[i] == '|' || command[i] == '&') {
            //print error through stderr
            fprintf(stderr, "%sError: '%s' contains not allowed operators: [|<>&]%s\n", KRED, command, KNRM);
            return -1;
        }
    }

    return 0;
}