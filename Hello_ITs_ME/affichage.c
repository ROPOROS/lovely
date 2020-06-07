/**
* @file affichage.c
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

#include "affichage.h"


void afficherImage(void)
{
    SDL_Rect copy;
    copy=map.dest;
    SDL_BlitSurface(map.background, NULL, jeu.screen, &copy);
    SDL_BlitSurface(star.sprite, NULL, jeu.screen, &star.dest);
}


void drawImage(SDL_Surface *image, int x, int y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;

    SDL_BlitSurface(image, NULL, jeu.screen, &dest);
}


void afficher(void)
{
    int t;

    SDL_Rect posplayer, posmonster, posstar;

    afficherImage();

    animationplayer();

    if (monster.sprite!= NULL)
        animationMonster();

    drawHud();

    timer();

    Afficher_Minimap(jeu.screen, posplayer, posmonster, posstar);

    SDL_Flip(jeu.screen);

    SDL_Delay(1);

}


SDL_Surface *loadImage(char *name)
{

    SDL_Surface *temp = IMG_Load(name);
    SDL_Surface *image;

    SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(temp->format,TRANS_R, TRANS_G,TRANS_B));

    image = SDL_DisplayFormat(temp);

    SDL_FreeSurface(temp);

    return image;

}


void delay(unsigned int frameLimit)
{

    /* Gestion des 60 fps (images/stories/seconde) */

    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}


void drawHud(void)
{
    char text[200];


    drawImage(jeu.HUD_vie, 1090, 40);
    sprintf(text, "%d", jeu.vies);
    drawString(text, 1160, 49, font);

    drawImage(jeu.HUD_etoiles, 40, 40);
    sprintf(text, "%d", jeu.etoiles);
    drawString(text, 80, 37, font);

}
