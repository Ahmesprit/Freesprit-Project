#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "background.h"

void initMenu(menuComponents * mc, menuPosComponents * mpc){
mc->back =IMG_Load("Resources/back1.png");
if (mc->back==NULL){
	printf("unable to load background  image %s\n",SDL_GetError());
}
mc->butgame=IMG_Load("Resources/play.png");
mc->butsettings=IMG_Load("Resources/settings.png");
mc->butshop=IMG_Load("Resources/shop.png");
mc->butgame2=IMG_Load("Resources/play2.png");
mc->butsettings2=IMG_Load("Resources/settings2.png");
mc->butshop2=IMG_Load("Resources/shop2.png");
mc->buthelp = IMG_Load("Resources/help.png");
mc->butsound = IMG_Load("Resources/volume.png");
mc->butsound2 = IMG_Load("Resources/volume2.png");
mc->butcredits = IMG_Load("Resources/credits.png");
mc->butcredits2 = IMG_Load("Resources/credits2.png");
mc->butmusic = IMG_Load("Resources/music.png");
mc->butmusic2 = IMG_Load("Resources/music2.png");
mc->butquit = IMG_Load("Resources/quit.png");
mc->butquit2 = IMG_Load("Resources/quit2.png");
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
mpc->posbutmusic.y = 570;
mpc->posbutmusic.w=mc->butmusic->w;
mpc->posbutmusic.h=mc->butmusic->h;
mpc->posbutsound.x = 10;
mpc->posbutsound.y = 570;
mpc->posbutsound.w=mc->butsound->w;
mpc->posbutsound.h=mc->butsound->h;

}
void showMenu (menuComponents *mc, menuPosComponents *mpc, SDL_Surface *screen, butControl bc){
   SDL_BlitSurface(mc->back,NULL, screen,&mpc->posback);
SDL_BlitSurface(mc->butgame,NULL, screen,&mpc->posbutgame);
SDL_BlitSurface(mc->butsettings,NULL, screen,&mpc->posbutsettings);
SDL_BlitSurface(mc->butshop,NULL, screen,&mpc->posbutshop);
SDL_BlitSurface(mc->butcredits,NULL, screen,&mpc->posbutcredits);
SDL_BlitSurface(mc->butquit,NULL, screen,&mpc->posbutquit);
SDL_BlitSurface(mc->buthelp,NULL, screen,&mpc->posbuthelp);
if(bc.music == 0){
SDL_BlitSurface(mc->butmusic,NULL,screen,&mpc->posbutmusic);
}else{
SDL_BlitSurface(mc->butmusic2,NULL,screen,&mpc->posbutmusic);
}
if(bc.sound== 0){
SDL_BlitSurface(mc->butsound,NULL,screen,&mpc->posbutsound);
}else{
SDL_BlitSurface(mc->butsound2,NULL,screen,&mpc->posbutsound);
}

SDL_Flip(screen);
}
void initSound(Mix_Music **music, soundClicks *sc){
    *music = Mix_LoadMUS("Resources/main-theme.mp3");
    sc->butHover = Mix_LoadWAV("Resources/mouseh.wav");
    sc->butClick = Mix_LoadWAV("Resources/mousec.wav");
}

