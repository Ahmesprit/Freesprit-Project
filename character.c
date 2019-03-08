#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

character initChar (){
  character chr;
  int lives = 0;
  chr.ch = IMG_Load("object.png");
if(chr.ch == NULL){
  printf("enable to load the image\n");
}
  return chr;
}
void showChar(character chr, SDL_Surface * screen){
chr.posChr.x = 300;
chr.posChr.y = 300;
chr.posChr.h = chr.ch->h;
chr.posChr.w = chr.ch->w;
 SDL_BlitSurface(chr.ch, NULL, screen, &chr.posChr);
 SDL_Flip (screen);
}
