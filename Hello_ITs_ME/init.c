/**
* @file init.c
* @brief init libs
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

#include "init.h"


void init(char *title)
{

    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("erreurinit1");
        exit(1);
    }

    jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

    SDL_ShowCursor(SDL_DISABLE);

    SDL_WM_SetCaption(title, NULL);


    if (TTF_Init() < 0)
    {
        printf("erreurinit2\n");
        exit(1);
    }

    font = loadFont("GenBasB.ttf", 32);

    /*int flags=MIX_INIT_MP3;
    int initted=Mix_Init(flags);

    if( (initted & flags) != flags)
    {
        printf("erreurinit3\n");
        printf("erreurinit4");
        exit(1);
    }*/

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==-1)
    {
        printf("erreurinit5");
        exit(1);
    }

    Mix_AllocateChannels(32);


    SDL_InitSubSystem(SDL_INIT_JOYSTICK);

    if (SDL_NumJoysticks() > 0)
    {
        jeu.joystick = SDL_JoystickOpen(0);

        if (!jeu.joystick)
            printf("erreurinit6 !\n");

    }

}

void loadGame(void)
{

    if (map.background != NULL)
    {
        SDL_FreeSurface(map.background);
    }

    map.background = loadImage("blurbackground.png");
    map.dest.x = 0;
    map.dest.y = 0;

    star.sprite = IMG_Load("star.png");
    star.dest.x= 652;
    star.dest.y= 277;

    jeu.vies = 3;
    jeu.etoiles = 0;

    jeu.HUD_vie = IMG_Load("life.png");
    jeu.HUD_etoiles = IMG_Load("stars.png");

    loadSong("Music-Adventure-Soundtrack.mp3");

    loadSound();

    jeu.onMenu = 1;

    player.perso = 1;

    jeu.saut = 0;

    jeu.calcule=0;

    jeu.enigmetest = 1;
    jeu.startest = 1;
    jeu.monstertest = 1;

    jeu.menuType = START;

}


void cleanup()
{
    if (map.background != NULL)
    {
        SDL_FreeSurface(map.background);
    }

    if (player.sprite != NULL)
    {
        SDL_FreeSurface(player.sprite);
    }

    if (monster.sprite != NULL)
    {
        SDL_FreeSurface(monster.sprite);
    }

    if (star.sprite != NULL)
    {
        SDL_FreeSurface(star.sprite);
    }

    if (monster.sprite != NULL)
    {
        SDL_FreeSurface(monster.sprite);
    }

    if (jeu.HUD_etoiles != NULL)
    {
        SDL_FreeSurface(jeu.HUD_etoiles);
    }
    if (jeu.HUD_vie != NULL)
    {
        SDL_FreeSurface(jeu.HUD_vie);
    }

    if ( jeu.musique != NULL )
        Mix_FreeMusic(jeu.musique);

    freeSound();

    Mix_CloseAudio();
    Mix_Quit();

    closeFont(font);

    SDL_Quit();
}
