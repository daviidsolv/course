#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pokemon.h"

struct pokemon pokedex[POKEMONS];

void show_pokemon(int position){
    struct pokemon pokemon = pokedex[position];
    printf("\n============================= \n");
    printf("==  id: %d \n",  pokemon.id);
    printf("==  name: %s \n",  pokemon.name);
    printf("==  attack: %d \n",  pokemon.attack);
    printf("==  defense: %d \n",  pokemon.defense);
    printf("============================= \n");
}

void init_pokedex(void){

  FILE* f = fopen("./pokedex.csv", "r");
  if(!f) {
    perror("fopen");
    exit(1);
  }
  //@TODO

  char *buffer = malloc(151);

  while(fgets(buffer, 151, f) != NULL) {
    char *token = strtok(buffer, ",");
    int id = atoi(token);

    token = strtok(NULL, ",");
    char *name = token;

    token = strtok(NULL, ",");
    char *type = token;

    token = strtok(NULL, ",");
    char *type2 = token;

    token = strtok(NULL, ",");
    int total = atoi(token);
    
    token = strtok(NULL, ",");
    int hp = atoi(token);

    token = strtok(NULL, ",");
    int attack = atoi(token);

    token = strtok(NULL, ",");
    int deffense = atoi(token);

    token = strtok(NULL, ",");
    int spAttack = atoi(token);

    token = strtok(NULL, ",");
    int spDeffense = atoi(token);

    token = strtok(NULL, ",");
    int speed = atoi(token);

    token = strtok(NULL, ",");
    int generation = atoi(token);

    token = strtok(NULL, ",");
    int legendary = atoi(token);

    struct pokemon p = {id, name, type, type2, total, hp, attack, defense, spAttack, spDeffense, speed, generation, legendary};
    pokedex[id-1] = p;
  }

  fclose(f);
}
