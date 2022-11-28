#include "utils.h"

int main(int argc, char *argv[]) {
    //code

    int players = 0;

    printf("How many players? ");
    scanf("%d", &players);

    printf("Starting game with %d players!\n", players);

    pid_t *childs = (pid_t *) malloc(players * sizeof(pid_t));

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

    char temp[PASS_LENGTH];
    generatePassword(temp);

    printf("Password: %s\n", temp);

    return 0;
}