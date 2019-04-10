#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "dc.h"
backgroundMaps initMaps(){
backgroundMaps bm;
 bm.map = IMG_Load("backgroundstage1.png");
 bm.posMap.x=0;
 bm.posMap.y=0; 
 bm.posMap.w=960;
 bm.posMap.h=600;

 return bm;
}
void showMaps(backgroundMaps bm, SDL_Surface *screen){
 
  SDL_BlitSurface(bm.map,NULL, screen, &bm.posMap);
}


void depKeyboard (SDL_Rect* persoPos, SDL_Event event){


         SDL_PollEvent(&event);
  switch (event.key.keysym.sym){
         case SDLK_UP: //fleche haut
          persoPos->y-=10;
  break;
         case SDLK_DOWN: //fleche bas
         persoPos->y+=10;
  break;

  case SDLK_RIGHT:
         persoPos->x+=10;
  break;
  case SDLK_LEFT:
          persoPos->x-=10;
  break;
   }

}
int main() {
  
SDL_Surface *screen;
backgroundMaps bm;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL:%s \n",SDL_GetError());
return 1;
}
screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

SDL_WM_SetCaption("Freesprit", NULL);

int done = 0;
SDL_Surface * perso;
SDL_Rect persoPos;
SDL_Event event;
bm = initMaps();
showMaps(bm, screen);


perso = IMG_Load("soso.png");
SDL_SetColorKey(perso ,SDL_SRCCOLORKEY,SDL_MapRGB(perso ->format,255,255,255));
persoPos.x = 0; persoPos.y = 0;
SDL_EnableKeyRepeat(20,10);
persoPos.h = perso->h; persoPos.w = perso->w;
SDL_BlitSurface(perso, NULL, screen, &persoPos);
SDL_Flip(screen);

while(done == 0){
while(SDL_PollEvent(&event) == 1){
   
    depKeyboard(&persoPos, event);
 
SDL_BlitSurface(bm.map, NULL, screen, &bm.posMap);
SDL_BlitSurface(perso, NULL, screen, &persoPos);
SDL_Flip(screen);

}
}


SDL_FreeSurface(screen);
SDL_Quit();
return 0;
}
