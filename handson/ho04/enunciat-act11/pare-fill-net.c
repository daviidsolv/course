#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int status;
pid_t childPid;

int main() {
    pid_t pid;
    printf("Executant pare amb PID: %d\n", getpid());
    if ((pid = fork()) < 0) {
        err(EXIT_FAILURE, "fork error");
    } else if (pid == 0) {
        printf("Executant fill amd PID: %d\n", getpid());
        if ((childPid = fork()) < 0) {
            err(EXIT_FAILURE, "fork error");
        } else if (childPid == 0) {
            printf("Executant net amd PID: %d\n", getpid());
            printf("Acabant net amd PID: %d\n", getpid());
            exit(0);
        } else {
            childPid = wait(&status);
            printf("Acabant fill amd PID: %d\n", getpid());
        }
        exit(0);
    } else {
        pid = wait(&status);
        printf("Acabant pare amb PID: %d\n", getpid());
    }


}