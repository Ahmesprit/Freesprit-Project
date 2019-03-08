#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "background.h"

void initMenu(menuComponents * mc, menuPosComponents * mpc){
mc->back =IMG_Load("back1.png");
if (mc->back==NULL){	
	printf("unable to load background  image %s\n",SDL_GetError());
}
mc->butgame=IMG_Load("play.png");
mc->butsettings=IMG_Load("settings.png");
mc->butshop=IMG_Load("shop.png");
mc->butgame2=IMG_Load("play2.png");
mc->butsettings2=IMG_Load("settings2.png");
mc->butshop2=IMG_Load("shop2.png");
mc->buthelp = IMG_Load("help.png");
mc->butsound = IMG_Load("volume.png");
mc->butsound2 = IMG_Load("volume2.png");
mc->butcredits = IMG_Load("credits.png");
mc->butcredits2 = IMG_Load("credits2.png");
mc->butmusic = IMG_Load("music.png");
mc->butmusic2 = IMG_Load("music2.png");
mc->butquit = IMG_Load("quit.png");
mc->butquit2 = IMG_Load("quit2.png");
if ((mc->butgame==NULL) || (mc->butsettings==NULL) || (mc->butshop==NULL) || (mc->butgame2==NULL) || (mc->butsettings2==NULL) || (mc->butshop2==NULL) || (mc->buthelp==NULL) || (mc->butsound==NULL) || (mc->butsound2==NULL) || (mc->butmusic==NULL) || (mc->butmusic2==NULL) || (mc->butquit==NULL) || (mc->butquit2==NULL) || (mc->butcredits==NULL) || (mc->butcredits2==NULL)){	
	printf("unable to load button image %s\n",SDL_GetError());
}
mpc->posback.x=0;
mpc->posback.y=0;
mpc->posback.w=mc->back->w;
mpc->posback.h=mc->back->h;
mpc->posbutgame.x = 150;
mpc->posbutgame.y = 220;
mpc->posbutgame.w=mc->butgame->w;
mpc->posbutgame.h=mc->butgame->h;
mpc->posbutsettings.x = 150;
mpc->posbutsettings.y = 270;
mpc->posbutsettings.w=mc->butsettings->w;
mpc->posbutsettings.h=mc->butsettings->h;
mpc->posbutsettings.x = 150;
mpc->posbutsettings.y = 270;
mpc->posbutsettings.w=mc->butsettings2->w;
mpc->posbutsettings.h=mc->butsettings2->h;
mpc->posbutshop.x = 150;
mpc->posbutshop.y = 320;
mpc->posbutshop.w=mc->butshop->w;
mpc->posbutshop.h=mc->butshop->h;
mpc->posbutshop.x = 150;
mpc->posbutshop.y = 320;
mpc->posbutshop.w=mc->butshop2->w;
mpc->posbutshop.h=mc->butshop2->h;
mpc->posbutcredits.x = 150;
mpc->posbutcredits.y = 370;
mpc->posbutcredits.w=mc->butcredits->w;
mpc->posbutcredits.h=mc->butcredits->h;
mpc->posbutcredits.x = 150;
mpc->posbutcredits.y = 370;
mpc->posbutcredits.w=mc->butcredits2->w;
mpc->posbutcredits.h=mc->butcredits2->h;
mpc->posbutquit.x = 150;
mpc->posbutquit.y = 420;
mpc->posbutquit.w=mc->butquit->w;
mpc->posbutquit.h=mc->butquit->h;
mpc->posbutquit.x = 150;
mpc->posbutquit.y = 420;
mpc->posbutquit.w=mc->butquit2->w;
mpc->posbutquit.h=mc->butquit2->h;
mpc->posbuthelp.x = 910;
mpc->posbuthelp.y = 10;
mpc->posbuthelp.w=mc->buthelp->w;
mpc->posbuthelp.h=mc->buthelp->h;
mpc->posbutmusic.x = 910;
mpc->posbutmusic.y = 450;
mpc->posbutmusic.w=mc->butmusic->w;
mpc->posbutmusic.h=mc->butmusic->h;
mpc->posbutsound.x = 10;
mpc->posbutsound.y = 450;
mpc->posbutsound.w=mc->butsound->w;
mpc->posbutsound.h=mc->butsound->h;

}
void showMenu (menuComponents mc, menuPosComponents mpc, SDL_Surface *screen){
   SDL_BlitSurface(mc.back,NULL, screen,&mpc.posback);
SDL_BlitSurface(mc.butgame,NULL, screen,&mpc.posbutgame);
SDL_BlitSurface(mc.butsettings,NULL, screen,&mpc.posbutsettings);
SDL_BlitSurface(mc.butshop,NULL, screen,&mpc.posbutshop);
SDL_BlitSurface(mc.butcredits,NULL, screen,&mpc.posbutcredits);
SDL_BlitSurface(mc.butquit,NULL, screen,&mpc.posbutquit);
SDL_BlitSurface(mc.buthelp,NULL, screen,&mpc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL, screen,&mpc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL, screen ,&mpc.posbutsound);
SDL_Flip(screen);
}
void playmu(){
  Mix_Music *music;
music=Mix_LoadMUS("fatrat.mp3");
Mix_PlayMusic(music,-1);
}
