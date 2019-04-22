/*!
* @file main1.c
* @brief Testing Object.
* @author Aziz
* @version 1
* @date Apr 19, 2019
*/


#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"


int main (){
SDL_Surface * screen;
object o;
int done=0;

if(SDL_Init(SDL_INIT_VIDEO)!=0){
 printf("unable to initialize SDL:%s \n",SDL_GetError());
 	return 1;
 }
 screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 SDL_WM_SetCaption( "Freesprit", NULL);

while (done==0) {
o=initObj ();
showObj(o,screen);
SDL_Flip(screen);
}
SDL_FreeSurface(screen);
 return 0;
}
