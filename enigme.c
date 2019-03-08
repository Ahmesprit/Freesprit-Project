#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "enigme.h"

typedef struct{
  SDL_Surface * back;
  FILE * f = NULL;
}enigme;

enigme initEnigme (){
 e.f = fopen("period.txt", "r");
 e.back = IMG_Load("object.png");
}

void showEnigme (enigme e){
  char quest[400];
  char c1[50];
 char c2[50];
 char c3[50];
int x;
TTF_Font * sans = TTF_OpenFont("Sans.ttf", 24);
SDL_Color white = {255,255,0};
SDL_Surface * msg = TTF_RenderText_Solid(sans, quest, white);
SDL_Texture * message = SDL_CreateTextureFromSurface(renderer, msg);
SDL_Rect msgrect;
msgrect.x = 300;
msgrect.x = 300;
msgrect.w = 300;
msgrect.h = 300;
  fscanf("%s 1)%s 2)%s 3)%s %d\n", quest, c1, c2, c3, x);
  SDL_RenderCopy(renderer, message, NULL, &msgrect);
}
