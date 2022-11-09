#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int parseCommand(char *command){
    if(strncmp(command, "cd", 2) == 0) {
        printf("cd command");
        //TODO: implement cd command BY TOKENS
        chdir("..");
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

int parseLine(char *line){
    char *delim = ";\n\0";
    char *rest = line;

    char *command;

    while ((command = strtok_r(rest, delim, &rest))) {
        char *temp2 = malloc(strlen(command));
        strcpy(temp2, command);

        parseCommand(temp2);

        free(temp2);

    }
    
    return 0;
}

void printHelp() {
    printf("%s", 
    "#### GTIDIC - UDL - OSSH #################################\n"
    "#                                                        #\n"
    "# Type program names and arguments, and hit enter.       #\n"
    "# Use the man command for information on other programs. #\n"
    "#                                                        #\n"
    "##########################################################\n"
    );
}