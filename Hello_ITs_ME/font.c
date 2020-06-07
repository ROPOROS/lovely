/**
* @file font.c
* @brief font libs
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

#include "font.h"

TTF_Font *loadFont(char *name, int size)
{

    TTF_Font *font = TTF_OpenFont(name, size);

    if (font == NULL)
    {
        printf("erreurttf");

        exit(1);
    }

    return font;
}


void closeFont(TTF_Font *font)
{

    if (font != NULL)
    {
        TTF_CloseFont(font);
    }
}


void drawString(char *text, int x, int y, TTF_Font *font)
{
    SDL_Rect dest;
    SDL_Surface *surface;
    SDL_Color foregroundColor;

    foregroundColor.r = 0;
    foregroundColor.g = 0;
    foregroundColor.b = 0;


    surface = TTF_RenderUTF8_Blended(font, text, foregroundColor);


    if (surface == NULL)
    {
        printf("erreurttf2\n");

        return;
    }

    dest.x = x;
    dest.y = y;
    dest.w = surface->w;
    dest.h = surface->h;

    SDL_BlitSurface(surface, NULL, jeu.screen, &dest);

    SDL_FreeSurface(surface);
}


void draw_String(char *text, int x, int y, TTF_Font *font)
{
    SDL_Rect dest;
    SDL_Surface *surface;
    SDL_Color foregroundColor;

    foregroundColor.r = 252;
    foregroundColor.g = 199;
    foregroundColor.b = 12;


    surface = TTF_RenderUTF8_Blended(font, text, foregroundColor);


    if (surface == NULL)
    {
        printf("erreurttf3\n");

        return;
    }

    dest.x = x;
    dest.y = y;
    dest.w = surface->w;
    dest.h = surface->h;

    SDL_BlitSurface(surface, NULL, jeu.screen, &dest);

    SDL_FreeSurface(surface);
}
