/**
* @file player.c
* @brief player libs
* @author Yasmine+Cyrine
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

#include "player.h"


void initializePlayer(void)
{
    if (player.perso == 1)
        changeAnimation(&player, "walkright1.png");
    else if (player.perso == 2)
        changeAnimation(&player, "walkright2.png");

    player.direction = RIGHT;
    player.etat = WALK;

    player.w = PLAYER_WIDTH;
    player.h = PLAYER_HEIGTH;

    player.x = 20;
    player.y = 264;

    player.timerMort = 0;

}

void afficherplayer()
{

    SDL_Rect dest;

    dest.x = player.x - map.startX;
    dest.y = player.y - map.startY;
    dest.w = PLAYER_WIDTH;
    dest.h = PLAYER_HEIGTH;

    SDL_Rect src;

    src.x = player.frameNumber * PLAYER_WIDTH;
    src.y = 0;
    src.w = PLAYER_WIDTH;
    src.h = PLAYER_HEIGTH;


    SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);

}


void updatePlayer()
{

    if (player.timerMort == 0)
    {

        if (input.clavierleft == 1 || input.sourisleft == 1)
        {

            if(player.x >= 470 || map.dest.x >= 0)
                player.x -= PLAYER_SPEED;
            else
            {
                map.dest.x += PLAYER_SPEED;
                objet.poscollisionx += PLAYER_SPEED;
                star.dest.x += PLAYER_SPEED;
                monster.x += PLAYER_SPEED;
            }


            if (player.x < 0)
            {
                player.x = 0;
            }

            if(player.direction == RIGHT && player.perso == 1)
            {
                player.direction = LEFT;
                changeAnimation(&player, "walkleft1.png");
            }
            else if(player.direction == RIGHT && player.perso == 2)
            {
                player.direction = LEFT;
                changeAnimation(&player, "walkleft2.png");
            }

        }

        else if (input.clavierright == 1 || input.sourisright == 1)
        {
            if(player.x <=  470 || map.dest.x <= (1200 - 4800))
            {
                if (player.x<1200-60)
                    player.x += PLAYER_SPEED;
            }
            else
            {
                map.dest.x -= PLAYER_SPEED;
                objet.poscollisionx -= PLAYER_SPEED;
                star.dest.x -= PLAYER_SPEED;
                monster.x -= PLAYER_SPEED;
            }


            if (player.x + PLAYER_WIDTH <= map.maxX)
            {
                player.x = map.maxX - PLAYER_WIDTH;;
            }

            if(player.direction == LEFT && player.perso == 1)
            {
                player.direction =  RIGHT;
                changeAnimation(&player, "walkright1.png");
            }
            else if (player.direction == LEFT && player.perso == 2)
            {
                player.direction =  RIGHT;
                changeAnimation(&player, "walkright2.png");
            }

        }


        if(input.clavierenter == 1)
        {
            jeu.onMenu = 1;
            jeu.menuType = PAUSE;
            input.clavierenter = 0;
        }

    }

    if (player.timerMort > 0)
    {
        player.timerMort--;

        if (player.timerMort == 0)
        {

            if(jeu.vies < 0)
            {
                jeu.enigmetest = 1;
                jeu.onMenu = 1;
                jeu.menuType = START;
            }

            objet.poscollisionx = 990;
            initializeMonster();
            loadGame();

        }

    }

}


