/**
* @file menu.c
* @brief menu libs
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

#include "menu.h"

void updateStartMenu(void)
{
    char nomFich[] = "save.txt";

    if(input.clavierdown == 1  && jeu.onMenu == 1)
    {
        if(jeu.choice == 0 || jeu.choice == 1 )
        {
            jeu.choice++;
            Sound(BUTTON);
        }

        input.clavierdown = 0;
        input.sourisdown=0;

    }

    if(input.clavierup == 1 && jeu.onMenu == 1 )
    {
        if(jeu.choice == 1 || jeu.choice == 2)
        {
            jeu.choice--;
            Sound(BUTTON);
        }

        input.clavierup = 0;
        input.sourisup = 0;
    }

    if (input.clavierright == 1 && (jeu.onMenu == 2 || jeu.onMenu == 3 ))
    {
        if (jeu.settingschoice == 0 || jeu.settingschoice == 1 || jeu.settingschoice == 2 || jeu.settingschoice == 3 )
        {
            jeu.settingschoice++;
            Sound(BUTTON);
        }

        if (jeu.menuchoice == 0)
        {
            jeu.menuchoice++;
            Sound(BUTTON);
        }

        input.clavierright = 0;
        input.sourisright = 0;

    }

    if (input.clavierleft == 1 && (jeu.onMenu == 2 || jeu.onMenu == 3 ) )
    {
        if (jeu.settingschoice == 1 || jeu.settingschoice == 2 || jeu.settingschoice == 3 || jeu.settingschoice == 4 )
        {
            jeu.settingschoice--;
            Sound(BUTTON);
        }

        if (jeu.menuchoice == 1)
        {
            jeu.menuchoice--;
            Sound(BUTTON);
        }

        input.clavierleft = 0;
        input.sourisleft = 0;
    }

    if (input.clavierexit == 1)
    {
        if (map.background != NULL)
        {
            SDL_FreeSurface(map.background);
        }
        map.background = loadImage("blurbackground.png");
        jeu.onMenu =1;

        input.clavierexit = 0;
    }



    if( (input.clavierenter || input.sourisenter)  && jeu.onMenu != 2)
    {
        if(jeu.choice == 0)
        {
            if (map.background != NULL)
            {
                SDL_FreeSurface(map.background);
            }
            map.background = loadImage("settings1.png");
            jeu.onMenu = 2;

        }

        else if (jeu.choice == 1)
        {
            if (map.background != NULL)
            {
                SDL_FreeSurface(map.background);
            }
            map.background = loadImage("settings.png");
            jeu.onMenu = 3;

        }

        else if(jeu.choice == 2)
        {
            exit(0);
        }

        if (jeu.settingschoice == 0 )
        {
            SDL_ShowCursor(SDL_DISABLE);
        }

        else if (jeu.settingschoice == 1)
        {
            SDL_ShowCursor(SDL_DISABLE);
        }

        else if (jeu.settingschoice == 2 )
        {
            SDL_ShowCursor(SDL_ENABLE);
        }

        else if (jeu.settingschoice == 3 )
        {
            player.perso = 1;
        }

        else if (jeu.settingschoice == 4 )
        {
            player.perso = 2;
        }


        input.clavierenter = 0;
        input.sourisenter = 0;
    }

    if( (input.clavierenter || input.sourisenter ) && jeu.onMenu == 2)
    {
        if (jeu.menuchoice == 0)
        {
            if (map.background != NULL)
            {
                SDL_FreeSurface(map.background);
            }
            map.background = loadImage("background1.png");

            initializePlayer();
            initializeMonster();
            jeu.vies = 2;
            jeu.etoiles = 0;
            jeu.onMenu = 0;
            map.dest.x = 0;
            map.dest.y = 0;

            star.sprite = IMG_Load("star.png");
            star.dest.x= 652;
            star.dest.y= 277;

        }

        else if (jeu.menuchoice == 1)
        {
            if (map.background != NULL)
            {
                SDL_FreeSurface(map.background);
            }
            map.background = loadImage("background1.png");

            load(&player, &jeu, &map, nomFich);
            player.y = 264;
            map.dest.y = 0;

            if (player.perso == 1)
                changeAnimation(&player, "walkright1.png");
            else if (player.perso == 2)
                changeAnimation(&player, "walkright2.png");

            player.direction = RIGHT;
            player.etat = WALK;

            player.w = PLAYER_WIDTH;
            player.h = PLAYER_HEIGTH;

            if (jeu.startest == 1)
            {
                if (star.sprite != NULL)
                {
                    SDL_FreeSurface(star.sprite);
                }

                star.sprite = IMG_Load("star.png");
                star.dest.x= 652;
                star.dest.y= 277;
            }
            else
                star.sprite = NULL;

            if (jeu.monstertest == 1)
            {
                if (monster.sprite != NULL)
                {
                    SDL_FreeSurface(monster.sprite);
                }

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
            else
                monster.sprite = NULL;

            player.timerMort = 0;

            jeu.onMenu = 0;
        }

        input.clavierenter = 0;
        input.sourisenter = 0;

    }

}


void afficherMenu(void)
{

    char text[200];


    if(jeu.choice != 0)
    {
        sprintf(text, "START");
        drawString(text, 540, 200, font);
    }

    if(jeu.choice != 1)
    {
        sprintf(text, "SETINGS");
        drawString(text, 530, 275, font);
    }

    if(jeu.choice != 2)
    {
        sprintf(text, "QUIT");
        drawString(text, 550, 350, font);
    }


    if(jeu.choice == 0)
    {
        sprintf(text, "START");
        draw_String(text, 540, 200, font);
    }

    if(jeu.choice == 1)
    {
        sprintf(text, "SETINGS");
        draw_String(text, 530, 275, font);
    }

    else if(jeu.choice == 2)
    {
        sprintf(text, "QUIT");
        draw_String(text, 550, 350, font);
    }


}

void affichersettings(void)
{
    char text[200];

    if(jeu.settingschoice != 0)
    {
        sprintf(text, "Manette");
        drawString(text, 345, 150, font);
    }

    if(jeu.settingschoice != 1)
    {
        sprintf(text, "Clavier");
        drawString(text, 535, 150, font);
    }

    if(jeu.settingschoice != 2)
    {
        sprintf(text, "Souris");
        drawString(text, 700, 150, font);
    }

    if(jeu.settingschoice != 3)
    {
        sprintf(text, "PLAYER 1");
        drawString(text, 400, 405, font);
    }

    if(jeu.settingschoice != 4)
    {
        sprintf(text, "PLAYER 2");
        drawString(text, 628, 405, font);
    }

    if(jeu.settingschoice == 0)
    {
        sprintf(text, "Manette");
        draw_String(text, 345, 150, font);
    }

    if(jeu.settingschoice == 1)
    {
        sprintf(text, "Clavier");
        draw_String(text, 535, 150, font);
    }

     if(jeu.settingschoice == 2)
    {
        sprintf(text, "Souris");
        draw_String(text, 700, 150, font);
    }

        if(jeu.settingschoice == 3)
    {
        sprintf(text, "PLAYER 1");
        draw_String(text, 400, 405, font);
    }

    else if(jeu.settingschoice == 4)
    {
        sprintf(text, "PLAYER 2");
        draw_String(text, 628, 405, font);
    }


}


void updatePauseMenu(void)
{
    char nomFich[] = "save.txt";

    if (map.background != NULL)
        SDL_FreeSurface(map.background);

    map.background = loadImage("pause.png");

    if((input.clavierdown == 1 || input.sourisdown == 1) && jeu.onMenu != 4 )
    {
        if(jeu.pausechoice == 0 || jeu.pausechoice == 1 || jeu.pausechoice == 2)
        {
            jeu.pausechoice++;
            Sound(BUTTON);
        }

        input.clavierdown = 0;
        input.sourisdown=0;

    }

    if((input.clavierup == 1 || input.sourisup == 1) && jeu.onMenu != 4)
    {
        if(jeu.pausechoice == 1 || jeu.pausechoice == 2 || jeu.pausechoice == 3)
        {
            jeu.pausechoice--;
            Sound(BUTTON);
        }

        input.clavierup = 0;
        input.sourisup = 0;
    }

    if(input.clavierright == 1 && jeu.onMenu == 4)
    {
        if(jeu.savechoice == 0)
        {
            jeu.savechoice++;
            Sound(BUTTON);
        }

        input.clavierright = 0;
    }

    if(input.clavierleft == 1 && jeu.onMenu == 4)
    {
        if(jeu.savechoice == 1)
        {
            jeu.savechoice--;
            Sound(BUTTON);
        }

        input.clavierleft = 0;
    }


    if(input.clavierenter && jeu.onMenu != 4)
    {
        if (jeu.pausechoice == 0)
        {
            jeu.onMenu = 0;
            if (map.background != NULL)
                SDL_FreeSurface(map.background);

            map.background = loadImage("background1.png");
        }

        else if (jeu.pausechoice == 1 )
        {
            if(Mix_PausedMusic() == 1)
                Mix_ResumeMusic();

        }

        else if (jeu.pausechoice == 2)
        {
            if(Mix_PausedMusic() != 1)
                Mix_PauseMusic();
        }

        else if (jeu.pausechoice == 3)
        {
            jeu.onMenu = 4;
        }

        input.clavierenter = 0;

    }

    if(input.clavierenter == 1 && jeu.onMenu == 4)
    {
        if (jeu.savechoice == 0)
        {
            save(player,jeu, map ,nomFich);
            exit(0);
        }

        else if (jeu.savechoice == 1)
            exit(0);


        input.clavierenter = 0;

    }



}



void afficherpause(void)
{
    char text[200];

    if(jeu.pausechoice != 0)
    {
        sprintf(text, "RESUME");
        drawString(text, 530, 100, font);
    }

    if(jeu.pausechoice != 1)
    {
        sprintf(text, "SOUND ON");
        drawString(text, 520, 175, font);
    }

    if(jeu.pausechoice != 2)
    {
        sprintf(text, "SOUND OFF");
        drawString(text, 515, 250, font);
    }

    if(jeu.pausechoice != 3)
    {
        sprintf(text, "QUIT");
        drawString(text, 555, 325, font);
    }


    if(jeu.pausechoice == 0)
    {
        sprintf(text, "RESUME");
        draw_String(text, 530, 100, font);
    }

    if(jeu.pausechoice == 1)
    {
        sprintf(text, "SOUND ON");
        draw_String(text, 520, 175, font);
    }

    else if(jeu.pausechoice == 2)
    {
        sprintf(text, "SOUND OFF");
        draw_String(text, 515, 250, font);
    }

    else if(jeu.pausechoice == 3)
    {
        sprintf(text, "QUIT");
        draw_String(text, 555, 325, font);
    }


}


void affichermenu2(void)
{
    char text[200];

    if(jeu.menuchoice != 0)
    {
        sprintf(text, "NEW GAME");
        drawString(text, 300, 220, font);
    }

    if(jeu.menuchoice != 1)
    {
        sprintf(text, "LOAD GAME");
        drawString(text, 700, 220, font);
    }

    if(jeu.menuchoice == 0)
    {
        sprintf(text, "NEW GAME");
        draw_String(text, 300, 220, font);
    }

    if(jeu.menuchoice == 1)
    {
        sprintf(text, "LOAD GAME");
        draw_String(text, 700, 220, font);
    }
}

void afficherexit(void)
{
    char text[200];

    sprintf(text, "SAVE THE CHANGES ?");
    drawString(text, 410, 130, font);

    if(jeu.savechoice != 0)
    {
        sprintf(text, "YES");
        drawString(text, 460, 220, font);
    }

    if(jeu.savechoice != 1)
    {
        sprintf(text, "NO");
        drawString(text, 615, 220, font);
    }

    if(jeu.savechoice == 0)
    {
        sprintf(text, "YES");
        draw_String(text, 460, 220, font);
    }

    if(jeu.savechoice == 1)
    {
        sprintf(text, "NO");
        draw_String(text, 615, 220, font);
    }
}

