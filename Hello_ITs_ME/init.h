/**
* @file init.h
* @brief init libs
* @author Youssef+Cyrine
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

SDL_Surface *loadImage(char *name);
void closeFont(TTF_Font *font);
TTF_Font *loadFont(char *, int);
void loadSong( char filename[200] );
void loadSound(void);
void freeSound(void);

Gestion jeu;
Gameobject star;
Hero player;
Hero monster;
Map map;
TTF_Font *font;
Hero monster;
