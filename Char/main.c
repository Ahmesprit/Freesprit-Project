#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "char.h"
int main(){
//initializing the screen
SDL_Surface *screen;
 charac c;
characPos cp;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initializeSDL:%s \n",SDL_GetError());
	return 1;
}

screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

SDL_WM_SetCaption( "Freesprit", NULL);
int done = 0;
//Game loop starts
while (done == 0){
c = initChar();
 showChar(&cp, c , screen);
  SDL_Flip(screen);
}
//end game loop
SDL_FreeSurface(screen);
SDL_Quit();
return 0;
}
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
