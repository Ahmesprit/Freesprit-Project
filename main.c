#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "anim.h"

int main() {
enemy e;
SDL_Surface *pic;
SDL_Surface *screen;
enemyPos en;
SDL_Event event;
SDL_Rect backpos;
int done=0;
int playgame = 2;
SDL_Surface *back;

if(SDL_Init(SDL_INIT_VIDEO)!=0){
 printf("unable to initialize SDL:%s \n",SDL_GetError());
 	return 1;
 }
 screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 SDL_WM_SetCaption( "Freesprit", NULL);

 back= IMG_Load("backgroundstage1.png");

backpos.x = 0;
backpos.y = 0;
backpos.h = back->h;
backpos.w = back->w;

pic= IMG_Load("enemy.png");
en.position_enemy.x = 600;
en.position_enemy.y = 400;
en.position_enemy.h = pic->h;
en.position_enemy.w = pic->w;

e.spriteright=IMG_Load("d.png");
e.spriteleft=IMG_Load("l.png");

SDL_BlitSurface(back, NULL,screen, &backpos);
SDL_BlitSurface(pic, NULL,screen, &en.position_enemy);
SDL_Flip(screen);
int notDead = 0;
int x;
while (done == 0){
 while(notDead == 0){
          x = moveEnemy(&en,screen);
          if (x == 0) {
            printf("thisd\n");
          }
          SDL_BlitSurface(back, NULL,screen, &backpos);
                     animEnm(&e, en, screen, x);
                     SDL_Flip(screen);
       }
  }



SDL_FreeSurface(screen);
SDL_Quit();

return 0;
}
