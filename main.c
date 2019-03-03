#include <stdio.h>
#include "SDL/SDL_image.h"
#include"SDL/SDL.h"
#include "SDL/SDL_mixer.h"

int main(void){
char pause;
SDL_Surface *screen;
SDL_Surface *scren;
SDL_Surface *back1;
SDL_Surface *back2;
SDL_Surface *back3;
SDL_Surface *back4;
SDL_Surface *back5;
SDL_Surface *back7;
SDL_Surface *back8;
SDL_Surface *back9;
SDL_Surface *butgame;
SDL_Surface *butsettings;
SDL_Surface *butshop;
SDL_Surface *butgame2;
SDL_Surface *butsettings2;
SDL_Surface *butshop2;
SDL_Surface *butcredits2;
SDL_Surface *butcredits;
SDL_Surface *butsound;
SDL_Surface *butmusic;
SDL_Surface *butsound2;
SDL_Surface *butmusic2;
SDL_Surface *buthelp;
SDL_Surface *butquit;
SDL_Surface *butquit2;
SDL_Rect posback;
SDL_Rect posbutgame;
SDL_Rect posbutsettings;
SDL_Rect posbutshop;
SDL_Rect posbutsound;
SDL_Rect posbutmusic;
SDL_Rect posbutcredits;
SDL_Rect posbutabout;
SDL_Rect posbuthelp;
SDL_Rect posbutquit;

SDL_Event event;
int done=0;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initializeSDL:%s \n",SDL_GetError());
	return 1;
}

screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


if (screen==NULL){	
	printf("unable to load Game %s\n",SDL_GetError());
	return 1;
}
back1 =IMG_Load("back1.png");
back2 =IMG_Load("back2.png");
back3 =IMG_Load("back3.png");
back4 =IMG_Load("back4.png");
back5 =IMG_Load("back5.png");
back7 =IMG_Load("back7.png");
back8 =IMG_Load("back8.png");
back9 =IMG_Load("back9.png");

if ((back1==NULL) || (back2==NULL) || (back3==NULL) || (back4==NULL) || (back5==NULL) ||
(back7==NULL) || (back8==NULL) || (back9==NULL)){	
	printf("unable to load background  image %s\n",SDL_GetError());
	return 1;
}
butgame=IMG_Load("play.png");
butsettings=IMG_Load("settings.png");
butshop=IMG_Load("shop.png");
butgame2=IMG_Load("play2.png");
butsettings2=IMG_Load("settings2.png");
butshop2=IMG_Load("shop2.png");
buthelp = IMG_Load("help.png");
butsound = IMG_Load("volume.png");
butsound2 = IMG_Load("volume2.png");
butcredits = IMG_Load("credits.png");
butcredits2 = IMG_Load("credits2.png");
butmusic = IMG_Load("music.png");
butmusic2 = IMG_Load("music2.png");
butquit = IMG_Load("quit.png");
butquit2 = IMG_Load("quit2.png");
if ((butgame==NULL) || (butsettings==NULL) || (butshop==NULL) || (butgame2==NULL) || (butsettings2==NULL) || (butshop2==NULL) || (buthelp==NULL) || (butsound==NULL) || (butsound2==NULL) || (butmusic==NULL) || (butmusic2==NULL) || (butquit==NULL) || (butquit2==NULL) || (butcredits==NULL) || (butcredits2==NULL)){	
	printf("unable to load button image %s\n",SDL_GetError());
	return 1;
}
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
	printf("No sounds %s\n",Mix_GetError());
        return 1;
}
Mix_Music *music;
music=Mix_LoadMUS("fatrat.mp3");
Mix_PlayMusic(music,-1);

posback.x=0;
posback.y=0;
posback.w=back1->w;
posback.h=back1->h;
posbutgame.x = 150;
posbutgame.y = 220;
posbutgame.w=butgame->w;
posbutgame.h=butgame->h;
posbutsettings.x = 150;
posbutsettings.y = 270;
posbutsettings.w=butsettings->w;
posbutsettings.h=butsettings->h;
posbutsettings.x = 150;
posbutsettings.y = 270;
posbutsettings.w=butsettings2->w;
posbutsettings.h=butsettings2->h;
posbutshop.x = 150;
posbutshop.y = 320;
posbutshop.w=butshop->w;
posbutshop.h=butshop->h;
posbutshop.x = 150;
posbutshop.y = 320;
posbutshop.w=butshop2->w;
posbutshop.h=butshop2->h;
posbutcredits.x = 150;
posbutcredits.y = 370;
posbutcredits.w=butcredits->w;
posbutcredits.h=butcredits->h;
posbutcredits.x = 150;
posbutcredits.y = 370;
posbutcredits.w=butcredits2->w;
posbutcredits.h=butcredits2->h;
posbutquit.x = 150;
posbutquit.y = 420;
posbutquit.w=butquit->w;
posbutquit.h=butquit->h;
posbutquit.x = 150;
posbutquit.y = 420;
posbutquit.w=butquit2->w;
posbutquit.h=butquit2->h;
posbuthelp.x = 910;
posbuthelp.y = 10;
posbuthelp.w=buthelp->w;
posbuthelp.h=buthelp->h;
posbutmusic.x = 910;
posbutmusic.y = 450;
posbutmusic.w=butmusic->w;
posbutmusic.h=butmusic->h;
posbutsound.x = 10;
posbutsound.y = 450;
posbutsound.w=butsound->w;
posbutsound.h=butsound->h;
SDL_BlitSurface(back1,NULL,screen,&posback);
SDL_Flip(screen);

