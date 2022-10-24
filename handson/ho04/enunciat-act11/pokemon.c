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
<<<<<<< HEAD

  char *buf = malloc(POKEMONS);
  char *info;

  while (fgets(buf, POKEMONS, f) != NULL) {
    struct pokemon p;
    info = strtok(buf, ",");
    int c = 0; // index de la columna
    while(info){
      if (c==0) p.id=atoi(info);
      if (c==1) strcpy(p.name, info);
      if (c==2 || c==3)  strcpy(p.type[c-2], info);
      if (c==4)  p.total = atoi(info);
      if (c==5)  p.hp = atoi(info); 
      if (c==6)  p.attack = atoi(info);
      if (c==7) p.defense = atoi(info);
      if (c==8)    p.spAttack = atoi(info);
      if (c==9) p.spDefense = atoi(info);
      if (c==10) p.speed = atoi(info);
      if (c==11)  p.generation = atoi(info);
      if (c==12) p.legendary = atoi(info);
      c=c+1;
      info = strtok(NULL, ",");
    }
    pokedex[p.id-1]=p;
  }

  fclose(f);
  free(buf);
=======
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
    pokedex[id] = pokemon;
  }

  fclose(f);
>>>>>>> 48042f7 (completed pokemon.c)
}

