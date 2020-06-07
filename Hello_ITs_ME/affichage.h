/**
* @file affichage.h
* @brief affichage libs
* @author Youssef
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

void afficherplayer(void);
void afficherMonster(void);
void animationplayer(void);
void animationMonster(void);
void drawHud(void);
void afficher(void);
void drawString(char *text, int x, int y, TTF_Font *font);
void draw_String(char *text, int x, int y, TTF_Font *font);
void timer();
void Afficher_Minimap(SDL_Surface * screen, SDL_Rect posplayer, SDL_Rect posmonster, SDL_Rect posstar);

Gestion jeu;
Map map;
Gameobject star;
TTF_Font *font;
Hero monster;
Hero player;