SDL_BlitSurface(butgame,NULL,screen,&posbutgame);
SDL_BlitSurface(butsettings,NULL,screen,&posbutsettings);
SDL_BlitSurface(butshop,NULL,screen,&posbutshop);
SDL_BlitSurface(butcredits,NULL,screen,&posbutcredits);
SDL_BlitSurface(butquit,NULL,screen,&posbutquit);
SDL_BlitSurface(buthelp,NULL,screen,&posbuthelp);
SDL_BlitSurface(butmusic,NULL,screen,&posbutmusic);
SDL_BlitSurface(butsound,NULL,screen,&posbutsound);
SDL_Flip(screen);

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
posbutgame.w=butgame2->w;
posbutgame.h=butgame2->h;
SDL_BlitSurface(back1,NULL,screen,&posback);
SDL_BlitSurface(butsettings,NULL,screen,&posbutsettings);
SDL_BlitSurface(butshop,NULL,screen,&posbutshop);
SDL_BlitSurface(butcredits,NULL,screen,&posbutcredits);
SDL_BlitSurface(butquit,NULL,screen,&posbutquit);
SDL_BlitSurface(buthelp,NULL,screen,&posbuthelp);
SDL_BlitSurface(butmusic,NULL,screen,&posbutmusic);
SDL_BlitSurface(butsound,NULL,screen,&posbutsound);
                    SDL_BlitSurface(butgame2,NULL,screen,&posbutgame);
                    SDL_Flip(screen);
                 }else{
                 
if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 270) && (event.motion.y <= 300))) {
posbutsettings.w=butsettings2->w;
posbutsettings.h=butsettings2->h;
SDL_BlitSurface(back1,NULL,screen,&posback);
SDL_BlitSurface(butgame,NULL,screen,&posbutgame);
SDL_BlitSurface(butshop,NULL,screen,&posbutshop);
SDL_BlitSurface(butcredits,NULL,screen,&posbutcredits);
SDL_BlitSurface(butquit,NULL,screen,&posbutquit);
SDL_BlitSurface(buthelp,NULL,screen,&posbuthelp);
SDL_BlitSurface(butmusic,NULL,screen,&posbutmusic);
SDL_BlitSurface(butsound,NULL,screen,&posbutsound);
                    SDL_BlitSurface(butsettings2,NULL,screen,&posbutsettings);
                    SDL_Flip(screen);
                 }else{
if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 320) && (event.motion.y <= 350))) {
posbutshop.w=butshop2->w;
posbutshop.h=butshop2->h;
SDL_BlitSurface(back1,NULL,screen,&posback);
SDL_BlitSurface(butgame,NULL,screen,&posbutgame);
SDL_BlitSurface(butsettings,NULL,screen,&posbutsettings);
SDL_BlitSurface(butcredits,NULL,screen,&posbutcredits);
SDL_BlitSurface(butquit,NULL,screen,&posbutquit);
SDL_BlitSurface(buthelp,NULL,screen,&posbuthelp);
SDL_BlitSurface(butmusic,NULL,screen,&posbutmusic);
SDL_BlitSurface(butsound,NULL,screen,&posbutsound);
                    SDL_BlitSurface(butshop2,NULL,screen,&posbutshop);
                    SDL_Flip(screen);
                 }else{
                   if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 370) && (event.motion.y <= 400))) {
posbutcredits.w=butcredits2->w;
posbutcredits.h=butcredits2->h;
SDL_BlitSurface(back1,NULL,screen,&posback);
SDL_BlitSurface(butgame,NULL,screen,&posbutgame);
SDL_BlitSurface(butsettings,NULL,screen,&posbutsettings);
SDL_BlitSurface(butshop,NULL,screen,&posbutshop);
SDL_BlitSurface(butquit,NULL,screen,&posbutquit);
SDL_BlitSurface(buthelp,NULL,screen,&posbuthelp);
SDL_BlitSurface(butmusic,NULL,screen,&posbutmusic);
SDL_BlitSurface(butsound,NULL,screen,&posbutsound);
SDL_BlitSurface(butcredits2,NULL,screen,&posbutcredits);
                    SDL_Flip(screen);
                 }else{
 if(((event.motion.x <= 350) && (event.motion.x >= 150)) && ((event.motion.y >= 420) && (event.motion.y <= 450))) {
posbutquit.w=butquit2->w;
posbutquit.h=butquit2->h;
SDL_BlitSurface(back1,NULL,screen,&posback);
SDL_BlitSurface(butgame,NULL,screen,&posbutgame);
SDL_BlitSurface(butsettings,NULL,screen,&posbutsettings);
SDL_BlitSurface(butshop,NULL,screen,&posbutshop);
SDL_BlitSurface(butcredits,NULL,screen,&posbutcredits);
SDL_BlitSurface(buthelp,NULL,screen,&posbuthelp);
SDL_BlitSurface(butmusic,NULL,screen,&posbutmusic);
SDL_BlitSurface(butsound,NULL,screen,&posbutsound);
SDL_BlitSurface(butquit2,NULL,screen,&posbutquit);
           SDL_Flip(screen);
                 }else{
posbutquit.w=butquit2->w;
posbutquit.h=butquit2->h;
SDL_BlitSurface(back1,NULL,screen,&posback);
SDL_BlitSurface(butgame,NULL,screen,&posbutgame);
SDL_BlitSurface(butsettings,NULL,screen,&posbutsettings);
SDL_BlitSurface(butshop,NULL,screen,&posbutshop);
SDL_BlitSurface(butcredits,NULL,screen,&posbutcredits);
SDL_BlitSurface(buthelp,NULL,screen,&posbuthelp);
SDL_BlitSurface(butquit,NULL,screen,&posbutquit);
SDL_BlitSurface(butmusic,NULL,screen,&posbutmusic);
SDL_BlitSurface(butsound,NULL,screen,&posbutsound);
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
SDL_FreeSurface(screen);
Mix_FreeMusic(music);
pause=getchar();
return 0;
}
