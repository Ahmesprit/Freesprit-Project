/*!
* @file anim.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "anim.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <time.h>

/**
* @brief choose random pos .
* @param pmax maximal position 
* @param pmin minimum position
* @return position
*/



int rand_pos(int pmax,int pmin){
int pos;
 srand(time(NULL));
pos=rand()%(pmax-pmin+1)+pmin;
return pos;
}

/**
* @brief moving the ennemy .
* @param screen the screen
* @param e the enemy's position
* @return int moving to right or left
*/

int moveEnemy (enemyPos * e, SDL_Surface *screen){
SDL_Event event;
int c = 1;
int tPr = 0, tAct = 0;
int pos;
static int k=0;
e->pmax_enemy.x = screen->w  ;
e->pmin_enemy.x = screen->w/2 ;
pos = rand_pos(e->pmax_enemy.x, e->pmin_enemy.x);
        tAct = SDL_GetTicks();
        if (tAct - tPr > 30){
           if(k==0){
              if(e->position_enemy.x < pos){
                  e->position_enemy.x++;
                  return 1;
              }else{
                k=1;
                return 2;
              }
            }
            if(k==1){
                if(e->position_enemy.x > e->pmin_enemy.x){
                      e->position_enemy.x--;
                        return 2;
                    }else{
                         k=0;
                         return 1;
                    }
            }
            tPr = tAct;
        }
        return 0;
}


/**
* @brief animate enemy
* @param e the enemy
* @param ep enemy's position
* @param asMovement moving right or left
* @param screen the screen
* @return nothing
*/

void animEnm (enemy * e, enemyPos ep, SDL_Surface *screen, int asMovement){
  SDL_Rect frame;
  static int inc = 0;
  static int incc = 0;
  static int i = 0;
  static int k = 0;
  if (asMovement == 1) {
    incc = 0; k = 0;
    if(i > 7){
      inc = 0; i =0;
      inc = inc + 64;
      frame.x = inc;
      frame.y = 0;
      frame.w = 64;
      frame.h = 61;
      SDL_BlitSurface(e->spriteleft, &frame, screen, &ep.position_enemy);
    }else{
  inc = inc + 64;
  frame.x = inc;
  frame.y = 0;
  frame.w = 64;
  frame.h = 61;
  SDL_BlitSurface(e->spriteleft, &frame, screen, &ep.position_enemy);
  i++;
}
}else{
  i = 0;
  if (asMovement == 2) {
    inc = 0;
    if(k > 7){
      incc = 0; k =0;
      incc = incc + 64;
    frame.x = incc;
    frame.y = 0;
    frame.w = 64;
    frame.h = 61;
    SDL_BlitSurface(e->spriteright, &frame, screen, &ep.position_enemy);
    }else{
    incc = incc + 64;
  frame.x = incc;
  frame.y = 0;
  frame.w = 64;
  frame.h = 61;
  SDL_BlitSurface(e->spriteright, &frame, screen, &ep.position_enemy);
  k++;
}
}
}
}
