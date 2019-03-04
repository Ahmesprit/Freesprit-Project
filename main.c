#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "init.h"
#include "affichage.h"

int main(){
menuComponents mc;
rectMenuComponents rmc;
char pause;
SDL_Event event;
int done=0;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initializeSDL:%s \n",SDL_GetError());
	return 1;
}

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
	printf("No sounds %s\n",Mix_GetError());
        return 1;
}
Mix_Music *music;
music=Mix_LoadMUS("fatrat.mp3");
Mix_PlayMusic(music,-1);

mc=initMenu();
showMenu(mc, &rmc);
while (done == 0){
 while(SDL_PollEvent(&event) == 1){
    switch(event.type){
           case SDL_KEYDOWN:
             if(event.key.keysym.sym == SDLK_UP){
                 done = 1;
             }
           break;
           case SDL_MOUSEMOTION:
printf("mouse event is %d, %d\n", event.motion.x, event.motion.y);
                if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 220) && (event.motion.y <= 240))) {
rmc.posbutgame.w=mc.butgame2->w;
rmc.posbutgame.h=mc.butgame2->h;
SDL_BlitSurface(mc.back1,NULL,mc.screen,&rmc.posback);
SDL_BlitSurface(mc.butsettings,NULL,mc.screen,&rmc.posbutsettings);
SDL_BlitSurface(mc.butshop,NULL,mc.screen,&rmc.posbutshop);
SDL_BlitSurface(mc.butcredits,NULL,mc.screen,&rmc.posbutcredits);
SDL_BlitSurface(mc.butquit,NULL,mc.screen,&rmc.posbutquit);
SDL_BlitSurface(mc.buthelp,NULL,mc.screen,&rmc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,mc.screen,&rmc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,mc.screen,&rmc.posbutsound);
                    SDL_BlitSurface(mc.butgame2,NULL,mc.screen,&rmc.posbutgame);
                    SDL_Flip(mc.screen);
                 }else{
                 
if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 270) && (event.motion.y <= 300))) {
rmc.posbutsettings.w=mc.butsettings2->w;
rmc.posbutsettings.h=mc.butsettings2->h;
SDL_BlitSurface(mc.back1,NULL,mc.screen,&rmc.posback);
SDL_BlitSurface(mc.butgame,NULL,mc.screen,&rmc.posbutgame);
SDL_BlitSurface(mc.butshop,NULL,mc.screen,&rmc.posbutshop);
SDL_BlitSurface(mc.butcredits,NULL,mc.screen,&rmc.posbutcredits);
SDL_BlitSurface(mc.butquit,NULL,mc.screen,&rmc.posbutquit);
SDL_BlitSurface(mc.buthelp,NULL,mc.screen,&rmc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,mc.screen,&rmc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,mc.screen,&rmc.posbutsound);
                    SDL_BlitSurface(mc.butsettings2,NULL,mc.screen,&rmc.posbutsettings);
                    SDL_Flip(mc.screen);
                 }else{
if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 320) && (event.motion.y <= 350))) {
rmc.posbutshop.w=mc.butshop2->w;
rmc.posbutshop.h=mc.butshop2->h;
SDL_BlitSurface(mc.back1,NULL,mc.screen,&rmc.posback);
SDL_BlitSurface(mc.butgame,NULL,mc.screen,&rmc.posbutgame);
SDL_BlitSurface(mc.butsettings,NULL,mc.screen,&rmc.posbutsettings);
SDL_BlitSurface(mc.butcredits,NULL,mc.screen,&rmc.posbutcredits);
SDL_BlitSurface(mc.butquit,NULL,mc.screen,&rmc.posbutquit);
SDL_BlitSurface(mc.buthelp,NULL,mc.screen,&rmc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,mc.screen,&rmc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,mc.screen,&rmc.posbutsound);
                    SDL_BlitSurface(mc.butshop2,NULL,mc.screen,&rmc.posbutshop);
                    SDL_Flip(mc.screen);
                 }else{
                   if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 370) && (event.motion.y <= 400))) {
rmc.posbutcredits.w=mc.butcredits2->w;
rmc.posbutcredits.h=mc.butcredits2->h;
SDL_BlitSurface(mc.back1,NULL,mc.screen,&rmc.posback);
SDL_BlitSurface(mc.butgame,NULL,mc.screen,&rmc.posbutgame);
SDL_BlitSurface(mc.butsettings,NULL,mc.screen,&rmc.posbutsettings);
SDL_BlitSurface(mc.butshop,NULL,mc.screen,&rmc.posbutshop);
SDL_BlitSurface(mc.butquit,NULL,mc.screen,&rmc.posbutquit);
SDL_BlitSurface(mc.buthelp,NULL,mc.screen,&rmc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,mc.screen,&rmc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,mc.screen,&rmc.posbutsound);
SDL_BlitSurface(mc.butcredits2,NULL,mc.screen,&rmc.posbutcredits);
                    SDL_Flip(mc.screen);
                 }else{
 if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 420) && (event.motion.y <= 450))) {
rmc.posbutquit.w=mc.butquit2->w;
rmc.posbutquit.h=mc.butquit2->h;
SDL_BlitSurface(mc.back1,NULL,mc.screen,&rmc.posback);
SDL_BlitSurface(mc.butgame,NULL,mc.screen,&rmc.posbutgame);
SDL_BlitSurface(mc.butsettings,NULL,mc.screen,&rmc.posbutsettings);
SDL_BlitSurface(mc.butshop,NULL,mc.screen,&rmc.posbutshop);
SDL_BlitSurface(mc.butcredits,NULL,mc.screen,&rmc.posbutcredits);
SDL_BlitSurface(mc.buthelp,NULL,mc.screen,&rmc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,mc.screen,&rmc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,mc.screen,&rmc.posbutsound);
SDL_BlitSurface(mc.butquit2,NULL,mc.screen,&rmc.posbutquit);
           SDL_Flip(mc.screen);
                 }else{
rmc.posbutquit.w=mc.butquit2->w;
rmc.posbutquit.h=mc.butquit2->h;
SDL_BlitSurface(mc.back1,NULL,mc.screen,&rmc.posback);
SDL_BlitSurface(mc.butgame,NULL,mc.screen,&rmc.posbutgame);
SDL_BlitSurface(mc.butsettings,NULL,mc.screen,&rmc.posbutsettings);
SDL_BlitSurface(mc.butshop,NULL,mc.screen,&rmc.posbutshop);
SDL_BlitSurface(mc.butcredits,NULL,mc.screen,&rmc.posbutcredits);
SDL_BlitSurface(mc.buthelp,NULL,mc.screen,&rmc.posbuthelp);
SDL_BlitSurface(mc.butquit,NULL,mc.screen,&rmc.posbutquit);
SDL_BlitSurface(mc.butmusic,NULL,mc.screen,&rmc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,mc.screen,&rmc.posbutsound);
                    SDL_Flip(mc.screen);
             
 }  
             
 }  
 }              
  }
}           

           break;
}
}
 
}
SDL_FreeSurface(mc.screen);
Mix_FreeMusic(music);
pause=getchar();
return 0;
}
