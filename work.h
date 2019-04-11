#ifndef WORK_H_INCLUDED
#define WORK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <time.h>
#include <math.h>
typedef struct {
 SDL_Surface * spriteleft;
 SDL_Surface * spriteright;
}enemy;
typedef struct{
  SDL_Rect pmax_enemy;
  SDL_Rect pmin_enemy;
  SDL_Rect position_enemy;
}enemyPos;
typedef struct {
int sec;
int min;
int ticker;
}timer;
typedef struct {
  SDL_Surface *hearts;
  SDL_Rect posLives;
  SDL_Surface *livestext;
  SDL_Surface *timestext;
  SDL_Surface *scoretext;
  SDL_Rect scorePos;
  SDL_Rect posheart;
  SDL_Rect timePos;
}entities;
SDL_Surface * updateScore(int *score);
SDL_Surface * updateLives(int *lives);
SDL_Surface * gameTime (timer *t);
entities gameEntities();
enemy initEnm ();
void showEnm(enemyPos *enm, enemy e, SDL_Surface * screen);
int detectCollTrig (SDL_Rect rect1, SDL_Rect rect2);
#endif
