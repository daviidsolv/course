#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"
#include "other.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *command = malloc(100);

    int debugMode = 0;

    if (argc == 2 && strcmp(argv[1], "DEBUG") == 0) {
        debugMode = 1;
    }

    while(memcmp(command, "exit", 4) != 0) {
        printf("%sossh%s> %s", KGRN ,KRED, KNRM);

        fgets(command, 100, stdin);
        
        parseLine(command, debugMode);
    }

    free(command);

    return 0;
}