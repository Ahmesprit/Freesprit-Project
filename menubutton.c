#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "menubutton.h"

void initSettings(settingsComponents * setc, settingsPosComponents * spc){
setc->settingsback =IMG_Load("Resources/settingsback.png");
if (setc->settingsback==NULL){
	printf("unable to load background  image %s\n",SDL_GetError());
}
setc->butback=IMG_Load("Resources/back.png");
setc->butoff1=IMG_Load("Resources/switchoff.png");
setc->buton1=IMG_Load("Resources/switchon.png");
setc->butoff2=IMG_Load("Resources/switchoff.png");
setc->buton2=IMG_Load("Resources/switchon.png");
setc->butone1=IMG_Load("Resources/one.png");
setc->butone2 = IMG_Load("Resources/one.png");
setc->buttwo1 = IMG_Load("Resources/two.png");
setc->buttwo2 = IMG_Load("Resources/two.png");
//positions
spc->possettingsback.x=0;
spc->possettingsback.y=0;
spc->possettingsback.w=setc->settingsback->w;
spc->possettingsback.h=setc->settingsback->h;
spc->posbutback.x = 150;
spc->posbutback.y = 220;
spc->posbutback.w=setc->butback->w;
spc->posbutback.h=setc->butback->h;
spc->posbuton.x = 150;
spc->posbuton.y = 270;
spc->posbuton.w=setc->buton1->w;
spc->posbuton.h=setc->buton1->h;
spc->posbutoff.x = 150;
spc->posbutoff.y = 270;
spc->posbutoff.w=setc->butoff1->w;
spc->posbutoff.h=setc->butoff1->h;
spc->posbutone1.x = 150;
spc->posbutone1.y = 320;
spc->posbutone1.w=setc->butone1->w;
spc->posbutone1.h=setc->butone1->h;
spc->posbuttwo1.x = 150;
spc->posbuttwo1.y = 320;
spc->posbuttwo1.w = setc->buttwo1->w;
spc->posbuttwo1.h = setc->buttwo1->h;
spc->posbutone2.x = 150;
spc->posbutone2.y = 320;
spc->posbutone2.w=setc->butone2->w;
spc->posbutone2.h=setc->butone2->h;
spc->posbuttwo2.x = 150;
spc->posbuttwo2.y = 320;
spc->posbuttwo2.w = setc->buttwo2->w;
spc->posbuttwo2.h = setc->buttwo2->h;
spc->posbutselection1.x = 150;
spc->posbutselection1.y = 370;
spc->posbutselection2.x = 150;
spc->posbutselection2.y = 370;
}
