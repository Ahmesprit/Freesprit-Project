#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "char.h"
 
charac initChar (){
  charac c;
  c.spriteleft = IMG_Load("perso_l.png");
	c.spriteright = IMG_Load("perso_r.png");
if((c.spriteleft == NULL) && (c.spriteright == NULL)){
  printf("enable to load the image\n");
}
  return c;
}
void showChar(characPos *cp, charac c, SDL_Surface * screen){
  SDL_Rect camera;
  camera.x = 0;
  camera.y = 0;
  camera.h = 61;
  camera.w = 65;
cp->position.x = 200;
cp->position.y = 500;
cp->position.h = c.spriteleft->h;
cp->position.w = c.spriteleft->w;
 SDL_BlitSurface(c.spriteleft, &camera, screen, &cp->position);
}



