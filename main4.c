#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "scro.h"
#include <string.h>

int main() {
SDL_Rect camera;
SDL_Surface *screen;
SDL_Surface *back;
SDL_Event event;
int done=0;
SDL_Rect backpos;

if(SDL_Init(SDL_INIT_VIDEO)!=0){
 printf("unable to initialize SDL:%s \n",SDL_GetError());
 	return 1;
 }
 screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 SDL_WM_SetCaption( "Freesprit", NULL);


 back= IMG_Load("backgroundstage1.png");

backpos.x = 0;
backpos.y = 0;
backpos.h = back->h;
backpos.w = back->w;
camera.x = 0;
camera.y = 0;
camera.h = back->h;
camera.w = back->w;
SDL_BlitSurface(back, &camera, screen, NULL);
SDL_Flip(screen);

while (done == 0){
SDL_WaitEvent(&event);
scrolling (&camera,event);
SDL_BlitSurface(back, &camera, screen, NULL);
SDL_Flip(screen);
}

SDL_FreeSurface(screen);
SDL_Quit();

return 0;
}
