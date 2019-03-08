#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

object initObj (){
  object o;
  o.obj = IMG_Load("object.png");
if(o.obj == NULL){
  printf("enable to load the image\n");
}
  return o;
}
void showObj(object o, SDL_Surface * screen){
o.posObj.x = 300;
o.posObj.y = 300;
o.posObj.h = o.obj->h;
o.posObj.w = o.obj->w;
 SDL_BlitSurface(o.obj, NULL, screen, &o.posObj);
 SDL_Flip (screen);
}
