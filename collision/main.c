#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "utility.h"

int main()
{
SDL_Surface *screen,*back1,*back2,*back3 ; 
SDL_Rect perso;
SDL_Event event ; 
int done=0 , x,xx=0 ; 
perso.x=360;
perso.y=200;

 if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode ( 7500 ,  800 ,  32 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     }
back1=IMG_Load( "map.png" );
back2=IMG_Load( "map1.png" );
back3=IMG_Load( "C.png" );
SDL_BlitSurface ( back2,  NULL ,  screen , NULL );

SDL_BlitSurface ( back1,  NULL ,  screen , NULL );
SDL_BlitSurface ( back3,  NULL ,  screen , &perso );

SDL_Flip ( screen ); 
   
   SDL_EnableKeyRepeat(10,10) ; 
    while  ( done==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 done  =  1 ; 
                 break ;  
    case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {
      case SDLK_ESCAPE : 
done=1 ; 

case SDLK_LEFT : 

perso.x-=10 ; 
xx=detectCollPP(back2,perso) ;
if(xx==1)
{
perso.x+=10;
printf("hello");
}
SDL_BlitSurface ( back2,  NULL ,  screen , NULL );

SDL_BlitSurface ( back1,  NULL ,  screen , NULL );
SDL_BlitSurface ( back3,  NULL ,  screen , &perso );

SDL_Flip ( screen ); 

break ; 

case SDLK_RIGHT : 
perso.x+=30 ;
xx=detectCollPP (back2,perso) ;
if(xx==1)
{
perso.x-=30;
}

SDL_BlitSurface ( back2,  NULL ,  screen , NULL );

SDL_BlitSurface ( back1,  NULL ,  screen , NULL );
SDL_BlitSurface ( back3,  NULL ,  screen , &perso );

SDL_Flip ( screen ); 

break ; 
case SDLK_UP : 

perso.y-=10 ; 
xx=detectCollPP (back2,perso) ;
if(xx==1)
{
perso.y+=10;
}
x=detectCollPP (back2,perso) ;
SDL_BlitSurface ( back2,  NULL ,  screen , NULL );

SDL_BlitSurface ( back1,  NULL ,  screen , NULL );
SDL_BlitSurface ( back3,  NULL ,  screen , &perso );

SDL_Flip ( screen ); 

break ; 
case SDLK_DOWN : 

perso.y+=10 ;
xx=detectCollPP (back2,perso) ;
if(xx==1)
{
perso.y-=10;
}

SDL_BlitSurface ( back2,  NULL ,  screen , NULL );

SDL_BlitSurface ( back1,  NULL ,  screen , NULL );
SDL_BlitSurface ( back3,  NULL ,  screen , &perso );

SDL_Flip ( screen ); 

break ; 


                 
			 }


if(x==1) 
{
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));
SDL_Flip(screen) ; 
}
break ; 

		 }
	 }


}
return 0 ; 
}
