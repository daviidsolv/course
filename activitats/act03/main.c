#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"
#include "other.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFERSIZE 100

int main(int argc, char *argv[]){
    
    //@Jordi: Millor amb el sizeof 
    char *command = malloc(BUFFERSIZE*sizeof(char));

    //@Jordi: A la línia 26 compares el contingut, per tant, ha de tenir algun contingut la primera vegada
    // Això es tradueix en: Conditional jump or move depends on uninitialised value(s)
    strcpy(command,"\0");

    int debugMode = 0;

    if (argc == 2 && strcmp(argv[1], "DEBUG") == 0) {
        debugMode = 1;
    }

    //@Jordi: Problema si introdueixes una comanda com ls;exit el programa no acabarà
    while(memcmp(command, "exit", 4) != 0) {

        //@Jordi: :) Colorful
        printf("%sossh%s> %s", KGRN ,KRED, KNRM);

        // Intenta sempre revisar que la funció retorna l'esperat.
        if (fgets(command, BUFFERSIZE, stdin) != NULL){
            parseLine(command, debugMode);
        };
        
        
    }

    free(command);

    return 0;
}
