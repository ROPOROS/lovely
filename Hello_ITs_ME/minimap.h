/**
* @file minimap.h
* @brief minimap libs
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

#include <unistd.h>
#include "structs.h"

Gestion jeu;
Map map;
Hero player;
Hero monster;
Gameobject star;

void Afficher_Minimap(SDL_Surface * screen, SDL_Rect posplayer, SDL_Rect posmonster, SDL_Rect posstar);
SDL_Rect makeItSmall(SDL_Rect minimap, SDL_Rect position);
