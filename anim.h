#ifndef ANIM_H_INCLUDED
#define ANIM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <time.h>
typedef struct {
 SDL_Surface * spriteleft;
 SDL_Surface * spriteright;
}enemy;
typedef struct{
  SDL_Rect pmax_enemy;
  SDL_Rect pmin_enemy;
  SDL_Rect position_enemy;
}enemyPos;

int rand_pos(int pmax,int pmin);
int moveEnemy(enemyPos * e, SDL_Surface *screen);
void animEnm (enemy * e, enemyPos ep, SDL_Surface *screen, int asMovement);
#endif
