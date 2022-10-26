#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "pokemon.h"

int
main(int argc, char *argv[])
{

    int status;
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    // Executa fill
    if (pid == 0) {
        execl("./random", "random", NULL);
        perror("execl");
        exit(1);
    }

    // Executa pare
    init_pokedex();
    if (waitpid(pid, &status, 0) >= 0) {
        if (WIFEXITED(status))
            show_pokemon(WEXITSTATUS(status));
    }

}