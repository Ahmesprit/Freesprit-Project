

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "bg.h"



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

int main() {
int done=0;
SDL_Event event;
  
SDL_Surface *screen;
backgroundMaps bm;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL:%s \n",SDL_GetError());

return 1;
}
screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

SDL_WM_SetCaption("Freesprit", NULL);
bm = initMaps();
showMaps(bm, screen);

while(done!=1)
{

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
	{
		case SDL_QUIT:
		done=1;
	break;
	case SDL_KEYDOWN:
	{
	if (event.key.keysym.sym==SDLK_ESCAPE)
	done=1;
	
		break;
	}
	}
	}
SDL_BlitSurface(bm.map, NULL, screen, &bm.posMap);
SDL_Flip(screen);
}

SDL_FreeSurface(screen);
SDL_Quit();
return 0;
}
