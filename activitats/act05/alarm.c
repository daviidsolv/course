#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    
    if(argc != 2) return -1;

    int time = atoi(argv[1]);

    while(time > 0) {
        printf("Time left: %d\n", time);
        sleep(1);
        time--;
    }

    printf("[ALARM] Time's up!\n");

    kill(getppid(), SIGUSR1);

    return 0;
}