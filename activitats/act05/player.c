#include "utils.h"

void signalHandler(int sig);

int main(int argc, char *argv[]) {
    
    for(int i = 0; i < 10; i++) {
        int key = generatePassword();
        printf("[Child: %d] Password: %04d\n", getpid(), key);
        //write(fd[1], key, PASS_LENGTH);
        //sleep 500ms
        usleep(500 * 1000);

    }

    kill(getppid(), SIGUSR2);

    return 0;
}

void signalHandler(int sig) {
    if (sig == SIGUSR2) {
        printf("[Child %d]Time's up!\n", getpid());
        exit(0);
    }
}