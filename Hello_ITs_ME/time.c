/**
* @file time.c
* @brief time libs
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

#include "time.h"

void timer()
{
    TTF_Font *police;
    SDL_Rect postime;
    SDL_Surface *texte =  NULL;
    SDL_Color noir = {4,9,30,0}, blanc = {255,255,255};

    postime.x = 480;
    postime.y = 0;


    TTF_Init();
    police = TTF_OpenFont("GenBasB.ttf", 69);

    jeu.time = SDL_GetTicks();             //Minute       //Seconde   //Dixieme
    sprintf(jeu.chrono, "%02u:%02u.%u", jeu.time/1000/60%60, jeu.time/1000%60, jeu.time%1000/100);
    texte = TTF_RenderText_Blended(police, jeu.chrono, blanc);

    SDL_BlitSurface(texte, NULL, jeu.screen, &postime);

    if (texte != NULL)
    {
        SDL_FreeSurface(texte);
    }

    TTF_CloseFont(police);

}

