#ifndef ANIM_H_INCLUDED
#define ANIM_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <time.h>


/**
* @struct enemy
* @brief struct for the enemy's sprites
*/

typedef struct {
 SDL_Surface * spriteleft; /*!< Surface. */
 SDL_Surface * spriteright;  /*!< Surface. */
 STATE state;
}enemy;

/**
* @struct enemyPos
* @brief struct for the enemy's position
*/

typedef struct{
  SDL_Rect pmax_enemy;             /*!< Rectangle*/
  SDL_Rect pmin_enemy;            /*!< Rectangle*/
  SDL_Rect position_enemy;      /*!< Rectangle*/

}enemyPos;

int rand_pos(int pmax,int pmin);
int moveEnemy(enemyPos * e, SDL_Surface *screen);
void animEnm (enemy * e, enemyPos ep, SDL_Surface *screen, int asMovement);
#endif
