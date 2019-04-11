#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"animChar.h"
SDL_Event event;
SDL_Rect rect,rect2,rect3,rect4,back;
SDL_Surface *screen,*rectangle,*rectangle4; 
SDL_Surface *background = NULL;
  
  void setrects(SDL_Rect* clip){
clip[0].x=0;
clip[0].y=0;
clip[0].w=114;
clip[0].h=160;

clip[1].x=114;
clip[1].y=0;
clip[1].w=114;
clip[1].h=160;

clip[2].x=228;
clip[2].y=0;
clip[2].w=114;
clip[2].h=160;

clip[3].x=342;
clip[3].y=0;
clip[3].w=114;
clip[3].h=160;

clip[4].x=456;
clip[4].y=0;
clip[4].w=114;
clip[4].h=160;

clip[5].x=570;
clip[5].y=0;
clip[5].w=114;
clip[5].h=160;

clip[6].x=684;
clip[6].y=0;
clip[6].w=114;
clip[6].h=160;

clip[7].x=798;
clip[7].y=0;
clip[7].w=114;
clip[7].h=160;


}
void inputInit(void)
{
      SDL_EnableUNICODE(1);
 
         SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,
       SDL_DEFAULT_REPEAT_INTERVAL+50);
       }
 
void apply_surface (int x,int y, SDL_Surface* source, SDL_Surface* destination)
 
{    SDL_Rect  offset;
     offset.x = x;
     offset.y = y;

 
     SDL_BlitSurface (source, NULL, destination, &offset);
 
 
     }
 
 
void affichage()
{    
      SDL_FillRect(screen, NULL, 0);
      rect.x= (screen->w /2) -(rect.w/ 2);
      rect.y= (screen->h /2) -(rect.h/ 2);
      rect.w= screen ->w /2;
      rect.h= screen -> h /2; 
 
 
 
     rect.x =rect.x - 50;
     rect.y =rect.y - 100;
 
 
     rect4.x =rect.x +200;
     rect4.y =rect.y;
 
     SDL_BlitSurface(rectangle,NULL,screen,&rect);
     SDL_BlitSurface(rectangle4,NULL,screen,&rect4);
 
 
     }
 
 
      
 
 
 


