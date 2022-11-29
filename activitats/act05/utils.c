#include "utils.h"

void generatePassword(char *code) {
    struct timeval t;
    gettimeofday(&t, NULL);

    unsigned int seed = (unsigned) getpid() * (unsigned) t.tv_usec;
    srand(seed);

    for(int i = 0; i < PASS_LENGTH; i++) {
        code[i] = (char)((rand() % 26) + 'A');
    }
}