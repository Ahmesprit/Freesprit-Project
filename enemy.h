#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "enemy.h"
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
enemy initEnm ();
int rand_pos(int pmax,int pmin);
void moveEnemy(enemyPos * e, SDL_Surface *screen);
void showEnm(enemyPos *enm, enemy e, SDL_Surface * screen);
void animEnm (enemy * e, enemyPos ep, SDL_Surface *screen);
#endif
