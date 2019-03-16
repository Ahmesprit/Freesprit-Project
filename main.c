#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "background.h"
#include "collision.h"
#include "object.h"
#include "management.h"
#include "mouvement.h"
#include "character.h"
#include "enigme.h"
#include "enemy.h"
int main(){
menuComponents mc;
menuPosComponents mpc;
SDL_Surface *screen;
Mix_Music * music;
char pause;
SDL_Event event;
int done=0;
	SDL_Rect positionpers,positionennemi;
	 SDL_Surface *background = NULL;
	 double d,d1;
    STATE S=WAITING;
	positionpers.x=638;
    positionpers.y=338;
    positionennemi.x=700;
    positionennemi.y=338;
	  SDL_Surface *ennemi=NULL;
	
	
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initializeSDL:%s \n",SDL_GetError());
	return 1;
}
screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
	printf("No sounds %s\n",Mix_GetError());
        return 1;
}

playmu();
initMenu(&mc, &mpc);
showMenu(mc, mpc, screen);
while (done == 0){
 while(SDL_PollEvent(&event) == 1){
    switch(event.type){
           case SDL_KEYDOWN:
             if(event.key.keysym.sym == SDLK_UP){
                 done = 1;
             }
           break;
           case SDL_MOUSEMOTION:
                if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 220) && (event.motion.y <= 240))) {
mpc.posbutgame.w=mc.butgame2->w;
mpc.posbutgame.h=mc.butgame2->h;
SDL_BlitSurface(mc.back,NULL,screen,&mpc.posback);
SDL_BlitSurface(mc.butsettings,NULL,screen,&mpc.posbutsettings);
SDL_BlitSurface(mc.butshop,NULL,screen,&mpc.posbutshop);
SDL_BlitSurface(mc.butcredits,NULL,screen,&mpc.posbutcredits);
SDL_BlitSurface(mc.butquit,NULL,screen,&mpc.posbutquit);
SDL_BlitSurface(mc.buthelp,NULL,screen,&mpc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,screen,&mpc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,screen,&mpc.posbutsound);
                    SDL_BlitSurface(mc.butgame2,NULL,screen,&mpc.posbutgame);
                    SDL_Flip(screen);
                 }else{
                 
if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 270) && (event.motion.y <= 300))) {
mpc.posbutsettings.w=mc.butsettings2->w;
mpc.posbutsettings.h=mc.butsettings2->h;
SDL_BlitSurface(mc.back,NULL,screen,&mpc.posback);
SDL_BlitSurface(mc.butgame,NULL,screen,&mpc.posbutgame);
SDL_BlitSurface(mc.butshop,NULL,screen,&mpc.posbutshop);
SDL_BlitSurface(mc.butcredits,NULL,screen,&mpc.posbutcredits);
SDL_BlitSurface(mc.butquit,NULL,screen,&mpc.posbutquit);
SDL_BlitSurface(mc.buthelp,NULL,screen,&mpc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,screen,&mpc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,screen,&mpc.posbutsound);
                    SDL_BlitSurface(mc.butsettings2,NULL,screen,&mpc.posbutsettings);
                    SDL_Flip(screen);
                 }else{
if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 320) && (event.motion.y <= 350))) {
mpc.posbutshop.w=mc.butshop2->w;
mpc.posbutshop.h=mc.butshop2->h;
SDL_BlitSurface(mc.back,NULL,screen,&mpc.posback);
SDL_BlitSurface(mc.butgame,NULL,screen,&mpc.posbutgame);
SDL_BlitSurface(mc.butsettings,NULL,screen,&mpc.posbutsettings);
SDL_BlitSurface(mc.butcredits,NULL,screen,&mpc.posbutcredits);
SDL_BlitSurface(mc.butquit,NULL,screen,&mpc.posbutquit);
SDL_BlitSurface(mc.buthelp,NULL,screen,&mpc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,screen,&mpc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,screen,&mpc.posbutsound);
                    SDL_BlitSurface(mc.butshop2,NULL,screen,&mpc.posbutshop);
                    SDL_Flip(screen);
                 }else{
                   if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 370) && (event.motion.y <= 400))) {
mpc.posbutcredits.w=mc.butcredits2->w;
mpc.posbutcredits.h=mc.butcredits2->h;
SDL_BlitSurface(mc.back,NULL,screen,&mpc.posback);
SDL_BlitSurface(mc.butgame,NULL,screen,&mpc.posbutgame);
SDL_BlitSurface(mc.butsettings,NULL,screen,&mpc.posbutsettings);
SDL_BlitSurface(mc.butshop,NULL,screen,&mpc.posbutshop);
SDL_BlitSurface(mc.butquit,NULL,screen,&mpc.posbutquit);
SDL_BlitSurface(mc.buthelp,NULL,screen,&mpc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,screen,&mpc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,screen,&mpc.posbutsound);
SDL_BlitSurface(mc.butcredits2,NULL,screen,&mpc.posbutcredits);
                    SDL_Flip(screen);
                 }else{
 if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 420) && (event.motion.y <= 450))) {
mpc.posbutquit.w=mc.butquit2->w;
mpc.posbutquit.h=mc.butquit2->h;
SDL_BlitSurface(mc.back,NULL,screen,&mpc.posback);
SDL_BlitSurface(mc.butgame,NULL,screen,&mpc.posbutgame);
SDL_BlitSurface(mc.butsettings,NULL,screen,&mpc.posbutsettings);
SDL_BlitSurface(mc.butshop,NULL,screen,&mpc.posbutshop);
SDL_BlitSurface(mc.butcredits,NULL,screen,&mpc.posbutcredits);
SDL_BlitSurface(mc.buthelp,NULL,screen,&mpc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,screen,&mpc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,screen,&mpc.posbutsound);
SDL_BlitSurface(mc.butquit2,NULL,screen,&mpc.posbutquit);
           SDL_Flip(screen);
                 }else{
mpc.posbutquit.w=mc.butquit2->w;
mpc.posbutquit.h=mc.butquit2->h;
SDL_BlitSurface(mc.back,NULL,screen,&mpc.posback);
SDL_BlitSurface(mc.butgame,NULL,screen,&mpc.posbutgame);
SDL_BlitSurface(mc.butsettings,NULL,screen,&mpc.posbutsettings);
SDL_BlitSurface(mc.butshop,NULL,screen,&mpc.posbutshop);
SDL_BlitSurface(mc.butcredits,NULL,screen,&mpc.posbutcredits);
SDL_BlitSurface(mc.buthelp,NULL,screen,&mpc.posbuthelp);
SDL_BlitSurface(mc.butquit,NULL,screen,&mpc.posbutquit);
SDL_BlitSurface(mc.butmusic,NULL,screen,&mpc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,screen,&mpc.posbutsound);
                    SDL_Flip(screen);
             
 }  
             
 }  
 }              
  }
}           

           break;
}
}
 
}
	
	
	
    ennemi = IMG_Load( "enemy.png" );
	d= abs(positionpers.x-positionennemi.x);
     d1= abs(positionpers.y-positionennemi.y);   
            if (S== WAITING && (d>=50 && d1>=50))
            {
              S = WAITING;
              UpdateEnnemi(S,&positionennemi,dir);
            }
            else if (S== WAITING && (d<50 && d1<50))
            {
              S = FIGHT;
              UpdateEnnemi(S,&positionennemi,dir);
            }
            else if (S== FIGHT && (d>=50 && d1>=50))
            {
              S = WAITING;
              UpdateEnnemi(S,&positionennemi,dir);
            }
            else if (S==FIGHT && (d<50 & d1<50))
            {
              S = FIGHT;
              UpdateEnnemi(S,&positionennemi,dir);
            }
            else if (S== WAITING && (d>=50 && d1>=50))
            {
              S = WAITING;
              UpdateEnnemi(S,&positionennemi,dir);
            }
	
apply_surface( bg.x, bg.y, background, fenetre );
        apply_surface( positionpers.x, positionpers.y, image, fenetre );
        //SDL_BlitSurface(texte, NULL, fenetre, &positiontexte);
        SDL_BlitSurface(ennemi, NULL, fenetre, &positionennemi);
	
	
SDL_FreeSurface(screen);
Mix_FreeMusic(music);
pause=getchar();
return 0;
}
