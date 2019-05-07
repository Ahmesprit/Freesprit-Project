/**
*
*@file main.c
* @author Ahmed Debbech
*/
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <time.h>
#include "enigme.h"

int main(){
  SDL_Surface *screen;
  SDL_Event event;
  int done=0;
  enigme e;
  enigmeData ed;
  //initializing the screen
  if(SDL_Init(SDL_INIT_VIDEO)!=0){
  printf("unable to initializeSDL:%s \n",SDL_GetError());
  	return 1;
  }
  screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  SDL_WM_SetCaption( "Freesprit", NULL);
  e = initEnigme();
  ed = generateEnigme(e);
  showEnigme(ed,screen,e);
  SDL_Flip(screen);
while(done == 0){
     SDL_PollEvent(&event);
     if(event.type == SDL_QUIT){
       done =1 ;
     }else{
     if(event.type == SDL_KEYDOWN){
     if(resolutionEnigme(ed, event) == 1){
       printf("correct\n");
     }else{
       printf("not correct\n");
     }
   }
 }
}
  SDL_FreeSurface(screen);
  SDL_Quit();
  return 0;
}
