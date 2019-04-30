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
  SDL_Surface * spriteleft[4];
  SDL_Surface * spriteright[5];
  SDL_Rect pmax_enemy;
  SDL_Rect pmin_enemy;
  SDL_Rect position_enemy;
}enemy;

enemy initEnm ();
void showEnm(enemy e, SDL_Surface * screen);
int rand_pos(int pmax, int pmin);
int moveEnemy(enemy *e, SDL_Surface *screen,SDL_Rect poshero);
void animEnm (enemy e, SDL_Surface *screen, int asMouvement);
#endif
