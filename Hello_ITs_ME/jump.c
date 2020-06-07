/**
* @file jump.c
* @brief jump libs
* @author Yasmine
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

#include "jump.h"


/* just for test */
void jump(void)
{
    if (input.clavierjump == 1)
        jeu.saut=1;

    if (jeu.saut == 1 && jeu.calcule < 60 && jeu.calcule < 120)
    {
        player.y -= PLAYER_JUMP;
        jeu.calcule+=1.5;
    }

    if ( jeu.calcule >= 60)
    {
        if (player.y != ON_GROUND)
        {


            player.y += PLAYER_JUMP;
        jeu.calcule+=1.5;
         }

    }

    if(jeu.calcule==120)
    {
        jeu.saut=0;
        jeu.calcule=0;
    }
}
