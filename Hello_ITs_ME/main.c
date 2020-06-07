/**
* @file main.c
* @brief main libs
* @author Dynamic
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

#include "main.h"

int main( int argc, char *argv[ ] )
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int continuer;
    objet.poscollisionx = 0;
    objet.poscollisiony = 0;
    star.poscollisionx = 652;

    system("stty -F /dev/ttyACM0 9600 -parenb cs8 -cstopb");

    init("FEAR OF OCEAN");

    loadGame();

    atexit(cleanup);

    continuer = 1;


    while (continuer == 1)
    {

        if (jeu.joystick != NULL)
        {
            if(SDL_NumJoysticks() > 0)
                getJoystick();
            else
            {
                SDL_JoystickClose(jeu.joystick);
                jeu.joystick = NULL;
            }
        }
        else
        {
            if (SDL_NumJoysticks() > 0)
            {
                jeu.joystick = SDL_JoystickOpen(0);
                if (!jeu.joystick)
                    printf("error\n");
            }

            getInput();
        }

        //jump();

        if(jeu.onMenu == 0)
        {
            updatePlayer();

            if (monster.sprite!= NULL)
                updateMonster();

            if (collision() == 1)
            {
                if(input.clavierright ==1)
                    player.x -= PLAYER_SPEED;
                else if(input.clavierleft ==1)
                    player.x += PLAYER_SPEED;

            }

            if (collision() == 2 && star.sprite != NULL)
            {
                Sound(STAR);
                star.sprite = NULL;
                jeu.etoiles += 10;
                jeu.startest += 1;
            }

            if (collision() == 3 && monster.sprite != NULL)
            {
                jeu.vies--;
                if (jeu.vies < 1)
                    player.timerMort = 1;

                Sound(DESTROY);
                monster.sprite = NULL;
                jeu.monstertest += 1;
            }

            if (collision() == 4 && jeu.enigmetest == 1 )
            {
                afficherenigme();
                jeu.enigmetest += 1;
                input.clavierleft = 0;
                input.clavierright = 0;
                input.sourisleft = 0;
                input.sourisright = 0;
            }

        }

        else
        {
            if(jeu.menuType == START)
                updateStartMenu();

            else if(jeu.menuType == PAUSE)
                updatePauseMenu();

            if (jeu.onMenu == 3)
            {
                drawImage(map.background, 0, 0);
                affichersettings();
                SDL_Flip(jeu.screen);
                SDL_Delay(1);
            }

            if (jeu.onMenu == 2)
            {
                drawImage(map.background, 0, 0);
                affichermenu2();
                SDL_Flip(jeu.screen);
                SDL_Delay(1);

            }

        }

        if(jeu.onMenu == 0)
        {
            afficher();
        }

        else
        {
            if(jeu.menuType == START && jeu.onMenu != 3 && jeu.onMenu != 2 && jeu.onMenu != 4)
            {
                drawImage(map.background, 0, 0);
                afficherMenu();
                SDL_Flip(jeu.screen);
                SDL_Delay(1);
            }

            else if(jeu.menuType == PAUSE && jeu.onMenu != 4)
            {
                drawImage(map.background, 0, 0);
                afficherpause();
                SDL_Flip(jeu.screen);
                SDL_Delay(1);
            }

            if (jeu.onMenu == 4)
            {
                drawImage(map.background, 0, 0);
                afficherexit();
                SDL_Flip(jeu.screen);
                SDL_Delay(1);
            }

        }

        /* Gestion des 60 fps ( 60 images pas seconde : soit 1s ->1000ms/60 = 16.6 -> 16
        On doit donc attendre 16 ms entre chaque image (frame) */
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;

    }

    exit(0);

}






