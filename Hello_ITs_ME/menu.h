/**
* @file menu.h
* @brief menu libs
* @author Dynamic
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
TTF_Font *font;
Input input;
Hero player;
Hero monster;
Map map;
Gameobject star;

void drawString(char *text, int x, int y, TTF_Font *font);
void changeLevel(void);
void initializePlayer(void);
void draw_String(char *text, int x, int y, TTF_Font *font);
void save(Hero player, Gestion jeu, Map map ,char nomFich[]);
void load(Hero *player, Gestion *jeu, Map *map ,char nomFich[]);
void Sound(int type);
void initializeMonster();
void changeAnimation(Hero *entity, char *name);
SDL_Surface *loadImage(char *name);


