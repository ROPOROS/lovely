/**
* @file monster.c
* @brief monster libs
* @author skander+cyrine
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

#include "monster.h"


void initializeMonster(void)
{

    monster.sprite = IMG_Load("capserright.png");

    monster.direction = RIGHT;

    monster.frameNumber = 0;
    monster.frameTimer = TIME_BETWEEN_2_FRAMES;

    monster.w = MONSTER_WIDTH;
    monster.h = MONSTER_HEIGTH;

    monster.x = 800;
    monster.y = 304;

    monster.timerMort = 0;

}

void afficherMonster()
{

    SDL_Rect dest;

    dest.x = monster.x - map.startX;
    dest.y = monster.y - map.startY;
    dest.w = MONSTER_WIDTH;
    dest.h = MONSTER_HEIGTH;

    SDL_Rect src;

    src.x = monster.frameNumber * MONSTER_WIDTH;
    src.y = 0;
    src.w = MONSTER_WIDTH;;
    src.h = MONSTER_HEIGTH;


    SDL_BlitSurface(monster.sprite, &src, jeu.screen, &dest);

}

void updateMonster(void)
{
    if (monster.timerMort == 0)
    {
        if (monster.x == objet.poscollisionx +930 || monster.x == objet.poscollisionx +620)
        {
            if (monster.direction == RIGHT)
            {
                monster.direction = LEFT;
                changeAnimation(&monster, "capserleft.png");
            }
            else
            {
                monster.direction = RIGHT;;
                changeAnimation(&monster, "capserright.png");
            }

        }


        if(monster.direction == LEFT)
            monster.x -= 2;
        else
            monster.x += 2;

    }
}
