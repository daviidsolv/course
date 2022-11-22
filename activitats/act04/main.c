#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd[2], fd2[2];

    char *p1[] = {"grep", "crafo", NULL};
    char *p2[] = {"cat", "/etc/passwd", NULL};
    char *p3[] = {"whoami", NULL};

    if (pipe(fd)<0){
        perror("Error de creació del pipe fd[]");
        return EXIT_FAILURE;
        /* NOTREACHED */
    }

    if (pipe(fd2)<0){
        perror("Error de creació del pipe fd2[]");
        return EXIT_FAILURE;
        /* NOTREACHED */
    }

    pid_t pid1, pid2, pid3;

    switch (pid3 = fork()){
        case -1:
            perror("Error fork() - pid3");
            return EXIT_FAILURE;
        case 0:
            // Fill -> whoami -> imprimeix a stdout
            // Tanquem stdout i redireccionem stdout a l'escriptura fd[1] de la pipe
            dup2(fd2[1],STDOUT_FILENO);
            close(fd2[1]);
            close(fd2[0]);
            execvp(p3[0], p3);
            return EXIT_FAILURE;
        default:
            //save whoami output to variable
            waitpid(pid3,0,0);
            read(fd2[0], p1[1], 20);
            close(fd2[0]);
            close(fd2[1]);
    }

    switch (pid2 = fork()){
        case -1:
            perror("Error fork() - pid2");
            return EXIT_FAILURE;
        case 0:
            // Fill -> grep david -> llegeix stdin i imprimeix a stdout
            // Tanquem stdin per llegir i redireccionem stdin per llegir de la pipe fd[0]
            dup2(fd[0],STDIN_FILENO);
            close(fd[1]);
            close(fd[0]);
            execvp(p1[0], p1);
            return EXIT_FAILURE;
    }

    switch (pid1 = fork()){
        case -1:
            perror("Error fork() - pid1");
            return EXIT_FAILURE;
        case 0:
            // Fill -> cat /etc/passwd -> imprimeix a stdout
            // Tanquem stdout i redireccionem stdout a l'escriptura fd[1] de la pipe
            dup2(fd[1],STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            execvp(p2[0], p2);
            return EXIT_FAILURE;
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(pid2,0,0);
    waitpid(pid1,0,0);

    return EXIT_SUCCESS;
}