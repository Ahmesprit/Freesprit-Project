#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

enemy initEnm (){
  enemy enm;
  enm.e = IMG_Load("object.png");
if(enm.e == NULL){
  printf("enable to load the image\n");
}
  return enm;
}
void showEnm(enemy enm, SDL_Surface * screen){
enm.posEnm.x = 300;
enm.posEnm.y = 300;
enm.posEnm.h = enm.e->h;
enm.posEnm.w = enm.e->w;
 SDL_BlitSurface(enm.e, NULL, screen, &enm.posEnm);
 SDL_Flip (screen);
}
