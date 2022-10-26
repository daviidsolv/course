#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "pokemon.h"

pid_t pid;
int st;

void run_child(void);
void run_parent(void);

int
main(int argc, char *argv[])
{
<<<<<<< HEAD
    pid = fork();
    if (pid==-1){exit(-1);}
    else if (pid==0){  // Fill
        run_child();
    }
    else{ // Pare
        run_parent();
    }
}

void run_parent(){
    init_pokedex();
    if (waitpid(pid, &st, 0) >= 0){
            if ( WIFEXITED(st))
                show_pokemon(WEXITSTATUS(st));
    };
}

void run_child(){
    execl("./random","random", NULL);
    exit(-1);
=======

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

>>>>>>> 9650491 (main_done)
}