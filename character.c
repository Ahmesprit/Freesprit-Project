#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

charac initChar (){
  charac c;
  c.spriteleft = IMG_Load("Resources/perso_l.png");
	c.spriteright = IMG_Load("Resources/perso_r.png");
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
void animChar (charac * c, characPos cp, SDL_Surface *screen, SDL_Event event){
  SDL_Rect frame;
  static int inc = 0;
  static int incc = 0;
  if ((event.key.keysym.sym == SDLK_RIGHT) || (event.key.keysym.sym == SDLK_UP)) {
    incc =0;
    if (inc > 440){
       inc = 0;
     frame.x = inc;
     frame.y = 0;
     frame.w = 63;
     frame.h = 65;
     SDL_BlitSurface(c->spriteleft, &frame, screen, &cp.position);
    }else{
    inc = inc + 63;
  frame.x = inc;
  frame.y = 0;
  frame.w = 63;
  frame.h = 65;
  SDL_BlitSurface(c->spriteleft, &frame, screen, &cp.position);
}

}else{
  if ((event.key.keysym.sym == SDLK_LEFT) || (event.key.keysym.sym == SDLK_DOWN)) {
inc =0;
    if (incc > 440) {
       incc = 0;
       incc = incc + 63;
     frame.x = incc;
     frame.y = 0;
     frame.w = 63;
     frame.h = 65;
     SDL_BlitSurface(c->spriteright, &frame, screen, &cp.position);
    }else{
    incc = incc + 63;
  frame.x = incc;
  frame.y = 0;
  frame.w = 63;
  frame.h = 65;
  SDL_BlitSurface(c->spriteright, &frame, screen, &cp.position);
  }
  }
}
}
//you must add '-lm' in terminal to link file
void moveChar (SDL_Event event, SDL_Rect *posobj){
switch (event.key.keysym.sym){
       case SDLK_UP:
        posobj->y-=10;
	break;
       case SDLK_DOWN:
       posobj->y+=10;
	break;

	case SDLK_RIGHT:
       posobj->x+=10;
	break;
	case SDLK_LEFT:
       posobj->x-=10;
	break;
 }

}
