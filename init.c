#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "init.h"
menuComponents initMenu(){
menuComponents mc;
mc.screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

if (mc.screen==NULL){	
	printf("unable to load Game %s\n",SDL_GetError());
}
mc.back1 =IMG_Load("back1.png");
if (mc.back1==NULL){	
	printf("unable to load background  image %s\n",SDL_GetError());
}
mc.butgame=IMG_Load("play.png");
mc.butsettings=IMG_Load("settings.png");
mc.butshop=IMG_Load("shop.png");
mc.butgame2=IMG_Load("play2.png");
mc.butsettings2=IMG_Load("settings2.png");
mc.butshop2=IMG_Load("shop2.png");
mc.buthelp = IMG_Load("help.png");
mc.butsound = IMG_Load("volume.png");
mc.butsound2 = IMG_Load("volume2.png");
mc.butcredits = IMG_Load("credits.png");
mc.butcredits2 = IMG_Load("credits2.png");
mc.butmusic = IMG_Load("music.png");
mc.butmusic2 = IMG_Load("music2.png");
mc.butquit = IMG_Load("quit.png");
mc.butquit2 = IMG_Load("quit2.png");
if ((mc.butgame==NULL) || (mc.butsettings==NULL) || (mc.butshop==NULL) || (mc.butgame2==NULL) || (mc.butsettings2==NULL) || (mc.butshop2==NULL) || (mc.buthelp==NULL) || (mc.butsound==NULL) || (mc.butsound2==NULL) || (mc.butmusic==NULL) || (mc.butmusic2==NULL) || (mc.butquit==NULL) || (mc.butquit2==NULL) || (mc.butcredits==NULL) || (mc.butcredits2==NULL)){	
	printf("unable to load button image %s\n",SDL_GetError());
}
return mc;
}
