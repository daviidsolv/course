#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    
    if(argc != 2) return -1;

    int time = atoi(argv[1]);

    while(time > 0) {
        printf("\033[A\33[2KT\rTime left: %d\n", time);
        sleep(1);
        time--;
    }

    printf("\033[A\33[2KT\rTime left: %d\n", time);

    kill(getppid(), SIGUSR1);
    exit(time);
}