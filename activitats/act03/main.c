#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *command = malloc(100);

    while(memcmp(command, "exit", 4) != 0) {
        printf("%sossh%s> %s", KGRN ,KRED, KNRM);

        fgets(command, 100, stdin);
        
        parseLine(command);
        
    }

    return 0;
}