/**
* @file defs.h
* @brief defs libs
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

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 480

#define TRANS_R 255
#define TRANS_G 0
#define TRANS_B 255

#define PLAYER_HEIGTH 120
#define PLAYER_WIDTH 60

#define MONSTER_WIDTH 70
#define MONSTER_HEIGTH 74

#define TIME_BETWEEN_2_FRAMES 8

#define PLAYER_SPEED 4

#define PLAYER_JUMP 2.7

#define ON_GROUND 264

#define WALK 1
#define JUMP 2
#define RIGHT 1
#define LEFT 2

#define DEAD_ZONE 8000
#define BOUTON_HAUT 2
#define BOUTON_BAS 3
#define BOUTON_GAUCHE 4
#define BOUTON_DROITE 5
#define BOUTON_SAUT 7
#define BOUTON_PAUSE 6

enum
{
    DESTROY,
    STAR,
    BUTTON
};

enum
{
    START,
    PAUSE
};
