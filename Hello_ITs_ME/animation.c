/**
* @file animation.c
* @brief animation libs
* @author Raed+Yasmine+Youssef
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

#include "animation.h"


void animationplayer()
{

    if (player.frameTimer <= 0)
    {
        player.frameTimer = TIME_BETWEEN_2_FRAMES;

        if (input.clavierleft == 1 || input.clavierright == 1 || input.sourisleft || input.sourisright )
        {
            player.frameNumber++;

            if(player.frameNumber >= player.sprite->w / PLAYER_WIDTH)
                player.frameNumber = 0;
        }

        else
        {
            if(player.direction == RIGHT)
                player.frameNumber = 0;
            else
                player.frameNumber = 11;
        }

    }

    else
        player.frameTimer--;

    afficherplayer();

}

void animationMonster(void)
{
    if (monster.frameTimer <= 0)
    {
        monster.frameTimer = TIME_BETWEEN_2_FRAMES;
        monster.frameNumber++;

        if(monster.frameNumber >= monster.sprite->w / MONSTER_WIDTH )
            monster.frameNumber = 0;

    }

    else
        monster.frameTimer--;

    afficherMonster();
}



void changeAnimation(Hero *entity, char *name)
{

    if (entity->sprite != NULL)
    {
        SDL_FreeSurface(entity->sprite);
    }

    entity->sprite = IMG_Load(name);

    entity->frameNumber = 0;
    entity->frameTimer = TIME_BETWEEN_2_FRAMES;
}
