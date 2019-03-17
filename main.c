#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "background.h"
#include "collision.h"
#include "object.h"
#include "management.h"
#include "mouvement.h"
#include "character.h"
#include "enigme.h"
#include "enemy.h"

int main(){
menuComponents mc;
menuPosComponents mpc;
soundClicks sc;
butControl bc;
bc.sound = 0; //false: button sound not pressed yet
bc.music = 0; //false: button music not pressed yet
SDL_Surface *screen;
Mix_Music * music;
char pause;
SDL_Event event;
int done=0;
//initializing the screen
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initializeSDL:%s \n",SDL_GetError());
	return 1;
}

screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
	printf("No sounds %s\n",Mix_GetError());
        return 1;
}
//initializing menu and music
initSound(&music, &sc);
Mix_PlayMusic(music,-1);
initMenu(&mc, &mpc);
showMenu(&mc, &mpc, screen);
//Game loop starts
while (done == 0){
 while(SDL_PollEvent(&event) == 1){
      switch(event.type){
           case SDL_KEYDOWN:
             if(event.key.keysym.sym == SDLK_UP){
                 done = 1;
             }
           break;
           case SDL_MOUSEMOTION:
                menuMotion(&mc, &mpc, screen, &event, bc, &sc);
           break;
           case SDL_MOUSEBUTTONDOWN:
                menuClicks(&mc, &mpc, screen, &event, music, &sc, &bc);
              break;
}
}
}
SDL_FreeSurface(screen);
Mix_FreeMusic(music);
pause=getchar();
SDL_Quit();
return 0;
}
