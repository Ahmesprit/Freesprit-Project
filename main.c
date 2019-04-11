#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "work.h"

int main() {
int x = 0;
SDL_Surface *screen;
SDL_Surface * back;
entities ent;
SDL_Rect pos;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL:%s \n",SDL_GetError());
return 1;
}

screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
printf("No sounds %s\n",Mix_GetError());
        return 1;
}
SDL_WM_SetCaption( "Freesprit", NULL);
int done = 0;
SDL_Event event;
SDL_Surface * obj1;
SDL_Rect rect1, rect2;
enemy e;
int score = 0, lives = 5;
enemyPos ep;
timer t;
t.ticker = 0;
t.sec = 0; t.min =3;
back = IMG_Load("back.jpg");
obj1 = IMG_Load("obj1.jpg");
rect1.x = 700;
rect1.y = 300;
rect1.h = obj1->h;
rect1.w = obj1->w;
pos.x = 0; pos.y = 0; pos.h =back->h; pos.w= back->w;
e = initEnm();
ep.position_enemy.x = 300;
ep.position_enemy.y = 300;
showEnm(&ep, e, screen);
SDL_BlitSurface(obj1, NULL, screen, &rect1);
SDL_BlitSurface(back, NULL, screen, &pos);
ent = gameEntities();
ent.scoretext = updateScore(&score);
ent.timestext = gameTime(&t);
ent.livestext = updateLives(&lives);
SDL_BlitSurface(ent.scoretext, NULL, screen, &ent.scorePos);
SDL_BlitSurface(ent.timestext, NULL, screen, &ent.timePos);
SDL_BlitSurface(ent.livestext, NULL, screen, &ent.posLives);
SDL_BlitSurface(ent.timestext, NULL, screen, &ent.timePos);
SDL_BlitSurface(ent.hearts, NULL, screen, &ent.posheart);
SDL_Flip(screen);
//Game loop starts
while (done == 0){
  while(SDL_PollEvent(&event) == 1){
    x  =0;
  switch (event.key.keysym.sym){
         case SDLK_UP:
         score++;
          ep.position_enemy.y-=10;
  break;
         case SDLK_DOWN:
         score++;
         ep.position_enemy.y+=10;
  break;

  case SDLK_RIGHT:
  score++;
         ep.position_enemy.x+=10;
  break;
  case SDLK_LEFT:
  score++;
         ep.position_enemy.x-=10;
  break;
   }
}
SDL_BlitSurface(back, NULL, screen, &pos);
showEnm(&ep, e, screen);
SDL_BlitSurface(obj1, NULL, screen, &rect1);
ent = gameEntities();
ent.scoretext = updateScore(&score);
ent.timestext = gameTime(&t);
ent.livestext = updateLives(&lives);
SDL_BlitSurface(ent.scoretext, NULL, screen, &ent.scorePos);
SDL_BlitSurface(ent.timestext, NULL, screen, &ent.timePos);
SDL_BlitSurface(ent.livestext, NULL, screen, &ent.posLives);
SDL_BlitSurface(ent.timestext, NULL, screen, &ent.timePos);
SDL_BlitSurface(ent.hearts, NULL, screen, &ent.posheart);
   SDL_Flip(screen);
   if(detectCollTrig (ep.position_enemy,rect1)==1) {
     if(x == 0){
      lives--;
     x= 1;
   }
}

}
//end game loop
SDL_FreeSurface(screen);
SDL_Quit();

return 0;
}
