/**
* @file minimap.c
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

#include <string.h>
#include <unistd.h>
#include "minimap.h"


void Afficher_Minimap(SDL_Surface * screen, SDL_Rect posplayer, SDL_Rect posmonster, SDL_Rect posstar)
{
    SDL_Rect minimap = {1100,380,100,100};
    SDL_Rect position_player;
    SDL_Rect position_monster;
    SDL_Rect position_star;


    Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);
    Uint32 red = SDL_MapRGB(screen->format, 255, 12, 14);
    Uint32 blue = SDL_MapRGB(screen->format, 3,49,118);
    Uint32 gold = SDL_MapRGB(screen->format, 255,215,8);

    if(star.sprite != NULL)
    {
        posstar.x=652;
        posstar.y=277;
    }

    else
    {
        gold = white;
        posstar.x=0;
        posstar.y=0;
    }

    if (monster.sprite != NULL)
    {
        posmonster.x=monster.x;
        posmonster.y=monster.y;
    }

    else
    {
        red = white;
        posmonster.x=0;
        posmonster.y=0;

    }


    posplayer.x=player.x;
    posplayer.y=player.y;


    position_player = makeItSmall(minimap,posplayer);
    position_star = makeItSmall(minimap,posstar);
    position_monster = makeItSmall(minimap,posmonster);


    SDL_FillRect(screen, &minimap, white);
    SDL_FillRect(screen, &position_star, gold);
    SDL_FillRect(screen,  &position_monster, red);
    SDL_FillRect(screen, &position_player, blue);



}

SDL_Rect makeItSmall(SDL_Rect minimap, SDL_Rect position)
{
    SDL_Rect smallPosition;
    smallPosition.x = minimap.x + 400 * position.x / 8000;
    smallPosition.y = minimap.y + 200 * position.y / 8000;
    smallPosition.h = 10;
    smallPosition.w = 10;

    return smallPosition;
}
