/**
* @file musique.c
* @brief musique libs
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

#include "musique.h"

void loadSong( char filename[200] )
{

    if ( jeu.musique != NULL )
    {
        Mix_HaltMusic();
        Mix_FreeMusic(jeu.musique);
    }

    jeu.musique = Mix_LoadMUS( filename );

    if(Mix_PlayMusic(jeu.musique, -1)==-1)
    {
        printf("erreur");
    }

}


void loadSound(void)
{

    jeu.destroy_sound = Mix_LoadWAV("destroy.wav");
    if (jeu.destroy_sound == NULL)
    {
        fprintf(stderr, "erreur\n");
        exit(1);
    }


    jeu.star_sound = Mix_LoadWAV("star.wav");
    if (jeu.star_sound == NULL)
    {
        fprintf(stderr, "erreur\n");
        exit(1);
    }

    jeu.button_sound = Mix_LoadWAV("audioclip-1581540580-323 (1).wav");
    if (jeu.button_sound == NULL)
    {
        fprintf(stderr, "erreur\n");
        exit(1);
    }

}

void freeSound(void)
{

    Mix_FreeChunk(jeu.destroy_sound);
    Mix_FreeChunk(jeu.star_sound);
    Mix_FreeChunk(jeu.button_sound);

}


void Sound(int type)
{

    switch (type)
    {

    case DESTROY:
        Mix_PlayChannel(-1, jeu.destroy_sound, 0);
        break;

    case STAR:
        Mix_PlayChannel(-1, jeu.star_sound, 0);
        break;

    case BUTTON:
        Mix_PlayChannel(-1, jeu.button_sound, 0);
        break;

    }

}
