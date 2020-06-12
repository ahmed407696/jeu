/**
* @file saut.h
*/
#ifndef SAUT_H_DEFINED
#define SAUT_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
/*#ifdef WIN32
#pragma comment(lib,"sdl.lib")
#pragma comment(lib,"sdlmain.lib")
#endif*/

#define STAT_SOL 0
#define STAT_AIR 1
/**
* @struct sprite
* @brief struct for sprite
*/
typedef struct
{   SDL_Rect positionPerso;SDL_Surface *personnage;
    int status;
    //float x,y;
    float vx,vy;//vecteur vitesse instantanée du sprite
    
} Sprite;

void InitSprite(Sprite* Sp);
void Saute(Sprite* Sp,float impulsion);
void ControleSol(Sprite* Sp);
void Render(Sprite* Sp,SDL_Surface * screen);
void Gravite(Sprite* Sp,float factgravite,float factsautmaintenu,Uint8* keys);
void Evolue(Sprite* Sp,Uint8* keys);

#endif
