#include "utils.h"

int main(int argc, char *argv[]) {
    //code

    int players = 0;

    printf("How many players? ");

    if (scanf("%d", &players) >0) printf("Creating %d players...\n", players);
    else printf("You did not enter any number.\n");

    int unlock = generatePassword();

    printf("Password: %d\n", unlock);

    printf("Starting game with %d players!\n", players);

    pid_t *childs = (pid_t *) malloc((unsigned) players * sizeof(pid_t));

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

    /*open pipe to communicate with childs
    int fd[2];
    pipe(fd);

    for(int i = 0; i < players; i++) {
        char key[PASS_LENGTH];
        read(fd[0], key, PASS_LENGTH);
        printf("Password: %s\n", key);
        if(strcmp(key, unlock) == 0) {
            printf("Player %d unlocked the door!\n", i);
            for(int j = 0; j < players; j++) {
                kill(childs[j], SIGKILL);
            }
            break;
        }
    }*/

    waitpid(childs[players-1], NULL, 0);

    return 0;
}