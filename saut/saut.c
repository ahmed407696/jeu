#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"saut.h"

void InitSprite(Sprite* Sp)
{
    /*Sp->x = 150.0f;
    Sp->y = 250.0f;*/
    Sp->status = STAT_SOL;
    Sp->vx = Sp->vy = 0.0f;
    Sp->positionPerso.x=150.0f;
     Sp->positionPerso.y=250.0f;
}


void Render(Sprite* Sp,SDL_Surface * screen)
{ 
   SDL_Rect R;//déclaration d'une variable R de type rectangle 
    R.x = (Sint16)Sp->positionPerso.x;
    R.y = (Sint16)Sp->positionPerso.y;
    R.w = 20;
    R.h = 60;
   /* SDL_FillRect(screen,&R,SDL_MapRGB(screen->format,0,255,0));//coloration du surface en vert */
      Sp->personnage = IMG_Load("1.png");
      SDL_BlitSurface(Sp->personnage, NULL, screen, &Sp->positionPerso);
  
}

void Saute(Sprite* Sp,float impulsion)
{
    Sp->vy = -impulsion;
    Sp->status = STAT_AIR;
}

void ControleSol(Sprite* Sp)
{
    if (Sp->positionPerso.y>250.0f)
    {
        Sp->positionPerso.y = 600.0f;
        if (Sp->vy>0)
            Sp->vy = 0.0f;
        Sp->status = STAT_SOL;
    }
}

void Gravite(Sprite* Sp,float factgravite,float factsautmaintenu,Uint8* keys)
{
    if (Sp->status == STAT_AIR && keys[SDLK_SPACE])
        factgravite/=factsautmaintenu;
    Sp->vy += factgravite;
}

void Evolue(Sprite* Sp,Uint8* keys)
{
    float lateralspeed = 0.5f;
    float airlateralspeedfacteur = 10.5f;
    float maxhspeed = 3.0f;
    float adherance = 1.5f;//pour le freinage et sous 1 n'a pas de sens
    float impulsion = 6.0f;
    float factgravite = 0.8f;
    float factsautmaintenu = 100.0f;
// controle lateral
    if (Sp->status == STAT_AIR) // (*2)
        lateralspeed*= airlateralspeedfacteur;
    if (keys[SDLK_LEFT]) // (*1)
        Sp->vx-=lateralspeed;
    if (keys[SDLK_RIGHT])
        Sp->vx+=lateralspeed;
    if (Sp->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
        Sp->vx/=adherance;
// limite vitesse
    if (Sp->vx>maxhspeed) // (*4)
        Sp->vx = maxhspeed;
    if (Sp->vx<-maxhspeed)
        Sp->vx = -maxhspeed;
// saut
    if (keys[SDLK_SPACE] && Sp->status == STAT_SOL)
        Saute(Sp,impulsion);
    Gravite(Sp,factgravite,factsautmaintenu,keys);
    ControleSol(Sp);
// application du vecteur à la position.
    Sp->positionPerso.x +=Sp->vx;
    Sp->positionPerso.y+=Sp->vy;
}
