#include <stdio.h>
#include "SDL/SDL_image.h"
#include"SDL/SDL.h"


int main(void)
{
char pause;
SDL_Surface *screen;
SDL_Surface *image;
SDL_Rect positionecran;
SDL_Rect positiondetc;
int done=0;
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("unable to initializeSDL:%s \n",SDL_GetError());
	return 1;
}

screen = SDL_SetVideoMode(800,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


if (screen==NULL)
{	
	printf("unable to load bitmap %s\n",SDL_GetError());
	return 1;
}
image=SDL_LoadBMP("background.bmp");
if (image==NULL)
{	
	printf("unable to load background  image %s\n",SDL_GetError());
	return 1;
}

positionecran.x=0;
positionecran.y=0;
positionecran.w=image->w;
positionecran.h=image->h;

SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_Flip(screen);
}
SDL_FreeSurface(image);
pause=getchar();
return 0;
}
