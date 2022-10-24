#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int status;
pid_t childPid;

int main() {
    pid_t pid;
    char *buffer = malloc(100);
    sprintf(buffer, "Executant pare amb PID: %d\n", getpid());
    write(1, buffer, strlen(buffer));
    free(buffer);
    if ((pid = fork()) < 0) {
        err(EXIT_FAILURE, "fork error");
    } else if (pid == 0) {
        buffer = malloc(100);
        sprintf(buffer, "Executant fill amb PID: %d\n", getpid());
        write(1, buffer, strlen(buffer));
        free(buffer);
        if ((childPid = fork()) < 0) {
            err(EXIT_FAILURE, "fork error");
        } else if (childPid == 0) {
            buffer = malloc(100);
            sprintf(buffer, "Executant net amb PID: %d\n", getpid());
            write(1, buffer, strlen(buffer));
            free(buffer);

            buffer = malloc(100);
            sprintf(buffer, "Acabant net amb PID: %d\n", getpid());
            write(1, buffer, strlen(buffer));
            free(buffer);
            exit(0);
        } else {
            childPid = wait(&status);
            buffer = malloc(100);
            sprintf(buffer, "Acabant fill amb PID: %d\n", getpid());
            write(1, buffer, strlen(buffer));
            free(buffer);
        }
        exit(0);
    } else {
        pid = wait(&status);
        buffer = malloc(100);
        sprintf(buffer, "Acabant pare amb PID: %d\n", getpid());
        write(1, buffer, strlen(buffer));
        free(buffer);    
    }
}