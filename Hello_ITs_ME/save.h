/**
* @file save.h
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

#include "structs.h"

Gestion jeu;
Hero monster;
Map map;

void save(Hero player, Gestion jeu, Map map ,char nomFich[]);
void load(Hero *player, Gestion *jeu, Map *map ,char nomFich[]);
