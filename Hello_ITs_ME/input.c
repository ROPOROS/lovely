/**
* @file input.c
* @brief input libs
* @author Youssef+Cyrine
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

#include "input.h"

void getInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

        case SDL_QUIT:
            exit(0);
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                exit(0);
                break;

            case SDLK_DELETE:
                input.claviererase = 1;
                break;

            case SDLK_c:
                input.clavierjump = 1;
                break;

            case SDLK_v:
                input.clavierexit = 1;
                break;

            case SDLK_LEFT:
                input.clavierleft = 1;
                break;

            case SDLK_RIGHT:
                input.clavierright = 1;
                break;

            case SDLK_DOWN:
                input.clavierdown = 1;
                break;

            case SDLK_UP:
                input.clavierup = 1;
                break;

            case SDLK_RETURN:
                input.clavierenter = 1;
                break;

            default:
                break;
            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_DELETE:
                input.claviererase = 0;
                break;

            case SDLK_c:
                input.clavierjump = 0;
                break;

            case SDLK_LEFT:
                input.clavierleft = 0;
                break;

            case SDLK_RIGHT:
                input.clavierright = 0;
                break;

            case SDLK_DOWN:
                input.clavierdown = 0;
                break;

            case SDLK_UP:
                input.clavierup = 0;
                break;

            case SDLK_RETURN:
                input.clavierenter = 0;
                break;

            default:
                break;
            }
            break;




        case SDL_MOUSEBUTTONDOWN:
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                input.sourisleft = 1;
                input.sourisenter = 1;
            }

            if(event.button.button == SDL_BUTTON_RIGHT)
                input.sourisright = 1;

            break;

        case SDL_MOUSEBUTTONUP:
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                input.sourisleft = 0;
                input.sourisenter = 0;
            }

            if(event.button.button == SDL_BUTTON_RIGHT)
                input.sourisright = 0;


            break;
        }

    }
}


void getJoystick()
{
    SDL_Event event;
    //Si on ne touche pas au D-PAD, on le désactive (on teste les 4 boutons du D-PAD)
    if (SDL_JoystickGetButton(jeu.joystick, BOUTON_HAUT) == 0 &&  SDL_JoystickGetButton(jeu.joystick, BOUTON_BAS) == 0
        && SDL_JoystickGetButton(jeu.joystick, BOUTON_DROITE) == 0 && SDL_JoystickGetButton(jeu.joystick, BOUTON_GAUCHE) == 0)
        DPADinUse = 0;

    while (SDL_PollEvent(&event))
    {
            if ( event.type == SDL_QUIT )
                exit(0);
            else if ( event.type == SDL_KEYDOWN )
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;
                    default:
                    break;
                }
            }
            else if (event.type == SDL_JOYBUTTONDOWN)
            {
                if (event.jbutton.button == BOUTON_SAUT)
                    input.clavierjump = 1;
                else if (event.jbutton.button == BOUTON_PAUSE)
                    input.clavierenter = 1;

                else if (event.jbutton.button == BOUTON_HAUT)
                {
                    input.clavierup = 1;
                    DPADinUse = 1;
                }
                else if (event.jbutton.button == BOUTON_BAS)
                {
                    input.clavierdown = 1;
                    DPADinUse = 1;
                }
                else if (event.jbutton.button == BOUTON_GAUCHE)
                {
                    input.clavierleft = 1;
                    DPADinUse = 1;
                }
                else if (event.jbutton.button == BOUTON_DROITE)
                {
                    input.clavierright = 1;
                    DPADinUse = 1;
                }
            }
            else if (event.type == SDL_JOYBUTTONUP)
            {
                if (event.jbutton.button == BOUTON_PAUSE)
                    input.clavierenter = 0;
                else if (event.jbutton.button == BOUTON_SAUT)
                    input.clavierjump = 0;
                else if (event.jbutton.button == BOUTON_HAUT)
                    input.clavierup = 0;
                else if (event.jbutton.button == BOUTON_BAS)
                    input.clavierdown = 0;
                else if (event.jbutton.button == BOUTON_GAUCHE)
                    input.clavierleft = 0;
                else if (event.jbutton.button == BOUTON_DROITE)
                    input.clavierright = 0;
            }
            else if(event.type == SDL_JOYAXISMOTION && DPADinUse == 0)
            {
                //Si le joystick a détecté un mouvement
                if( event.jaxis.which == 0 )
                {
                    //Si le mouvement a eu lieu sur l'axe des X
                    if( event.jaxis.axis == 0 )
                    {
                        if(( event.jaxis.value > -DEAD_ZONE ) && ( event.jaxis.value < DEAD_ZONE ))
                        {
                            input.clavierright = 0;
                            input.clavierleft = 0;
                        }
                        else
                        {
                            if( event.jaxis.value < -DEAD_ZONE )
                            {
                                input.clavierright = 0;
                                input.clavierleft = 1;
                            }
                            else if( event.jaxis.value > DEAD_ZONE )
                            {
                                input.clavierright = 1;
                                input.clavierleft = 0;
                            }
                        }
                    }
                    //Si le mouvement a eu lieu sur l'axe des Y
                    else if( event.jaxis.axis == 1 )
                    {
                        if( ( event.jaxis.value > -DEAD_ZONE ) && ( event.jaxis.value < DEAD_ZONE ) )
                        {
                            input.clavierup = 0;
                            input.clavierdown = 0;
                        }
                        else
                        {
                            if( event.jaxis.value < 0 )
                            {
                                input.clavierup = 1;
                                input.clavierdown = 0;
                            }
                            else
                            {
                                input.clavierup = 0;
                                input.clavierdown = 1;
                            }
                        }
                    }
                }
            }
    }
}
