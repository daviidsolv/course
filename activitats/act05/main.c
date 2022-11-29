#include "utils.h"

int main(int argc, char *argv[]) {
    //code

    int players = 0;

    printf("How many players? ");
    
    if (scanf("%d", &players) >0) printf("Creating %d players...\n", players);
    else printf("You did not enter any number.\n");

    char temp[PASS_LENGTH];
    generatePassword(temp);

    printf("Password: %s\n", temp);

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

    waitpid(childs[players-1], NULL, 0);

    return 0;
}