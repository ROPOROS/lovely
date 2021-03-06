/**
* @file player.h
* @brief player libs
* @author Yasmine+Cyrine
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
Hero player;
Hero monster;
Input input;
Map map;
Gameobject objet;
Gameobject star;

SDL_Surface *loadImage(char *name);
void Sound(int type);
void changeAnimation(Hero *entity, char *name);
void initializeMonster(void);
void loadGame();
