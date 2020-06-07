/**
* @file collision.c
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

#include "collision.h"

int collision()
{
    int collisionp;
    collisionp=0;

    if((player.x < objet.poscollisionx+ 1035 && player.x + PLAYER_WIDTH > objet.poscollisionx+978
        && player.y < objet.poscollisiony+380 && player.y + PLAYER_HEIGTH > objet.poscollisiony+240)
            ||(player.x < objet.poscollisionx+ 1345 && player.x + PLAYER_WIDTH > objet.poscollisionx+1032
                && player.y < objet.poscollisiony+380 && player.y + PLAYER_HEIGTH > objet.poscollisiony+316)
                    ||(player.x < objet.poscollisionx+ 2377 && player.x + PLAYER_WIDTH > objet.poscollisionx+1345
                        && player.y < objet.poscollisiony+316 && player.y + PLAYER_HEIGTH > objet.poscollisiony+243)
                            ||(player.x < objet.poscollisionx+ 1812 && player.x + PLAYER_WIDTH > objet.poscollisionx+1752
                                && player.y < objet.poscollisiony+300 && player.y + PLAYER_HEIGTH > objet.poscollisiony+178)
                            ||(player.x < objet.poscollisionx+ 2377 && player.x + PLAYER_WIDTH > objet.poscollisionx+1345
                        && player.y < objet.poscollisiony+316 && player.y + PLAYER_HEIGTH > objet.poscollisiony+243)
                    ||(player.x < objet.poscollisionx+ 1812 && player.x + PLAYER_WIDTH > objet.poscollisionx+1752
                && player.y < objet.poscollisiony+300 && player.y + PLAYER_HEIGTH > objet.poscollisiony+178)
            ||(player.x < objet.poscollisionx+ 3160 && player.x + PLAYER_WIDTH > objet.poscollisionx+2740
        && player.y < objet.poscollisiony+380 && player.y + PLAYER_HEIGTH > objet.poscollisiony+165)
       ||(player.x < objet.poscollisionx+ 3900 && player.x + PLAYER_WIDTH > objet.poscollisionx+3845
    && player.y < objet.poscollisiony+380 && player.y + PLAYER_HEIGTH > objet.poscollisiony+165))

    {
        collisionp=1;
    }

    else if (player.x+PLAYER_WIDTH == star.dest.x )
    {
        collisionp =2;
    }

    else if (player.x+PLAYER_WIDTH >= monster.x && player.x+PLAYER_WIDTH <= monster.x + MONSTER_WIDTH )
    {
        collisionp=3;
    }

    else if (player.x+PLAYER_WIDTH == 500)
    {
        collisionp=4;
    }


    return collisionp;

}
