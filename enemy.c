#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <time.h>

enemy initEnm (){
  enemy e;
  e.spriteleft = IMG_Load("Resources/l.png");
	e.spriteright = IMG_Load("Resources/r.png");
if((e.spriteleft == NULL) && (e.spriteright == NULL)){
  printf("enable to load the image\n");
}
  return e;
}
int rand_pos(int pmax,int pmin){
int pos;
 srand(time(NULL));
pos=rand()%(pmax-pmin+1)+pmin;
return pos;
}
void moveEnemy(enemyPos * e, SDL_Surface *screen){
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
                  e->position_enemy.x+= 50;

              }else{
                k=1;
              }
            }
            if(k==1){
                if(e->position_enemy.x > e->pmin_enemy.x){
                      e->position_enemy.x-=50;
                    }else{
                         k=0;
                    }
            }
            tPr = tAct;
        }
}

void showEnm(enemyPos *enm, enemy e, SDL_Surface * screen){
  SDL_Rect camera;
  camera.x = 0;
  camera.y = 0;
  camera.h = 61;
  camera.w = 65;
enm->position_enemy.x = 800;
enm->position_enemy.y = 500;
enm->position_enemy.h = e.spriteleft->h;
enm->position_enemy.w = e.spriteleft->w;
 SDL_BlitSurface(e.spriteleft, &camera, screen, &enm->position_enemy);
}
void animEnm (enemy * e, enemyPos ep, SDL_Surface *screen){
  SDL_Rect frame;
  static int inc = 0;
  static int i = 1;
  static int k = 1;
  if (i<=8) {
  inc = inc + 63;
  frame.x = inc;
  frame.y = 0;
  frame.w = 63;
  frame.h = 65;
  SDL_BlitSurface(e->spriteleft, &frame, screen, &ep.position_enemy);
  i++;
}else{
  i=9; inc = 0;
  if (k <= 8) {
    inc = inc + 63;
  frame.x = inc;
  frame.y = 0;
  frame.w = 63;
  frame.h = 65;
  SDL_BlitSurface(e->spriteright, &frame, screen, &ep.position_enemy);
  k++;
}else{
  k = 9;
  i=1;
}
}
}
