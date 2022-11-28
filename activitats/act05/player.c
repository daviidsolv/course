#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    //code
    printf("Child %d started!\n", getpid());

    return 0;
}