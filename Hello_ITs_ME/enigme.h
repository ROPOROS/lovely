/**
* @file enigme.h
* @brief enigme libs
* @author Raed+Youssef
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

typedef struct
{
    SDL_Surface * img;
    SDL_Rect 	p;
    SDL_Rect  p1;
} enigme;

Gestion jeu;
Hero player;

void init_enigme(enigme * e) ;
void  generate_afficher (SDL_Surface * screen, char image [],enigme *e,int *alea) ;
int solution(char image []) ;
int resolution (int * running,int *run);
void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en) ;
