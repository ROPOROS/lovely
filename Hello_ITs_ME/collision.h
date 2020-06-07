/**
* @file collision.h
* @brief collision libs
* @author skander
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

Hero player;
Hero monster;
Gameobject objet;
Gameobject star;
Gestion jeu;


int collision();
void Sound(int type);
