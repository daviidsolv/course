#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int parseCommand(char *command){
    pid_t pid = fork();
    int status;
    if (pid == 0) {
        execlp(command, command, (char *)NULL);
        exit(0);
    }
    else {
        wait(&status);
        return status;
    }
}

int parseLine(char *line){
    int commands = 0;

    char *command = strtok(line, ";");
    while (command != NULL) {
        commands++;

        printf("Parsing command: %s with len: %ld\n", command, strlen(command));

        parseCommand(command);

        command = strtok(NULL, ";\0");
    }

    printf("Number of commands: %d \n", commands);
    
    return 0;
}