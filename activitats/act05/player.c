#include "utils.h"

int main(int argc, char *argv[]) {
    //code

    /*open pipe to communicate through stdout
    int fd[2];
    pipe(fd);

    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);*/

    for(int i = 0; i < 10; i++) {
        int key = generatePassword();
        printf("[Child: %d] Password: %04d\n", getpid(), key);
        //write(fd[1], key, PASS_LENGTH);
        //sleep 500ms
        usleep(100 * 1000);

    }

    return 0;
}