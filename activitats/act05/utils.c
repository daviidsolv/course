#include "utils.h"

void generatePassword(char *str) {
    unsigned int seed = (unsigned) getpid();
    srand(seed);
    for (int i = 0; i < PASS_LENGTH; i++) {
        char c = (char) (rand() % 58 + 'A');
        if(c > 'Z' && c < 'a') {
            c += 6;
        }
        str[i] = c;
    }
}