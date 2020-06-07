/**
* @file main.h
* @brief main libs
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

void init(char *);
void cleanup(void);
void getInput(void);
void afficher(void);
void loadGame(void);
void delay(unsigned int frameLimit);
void initializePlayer(void);
void initializeMonster(void);
void updatePlayer(void);
void updateMonster(void);
int collision(void);
void afficherenigme(void);
void afficherMenu(void);
void affichermenu2(void);
void affichersettings(void);
void afficherexit(void);
void updateStartMenu(void);
void drawImage(SDL_Surface *image, int x, int y);
void Sound(int type);
void afficherpause(void);
void updatePauseMenu(void);
void drawMap(void);
void animationplayer(void);
void animationMonster(void);
void drawHud(void);
void getJoystick(void);


Input input;
Gestion jeu;
Map map;
Hero player;
Hero monster;
Gameobject objet;
Gameobject star;
TTF_Font *font;
