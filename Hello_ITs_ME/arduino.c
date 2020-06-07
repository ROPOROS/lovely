/**
* @file arduino.c
* @brief arduino libs
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

#include "arduino.h"

int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;
    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);
    fprintf(f,"%d",x);
    fclose(f);
    return(0);
}

int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");
    if(f == NULL)
        return(-1);
    fscanf(f,"%d",x);
    fclose(f);
    return(0);
}