void menuMotion(menuComponents  *mc, menuPosComponents *mpc, SDL_Surface *screen, SDL_Event *event, butControl bc,soundClicks *sc, int soundHoverStopFlag){
static int played = 0;
  if(((event->motion.x <= mpc->posbutgame.x + mc->butgame->w) && (event->motion.x >= mpc->posbutgame.x)) && ((event->motion.y >= mpc->posbutgame.y) && (event->motion.y <= mpc->posbutgame.y + mc->butgame->h))) {
if(soundHoverStopFlag == 0){
if(played == 0){
Mix_PlayChannel(-1, sc->butHover, 0);
played = 1;
}
}
mpc->posbutgame.w=mc->butgame2->w;
mpc->posbutgame.h=mc->butgame2->h;
  SDL_BlitSurface(mc->butgame2,NULL,screen,&mpc->posbutgame);
  SDL_Flip(screen);
                 }else{
if(((event->motion.x <= mpc->posbutsettings.x + mc->butsettings->w) && (event->motion.x >= mpc->posbutsettings.x)) && ((event->motion.y >= mpc->posbutsettings.y) && (event->motion.y <= mpc->posbutsettings.y + mc->butsettings->h))) {
if(soundHoverStopFlag == 0){
if(played == 0){
Mix_PlayChannel(-1, sc->butHover, 0);
played =1;
}
}
mpc->posbutsettings.w=mc->butsettings2->w;
mpc->posbutsettings.h=mc->butsettings2->h;
                    SDL_BlitSurface(mc->butsettings2,NULL,screen,&mpc->posbutsettings);
                    SDL_Flip(screen);
                 }else{
if(((event->motion.x <= mpc->posbutshop.x + mc->butshop->w) && (event->motion.x >= mpc->posbutshop.x)) && ((event->motion.y >= mpc->posbutshop.y) && (event->motion.y <= mpc->posbutshop.y + mc->butshop->h))) {
if(soundHoverStopFlag == 0){
if(played == 0){
Mix_PlayChannel(-1, sc->butHover, 0);
played =1;
}
}
mpc->posbutshop.w=mc->butshop2->w;
mpc->posbutshop.h=mc->butshop2->h;
                    SDL_BlitSurface(mc->butshop2,NULL,screen,&mpc->posbutshop);
                    SDL_Flip(screen);
                 }else{
                   if(((event->motion.x <= mpc->posbutcredits.x + mc->butcredits->w) && (event->motion.x >= mpc->posbutcredits.x)) && ((event->motion.y >= mpc->posbutcredits.y) && (event->motion.y <= mpc->posbutcredits.y + mc->butcredits->h)))  {
if(soundHoverStopFlag == 0){
if(played == 0){
Mix_PlayChannel(-1, sc->butHover, 0);
played =1;
}
}
mpc->posbutcredits.w=mc->butcredits2->w;
mpc->posbutcredits.h=mc->butcredits2->h;
SDL_BlitSurface(mc->butcredits2,NULL,screen,&mpc->posbutcredits);
                    SDL_Flip(screen);
                 }else{
 if(((event->motion.x <= mpc->posbutquit.x + mc->butquit->w) && (event->motion.x >= mpc->posbutquit.x)) && ((event->motion.y >= mpc->posbutquit.y) && (event->motion.y <= mpc->posbutquit.y + mc->butquit->h))) {
if(soundHoverStopFlag == 0){
if(played == 0){
Mix_PlayChannel(-1, sc->butHover, 0);
played =1;
}
}
mpc->posbutquit.w=mc->butquit2->w;
mpc->posbutquit.h=mc->butquit2->h;
SDL_BlitSurface(mc->butquit2,NULL,screen,&mpc->posbutquit);
           SDL_Flip(screen);
				 }

 }
 }
  }
}
}
backgroundMaps initMaps(){
backgroundMaps bm;
   bm.map = IMG_Load("Resources/backstage1.jpg");
   if(bm.map == NULL){
      printf("enable to load first map\n");
    }
   bm.posMap.x=0;
bm.posMap.y=0;
bm.posMap.w=bm.map->w;
bm.posMap.h=bm.map->h;
 return bm;
}
void menuClicks(menuComponents  *mc, menuPosComponents *mpc, SDL_Surface *screen, SDL_Event *event, Mix_Music *music, soundClicks *sc, butControl *bc, int *soundHoverStopFlag, char pickFromMenu[]){
static int pressed = 0;
         if((((event->button.x <= mpc->posbutsound.x + mc->butsound->w) && (event->button.x >= mpc->posbutsound.x)) && ((event->button.y >= mpc->posbutsound.y) && (event->button.y <= mpc->posbutsound.y + mc->butsound->h))) && (bc->sound == 0)) {
         //flip button
    bc->sound = 1;
    mpc->posbutsound.w=mc->butsound2->w;
mpc->posbutsound.h=mc->butsound2->h;
if(bc->music == 0){
SDL_BlitSurface(mc->back,NULL,screen,&mpc->posback);
SDL_BlitSurface(mc->butgame,NULL,screen,&mpc->posbutgame);
SDL_BlitSurface(mc->butsettings,NULL,screen,&mpc->posbutsettings);
SDL_BlitSurface(mc->butshop,NULL,screen,&mpc->posbutshop);
SDL_BlitSurface(mc->butcredits,NULL,screen,&mpc->posbutcredits);
SDL_BlitSurface(mc->buthelp,NULL,screen,&mpc->posbuthelp);
SDL_BlitSurface(mc->butquit,NULL,screen,&mpc->posbutquit);
SDL_BlitSurface(mc->butmusic,NULL,screen,&mpc->posbutmusic);
SDL_BlitSurface(mc->butsound2,NULL,screen,&mpc->posbutsound);
                    SDL_Flip(screen);
}else{
SDL_BlitSurface(mc->back,NULL,screen,&mpc->posback);
SDL_BlitSurface(mc->butgame,NULL,screen,&mpc->posbutgame);
SDL_BlitSurface(mc->butsettings,NULL,screen,&mpc->posbutsettings);
SDL_BlitSurface(mc->butshop,NULL,screen,&mpc->posbutshop);
SDL_BlitSurface(mc->butcredits,NULL,screen,&mpc->posbutcredits);
SDL_BlitSurface(mc->buthelp,NULL,screen,&mpc->posbuthelp);
SDL_BlitSurface(mc->butquit,NULL,screen,&mpc->posbutquit);
SDL_BlitSurface(mc->butmusic2,NULL,screen,&mpc->posbutmusic);
SDL_BlitSurface(mc->butsound2,NULL,screen,&mpc->posbutsound);
                    SDL_Flip(screen);
}
Mix_PlayChannel(-1, sc->butClick, 0);
pressed = 1;
*soundHoverStopFlag = 1;

}else{
if((((event->button.x <= mpc->posbutsound.x + mc->butsound2->w) && (event->button.x >= mpc->posbutsound.x)) && ((event->button.y >= mpc->posbutsound.y) && (event->button.y <= mpc->posbutsound.y + mc->butsound2->h))) && (bc->sound == 1)) {
         //flip button
    bc->sound = 0;
        mpc->posbutsound.w=mc->butsound->w;
mpc->posbutsound.h=mc->butsound->h;
if(bc->music == 0){
SDL_BlitSurface(mc->back,NULL,screen,&mpc->posback);
SDL_BlitSurface(mc->butgame,NULL,screen,&mpc->posbutgame);
SDL_BlitSurface(mc->butsettings,NULL,screen,&mpc->posbutsettings);
SDL_BlitSurface(mc->butshop,NULL,screen,&mpc->posbutshop);
SDL_BlitSurface(mc->butcredits,NULL,screen,&mpc->posbutcredits);
SDL_BlitSurface(mc->buthelp,NULL,screen,&mpc->posbuthelp);
SDL_BlitSurface(mc->butquit,NULL,screen,&mpc->posbutquit);
SDL_BlitSurface(mc->butmusic,NULL,screen,&mpc->posbutmusic);
SDL_BlitSurface(mc->butsound,NULL,screen,&mpc->posbutsound);
                    SDL_Flip(screen);
}else{
SDL_BlitSurface(mc->back,NULL,screen,&mpc->posback);
SDL_BlitSurface(mc->butgame,NULL,screen,&mpc->posbutgame);
SDL_BlitSurface(mc->butsettings,NULL,screen,&mpc->posbutsettings);
SDL_BlitSurface(mc->butshop,NULL,screen,&mpc->posbutshop);
SDL_BlitSurface(mc->butcredits,NULL,screen,&mpc->posbutcredits);
SDL_BlitSurface(mc->buthelp,NULL,screen,&mpc->posbuthelp);
SDL_BlitSurface(mc->butquit,NULL,screen,&mpc->posbutquit);
SDL_BlitSurface(mc->butmusic2,NULL,screen,&mpc->posbutmusic);
SDL_BlitSurface(mc->butsound,NULL,screen,&mpc->posbutsound);
                    SDL_Flip(screen);
}
Mix_PlayChannel(-1, sc->butClick, 0);
pressed = 0;
*soundHoverStopFlag = 0;
}else{
   if(((event->button.x <= mpc->posbutgame.x + mc->butgame->w) && (event->button.x >= mpc->posbutgame.x)) && ((event->button.y >= mpc->posbutgame.y) && (event->button.y <= mpc->posbutgame.y + mc->butgame->h))){
      if(pressed == 0){
Mix_PlayChannel(-1, sc->butClick, 0);
}
strcpy(pickFromMenu, "playgame");
}else{
   if(((event->button.x <= mpc->posbutsettings.x + mc->butsettings->w) && (event->button.x >= mpc->posbutsettings.x)) && ((event->button.y >= mpc->posbutsettings.y) && (event->button.y <= mpc->posbutsettings.y + mc->butsettings->h))){
      if(pressed == 0){
Mix_PlayChannel(-1, sc->butClick, 0);
}
strcpy(pickFromMenu, "settings");
    }else{
        if(((event->button.x <= mpc->posbutshop.x + mc->butshop->w) && (event->button.x >= mpc->posbutshop.x)) && ((event->button.y >= mpc->posbutshop.y) && (event->button.y <= mpc->posbutshop.y + mc->butshop->h))){
       if(pressed == 0){
Mix_PlayChannel(-1, sc->butClick, 0);
}
strcpy(pickFromMenu, "shop");
    }else{
        if(((event->button.x <= mpc->posbutcredits.x + mc->butcredits->w) && (event->button.x >= mpc->posbutcredits.x)) && ((event->button.y >= mpc->posbutcredits.y) && (event->button.y <= mpc->posbutcredits.y + mc->butcredits->h))){
       if(pressed == 0){
Mix_PlayChannel(-1, sc->butClick, 0);
}
strcpy(pickFromMenu, "credits");
    }else{
        if(((event->button.x <= mpc->posbutquit.x + mc->butquit->w) && (event->button.x >= mpc->posbutquit.x)) && ((event->button.y >= mpc->posbutquit.y) && (event->button.y <= mpc->posbutquit.y + mc->butquit->h))){
       if(pressed == 0){
Mix_PlayChannel(-1, sc->butClick, 0);
}
strcpy(pickFromMenu, "quit");
    }else{
        if(((event->button.x <= mpc->posbuthelp.x + mc->buthelp->w) && (event->button.x >= mpc->posbuthelp.x)) && ((event->button.y >= mpc->posbuthelp.y) && (event->button.y <= mpc->posbuthelp.y + mc->buthelp->h))){
      if(pressed == 0){
Mix_PlayChannel(-1, sc->butClick, 0);
}
strcpy(pickFromMenu, "help");
    }else{
                 if((((event->button.x <= mpc->posbutmusic.x + mc->butmusic->w) && (event->button.x >= mpc->posbutmusic.x)) && ((event->button.y >= mpc->posbutmusic.y) && (event->button.y <= mpc->posbutmusic.y + mc->butmusic->h))) && (bc->music == 0)) {
         //flip button
    bc->music = 1;
        mpc->posbutmusic.w=mc->butmusic2->w;
mpc->posbutmusic.h=mc->butmusic2->h;
if(bc->sound ==1){
SDL_BlitSurface(mc->back,NULL,screen,&mpc->posback);
SDL_BlitSurface(mc->butgame,NULL,screen,&mpc->posbutgame);
SDL_BlitSurface(mc->butsettings,NULL,screen,&mpc->posbutsettings);
SDL_BlitSurface(mc->butshop,NULL,screen,&mpc->posbutshop);
SDL_BlitSurface(mc->butcredits,NULL,screen,&mpc->posbutcredits);
SDL_BlitSurface(mc->buthelp,NULL,screen,&mpc->posbuthelp);
SDL_BlitSurface(mc->butquit,NULL,screen,&mpc->posbutquit);
SDL_BlitSurface(mc->butmusic2,NULL,screen,&mpc->posbutmusic);
SDL_BlitSurface(mc->butsound2,NULL,screen,&mpc->posbutsound);
                    SDL_Flip(screen);
}else{
SDL_BlitSurface(mc->back,NULL,screen,&mpc->posback);
SDL_BlitSurface(mc->butgame,NULL,screen,&mpc->posbutgame);
SDL_BlitSurface(mc->butsettings,NULL,screen,&mpc->posbutsettings);
SDL_BlitSurface(mc->butshop,NULL,screen,&mpc->posbutshop);
SDL_BlitSurface(mc->butcredits,NULL,screen,&mpc->posbutcredits);
SDL_BlitSurface(mc->buthelp,NULL,screen,&mpc->posbuthelp);
SDL_BlitSurface(mc->butquit,NULL,screen,&mpc->posbutquit);
SDL_BlitSurface(mc->butmusic2,NULL,screen,&mpc->posbutmusic);
SDL_BlitSurface(mc->butsound,NULL,screen,&mpc->posbutsound);
                    SDL_Flip(screen);
}
 if(pressed == 0){
Mix_PlayChannel(-1, sc->butClick, 0);
}
Mix_PauseMusic();
}else{
if((((event->button.x <= mpc->posbutmusic.x + mc->butmusic->w) && (event->button.x >= mpc->posbutmusic.x)) && ((event->button.y >= mpc->posbutmusic.y) && (event->button.y <= mpc->posbutmusic.y + mc->butmusic->h))) && (bc->music == 1)) {
         //flip button
    bc->music = 0;
if(bc->sound == 1 ){
        mpc->posbutsound.w=mc->butsound->w;
mpc->posbutsound.h=mc->butsound->h;
SDL_BlitSurface(mc->back,NULL,screen,&mpc->posback);
SDL_BlitSurface(mc->butgame,NULL,screen,&mpc->posbutgame);
SDL_BlitSurface(mc->butsettings,NULL,screen,&mpc->posbutsettings);
SDL_BlitSurface(mc->butshop,NULL,screen,&mpc->posbutshop);
SDL_BlitSurface(mc->butcredits,NULL,screen,&mpc->posbutcredits);
SDL_BlitSurface(mc->buthelp,NULL,screen,&mpc->posbuthelp);
SDL_BlitSurface(mc->butquit,NULL,screen,&mpc->posbutquit);
SDL_BlitSurface(mc->butmusic,NULL,screen,&mpc->posbutmusic);
SDL_BlitSurface(mc->butsound2,NULL,screen,&mpc->posbutsound);
                    SDL_Flip(screen);
}else{
SDL_BlitSurface(mc->back,NULL,screen,&mpc->posback);
SDL_BlitSurface(mc->butgame,NULL,screen,&mpc->posbutgame);
SDL_BlitSurface(mc->butsettings,NULL,screen,&mpc->posbutsettings);
SDL_BlitSurface(mc->butshop,NULL,screen,&mpc->posbutshop);
SDL_BlitSurface(mc->butcredits,NULL,screen,&mpc->posbutcredits);
SDL_BlitSurface(mc->buthelp,NULL,screen,&mpc->posbuthelp);
SDL_BlitSurface(mc->butquit,NULL,screen,&mpc->posbutquit);
SDL_BlitSurface(mc->butmusic,NULL,screen,&mpc->posbutmusic);
SDL_BlitSurface(mc->butsound,NULL,screen,&mpc->posbutsound);
                    SDL_Flip(screen);
}
 if(pressed == 0){
Mix_PlayChannel(-1, sc->butClick, 0);
}
Mix_ResumeMusic();
}
}
     }
     }
     }
     }
     }
  }
}
}
}
