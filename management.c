#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "management.h"
#include <string.h>
void updateScore(int *score, SDL_Surface *screen){
  *score = 10;
  char ch[10];
  SDL_Rect poscore;
  SDL_Surface *scoring;
  poscore.x=300;
  poscore.y=300;
  poscore.w = 300;
  poscore.h = 300;
  TTF_Font *police = NULL;
  SDL_Color noir = {255, 255, 255};
  police = TTF_OpenFont("western.ttf", 32);
  sprintf(ch,"%d",*score);
  scoring=TTF_RenderText_Solid(police, ch, noir);
  SDL_BlitSurface(scoring, NULL, screen, &poscore);
  SDL_Flip(screen);
}
void updateLives(int *lives, SDL_Surface *screen){
  char ch[10];
  SDL_Rect poslives;
SDL_Rect poshearts;
  SDL_Surface *hearts = IMG_Load("heart.png");
SDL_Surface *livestext;
  poslives.x=300;
  poslives.y=300;
  poslives.w = 0;
  poslives.h = 0;
 poshearts.x= 400;
  poshearts.y= 300;
  poshearts.w = 0;
  poshearts.h = 0;
  TTF_Font *police = NULL;
  SDL_Color noir = {255, 255, 255};
  police = TTF_OpenFont("western.ttf", 32);
  sprintf(ch,"%d",((*lives)-1));
  livestext=TTF_RenderText_Solid(police, ch, noir);
SDL_BlitSurface(hearts, NULL, screen, &poshearts);
SDL_BlitSurface(livestext, NULL, screen, &poslives);
SDL_Flip(screen);
}


