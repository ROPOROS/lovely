/**
* @file enigme.c
* @brief enigme libs
* @author Raed+Youssef
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

#include "enigme.h"

void init_enigme(enigme * e)
{
    e->p.x=0;
    e->p.y=0;
    e->img=NULL;
}


void generate_afficher (SDL_Surface * screen, char image [],enigme *e,int *alea)
{
    int test=*alea ;
    do
    {
        *alea = 1+ rand()%3;
    }
    while(*alea==test) ;
    sprintf(image,"%d.png",*alea);
    e->img = IMG_Load(image);
    SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
    SDL_Flip(screen) ;
}


int solution(char image [])
{
    int solution =0 ;

    if(strcmp(image,"1.png")==0)
    {
        solution =1 ;
    }
    else if(strcmp(image,"2.png")==0)
    {
        solution =4;

    }
    else if(strcmp(image,"3.png")==0)
    {
        solution =4;
    }
    return solution;
}


int resolution (int * running,int *run )
{
    SDL_Event event ;
    int r=0 ;
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        *running= 0 ;
        *run = 0;
        break ;

    case SDL_KEYDOWN :
        switch( event.key.keysym.sym )
        {
        case  SDLK_q:
            r = 1;
            break ;
        case  SDLK_b :
            r = 2;
            break;
        case SDLK_c:
            r = 3 ;
            break;
        case SDLK_d:
            r = 4 ;
            break;
        }
        break ;
    }
    return r ;
}

void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)
{
    en->p1.x=332;
    en->p1.y=54;

    if (r==s)
    {
        en->img=IMG_Load("00.png");
        SDL_BlitSurface(en->img, NULL, screen, &(en->p1)) ;
        SDL_Flip(screen);
        jeu.etoiles += 40;
        return;

    }
    else
    {
        en->img=IMG_Load("11.png");
        SDL_BlitSurface(en->img, NULL, screen, &(en->p1)) ;
        SDL_Flip(screen);
        jeu.vies --;
        if(jeu.vies < 1)
            player.timerMort = 1;
        return;
    }
}

void afficherenigme()
{

    enigme  e,en;
    int s,r,run =1,running=1,alea;
    char image[30]="";
    SDL_Event event;
    srand(time(NULL));


    init_enigme(&e);

    running=1,r=0 ;
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        run = 0;
        break ;
    }

    generate_afficher ( jeu.screen, image,&e,&alea) ;
    s=solution(image );

    do
    {
        r=resolution (&running,&run);
    }
    while((r>4 || r<1) && running!=0) ;

    afficher_resultat (jeu.screen,s,r,&en) ;
    SDL_Delay(1000);
    SDL_WaitEvent(&event);

    if (e.img != NULL)
    {
        SDL_FreeSurface(e.img);
    }

}


