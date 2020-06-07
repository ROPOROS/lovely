/**
* @file save.c
* @brief save libs
* @author Raed
* @version 1.0
* @date 07/06/2020

*/
#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>
#include <time.h>

#include "save.h"

void save(Hero player, Gestion jeu, Map map ,char nomFich[])
{
    FILE* f=fopen(nomFich,"w");
    fprintf(f, "%d\n", player.x);
    fprintf(f, "%d\n", jeu.vies);
    fprintf(f, "%d\n", jeu.etoiles);
    fprintf(f, "%d\n", jeu.enigmetest);
    fprintf(f, "%d\n", jeu.startest);
    fprintf(f, "%d\n", jeu.monstertest);
    fprintf(f, "%d\n", player.perso);
    /*fprintf(f, "%d\n", jeu.count);
    fprintf(f, "%d\n", map.dest.x);*/

    fclose(f);

}

void load(Hero *player, Gestion *jeu, Map *map ,char nomFich[])
{
    FILE* f=fopen(nomFich,"r");
    fscanf(f, "%d\n", &player->x);
    fscanf(f, "%d\n", &jeu->vies);
    fscanf(f, "%d\n", &jeu->etoiles);
    fscanf(f, "%d\n", &jeu->enigmetest);
    fscanf(f, "%d\n", &jeu->startest);
    fscanf(f, "%d\n", &jeu->monstertest);
    fscanf(f, "%d\n", &player->perso);
    /*fscanf(f, "%d\n", &jeu->count);
    fscanf(f, "%d\n", &map->dest.x);*/
    fclose(f);

}
