#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

enemy initEnm (){
  enemy enm;
  enm.e = IMG_Load("enemy.png");
if(enm.e == NULL){
  printf("enable to load the image\n");
}
  return enm;
}
void showEnm(enemy enm, SDL_Surface * screen){
enm.posEnm.x = 300;
enm.posEnm.y = 300;
enm.posEnm.h = enm.e->h;
enm.posEnm.w = enm.e->w;
 SDL_BlitSurface(enm.e, NULL, screen, &enm.posEnm);
 SDL_Flip (screen);
}

int rand_pos(int pmax,int pmin)
{
int pos;
 srand(time(NULL));
pos=rand()%(pmax-pmin+1)+pmin;
return pos;
}

void deplacement_aleatoire(enemy e,SDL_Surface *screen)
{
SDL_Event event;
int c = 1;
int tPr = 0, tAct = 0;
int pos;
static int k=0;
char temps[20];

e.pmax_enemy.x=screen->w / 2 ;//- e.image_enemy->w / 2;
pos=rand_pos(e.pmax_enemy.x,e.pmin_enemy.x);
SDL_EnableKeyRepeat(10, 10);

    while (c)
    {
        SDL_PollEvent(&event); 
        switch(event.type)
        {
            case SDL_QUIT:
                c = 0;
                break;
        }

        tAct = SDL_GetTicks();
        if (tAct - tPr > 30) 
        { if(k==0)

                   {
                     if(e.position_enemy.x<pos)/*pmax)*/
                          {
                            e.position_enemy.x++;

                          }
                     else k=1;

                   }
              if(k==1)
                  {
                    if(e.position_enemy.x>e.pmin_enemy.x)
                            e.position_enemy.x--;
                    else
                         k=0;
                  }             
                                  
            tPr = tAct; 
        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(e.image_enemy, NULL, screen, &e.position_enemy);
        SDL_Flip(screen);
    }
}
