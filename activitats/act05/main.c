#include "utils.h"

void signalHandler(int sig);

int players = 0;
int alarmTime = 10;

pid_t alarmPid;
pid_t *childs;

int main(int argc, char *argv[]) {
    //code
    if(signal(SIGUSR1, signalHandler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    if(signal(SIGUSR2, signalHandler) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    printf("How many players? ");

    if (scanf("%d", &players) >0) printf("Creating %d players...\n", players);
    else printf("You did not enter any number.\n");

    int unlock = generatePassword();

    printf("Password: %d\n", unlock);

    printf("Starting game with %d players!\n", players);

    switch(alarmPid = fork()) {
        case -1:
            perror("Error creating alarm process");
            exit(-1);
        case 0:
            printf("[Child: %d] Alarm process created\n", getpid());
            char *args[] = {"./alarm", "10", NULL};
            execv(args[0], args);
            perror("Error executing alarm process");
            exit(-1);
    }

    childs = (pid_t *) malloc((unsigned) players * sizeof(pid_t));

    for(int i = 0; i < players; i++) {
        switch(childs[i] = fork()) {
            case -1:
                perror("fork");
                exit(EXIT_FAILURE);
            case 0:
                printf("Child %d created!\n", i);
                char *args[] = {"./player", NULL};
                execv(args[0], args);
                exit(EXIT_SUCCESS);
            default:
                break;
        }
    }

    pause();

    return 0;
}

void signalHandler(int sig) {
    if (sig == SIGUSR1) {
        printf("[Parent] Time's up!\n");
        for(int i = 0; i < players; i++) {
            kill(childs[i], SIGKILL);
        }
        exit(0);
    } else if (sig == SIGUSR2) {
        printf("[Parent] Player %d unlocked the door!\n", getpid());
        kill(alarmPid, SIGKILL);
        for(int i = 0; i < players; i++) {
            kill(childs[i], SIGKILL);
        }
        exit(0);
    }

    exit(0);
}