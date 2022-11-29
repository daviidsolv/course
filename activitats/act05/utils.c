#include "utils.h"

int generatePassword(void) {
    struct timeval t;
    gettimeofday(&t, NULL);

    unsigned int seed = (unsigned) getpid() * (unsigned) t.tv_usec;
    srand(seed);
    
    return rand() % 10000;
}