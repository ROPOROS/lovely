/**
* @file structs.h
* @brief structs libs
* @author youssef
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

#include "defs.h"

typedef struct Input
{

    int clavierleft, clavierright, clavierup, clavierdown, clavierjump, clavierexit, clavierenter, claviererase, clavierpause;
    int sourisleft, sourisright, sourisup, sourisdown, sourisenter;

} Input;


typedef struct Gestion
{
    SDL_Surface *screen;
    SDL_Surface *HUD_vie, *HUD_etoiles;
    SDL_Joystick *joystick;
    int vies, etoiles;
    Uint32 time;
    char chrono[16];
    int enigmetest, startest, monstertest,count;
    Mix_Music  *musique;
    int saut;
    int calcule;
    Mix_Chunk  *button_sound, *destroy_sound, *star_sound;
    int onMenu, menuType, choice, settingschoice, pausechoice, menuchoice, savechoice;

} Gestion;


typedef struct Map
{
    SDL_Surface *background;
    SDL_Rect dest;
    int startX, startY;
    int maxX, maxY;

} Map;


typedef struct Hero
{

    SDL_Surface *sprite;
    int x, y;
    int w, h;
    float dirX, dirY;
    int frameNumber, frameTimer;
    int timerMort;
    int etat, direction;
    SDL_Rect position;
    int perso;

} Hero;


typedef struct Gameobject
{
    SDL_Surface *sprite;
    SDL_Rect dest;
    int poscollisionx, poscollisiony;
    int vie, score;

} Gameobject;


