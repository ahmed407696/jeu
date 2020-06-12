
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"saut.h"
int main(int argc,char** argv)
{
    SDL_Surface* screen;
    int numkeys;
    Uint8 * keys;
    Sprite S;
    Uint32 timer,elapsed;
    SDL_Init(SDL_INIT_VIDEO);
    screen=SDL_SetVideoMode(800,600,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
    InitSprite(&S);
    do 
    {
        timer = SDL_GetTicks();
        SDL_FillRect(screen,NULL,0);
        SDL_PumpEvents();
        keys = SDL_GetKeyState(&numkeys);
        Evolue(&S,keys);
        Render(&S,screen);
        SDL_Flip(screen);
        elapsed = SDL_GetTicks() - timer;
        if (elapsed<40)
            SDL_Delay(60-elapsed);
    } while (!keys[SDLK_ESCAPE]);
    SDL_Quit();
    return 0;
}
