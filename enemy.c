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
  int i; char o[512];
  for (i = 0; i < 5; i++) {
    sprintf(o, "Resources/enemyEgypt/%d.PNG",i);
    e.spriteright[i] = IMG_Load(o);
  }
  for (i = 0; i < 4; i++) {
    sprintf(o, "Resources/enemyEgypt/%dl.png",i+1);
    e.spriteleft[i] = IMG_Load(o);
  }
e.position_enemy.x = 800;
e.position_enemy.y = 390;
  return e;
}
void showEnm(enemy e, SDL_Surface * screen){
e.position_enemy.h = e.spriteleft[0]->h;
// e.position_enemy.w = e.spriteleft[0]->w;
 SDL_BlitSurface(e.spriteleft[0], NULL, screen, &e.position_enemy);
}
int rand_pos(int pmax,int pmin){
int pos;
 srand(time(NULL));
pos=rand()%(pmax-pmin+1)+pmin;
return pos;
}
int moveEnemy(enemy *e, SDL_Surface *screen, SDL_Rect poshero){
SDL_Event event;
int c = 1;
int tPr = 0, tAct = 0;
int pos;
  int s1 = 600;
  int d = e->position_enemy.x - poshero.x;
  int i = 1;
  if(d >= s1){
    i = 1;
  }else{
    if((d < s1) && (d > 100)){
      e->position_enemy.x -=5;
      i = 2;
    }else{
      if((d <= 100) && (d>=0)){
        i= 3;
      }
    }
  }
  return i;
}

void animEnm (enemy e, SDL_Surface *screen, int asMouvement){
  static int anim_indicator = 0;
  if(asMouvement == 1){
   SDL_BlitSurface(e.spriteleft[0], NULL, screen, &e.position_enemy);
   }else{
   if(asMouvement == 2){
     if(anim_indicator > 4){
       anim_indicator = 0;
       SDL_BlitSurface(e.spriteleft[0], NULL, screen, &e.position_enemy);
     }else{
       SDL_BlitSurface(e.spriteleft[anim_indicator], NULL, screen, &e.position_enemy);
       anim_indicator++;
     }
   }else{
     if(asMouvement==3){

     }
   }
 }
}
