/**
* @file main.c
* @brief Afficher et initialiser Bckg
* @author Unisix
* @version 0.1
* @date Apr 23, 2019
*
* afficher backg 
*
*/
#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "jeux.h"

void pause() ;

int main()
{
int continuer=1;
SDL_Surface *screen= NULL;
SDL_Surface *imagedefond =NULL;
SDL_Rect image ;
int x,y;
SDL_Init(SDL_INIT_VIDEO);

screen=SDL_SetVideoMode(1920,768,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 if(screen==NULL){
printf("unable = %s\n",SDL_GetError());
return 1;
}
  x=0;
  y=0;
    
imagedefond=Init_imagedefond( imagedefond ,&image , x , y );


SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
SDL_BlitSurface(imagedefond,NULL, screen,&image) ;
SDL_Flip(screen);
pause() ;


SDL_FreeSurface(imagedefond); 
 
  SDL_Quit();
return 0;
}

void pause()
{
 int continuer = 1 ;
 SDL_Event event ;

 while(continuer)
  {
   SDL_WaitEvent(&event) ;
   switch(event.type)
   {
    case SDL_QUIT :
        continuer=0 ;
        break ;
   }
  }
}