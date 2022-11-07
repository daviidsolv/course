#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int parseCommand(char *command){
    char *path = malloc(5+strlen(command));
    char *args[] = {};
    char **prt = args;
    int i = 0;
    strcpy(path, "/bin/");

    char *token = strtok(command, " ");
    strcat(path, token);
    while(token != NULL) {
        //add token to args array
        prt[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    prt[i] = NULL;

    pid_t pid = fork();
    int status;

    if (pid == 0) {
        execv(path, args);
        exit(0);
    }
    else {
        wait(&status);
        return status;
    }
}

int parseLine(char *line){
    int commands = 0;
    char *temp = malloc(strlen(line)-1);
    strncpy(temp, line, strlen(line)-1);

    char *command = strtok(temp, ";");
    while (command != NULL) {
        commands++;

        parseCommand(command);

        command = strtok(NULL, ";\0");
    }

    free(temp);
    
    return 0;
}