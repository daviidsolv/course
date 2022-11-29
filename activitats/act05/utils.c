#include "utils.h"

void generatePassword(char *str) {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    unsigned int seed = (unsigned) getpid() * (unsigned) timeinfo->tm_sec;
    srand(seed);
    for (int i = 0; i < PASS_LENGTH; i++) {
        char c = (char) (rand() % 58 + 'A');
        if(c > 'Z' && c < 'a') {
            c = (char) (c+6);
        }
        str[i] = c;
    }
}