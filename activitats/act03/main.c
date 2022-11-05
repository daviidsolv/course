#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parsing.h"

int main(int argc, char *argv[]){
    char *command = malloc(100);

    while(memcmp(command, "exit", 4) != 0) {
        printf("%sossh%s> %s", KGRN ,KRED, KNRM);

        fgets(command, 100, stdin);
        char *cmd = malloc(strlen(command)-1);
        strncpy(cmd, command, strlen(command) - 1);

        pid_t pid = fork();
        if (pid == 0) {
            execlp(cmd, cmd, (char *)NULL);
            exit(0);
        }
        else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}