#include <stdio.h>
#include "SDL/SDL_image.h"
#include"SDL/SDL.h"
#include "SDL/SDL_mixer.h"

int main(void){
char pause;
SDL_Surface *screen;
SDL_Surface *image;
SDL_Surface *pers;
SDL_Surface *butgame;
SDL_Surface *butsettings;
SDL_Surface *butshop;
SDL_Surface *butgame2;
SDL_Surface *butsettings2;
SDL_Surface *butshop2;
SDL_Surface *texture;
SDL_Rect positionecran;
SDL_Rect positiongamebut;
SDL_Rect positionsetbut;
SDL_Rect positionshopbut;
SDL_Rect positiontext;
SDL_Event event;
int done=0;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initializeSDL:%s \n",SDL_GetError());
	return 1;
}

screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


if (screen==NULL){	
	printf("unable to load bitmap %s\n",SDL_GetError());
	return 1;
}
image=IMG_Load("kkkk.png");
if (image==NULL){	
	printf("unable to load background  image %s\n",SDL_GetError());
	return 1;
}
butgame = IMG_Load("butgame.png");
butsettings =IMG_Load("settings-button.png");
butshop=IMG_Load("shop-button.png");
butgame2=IMG_Load("gamebutton2.png");
butsettings2=IMG_Load("settingsbutton2.png");
butshop2=IMG_Load("shopbutton2.png");
texture=IMG_Load("Texture.png");
if ((butgame==NULL) || (butsettings==NULL) || (butshop==NULL) || (butgame2==NULL) || (butsettings2==NULL)  || (butshop2==NULL) || (texture==NULL)){	
	printf("unable to load button image %s\n",SDL_GetError());
	return 1;
}
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
	printf("%s\n",Mix_GetError());
}
Mix_Music *music;
music=Mix_LoadMUS("fatrat.mp3");
Mix_PlayMusic(music,-1);

positionecran.x=0;
positionecran.y=0;
positionecran.w=image->w;
positionecran.h=image->h;
positiongamebut.x=400;
positiongamebut.y=200;
positiongamebut.w=butgame->w;
positiongamebut.h=butgame->h;
positionsetbut.x=400;
positionsetbut.y=350;
positionsetbut.w=butsettings->w;
positionsetbut.h=butsettings->h;
positionshopbut.x=400;
positionshopbut.y=500;
positionshopbut.w=butshop->w;
positionshopbut.h=butshop->h;
positiontext.x=75;
positiontext.y=20;
positiontext.w=texture->w;
positiontext.h=texture->h;

SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_Flip(screen);
SDL_BlitSurface(butgame,NULL,screen,&positiongamebut);
SDL_Flip(screen);
SDL_BlitSurface(butsettings,NULL,screen,&positionsetbut);
SDL_Flip(screen);
SDL_BlitSurface(butshop,NULL,screen,&positionshopbut);
SDL_Flip(screen);
SDL_BlitSurface(texture,NULL,screen,&positiontext);
SDL_Flip(screen);

SDL_FreeSurface(image);
Mix_FreeMusic(music);
pause = getchar();
return 0;
}

