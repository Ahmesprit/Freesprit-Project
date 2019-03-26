#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "enemy.h"

int main(int argc, char** argv)
{
    SDL_Surface* screen = NULL;

	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
	screen = SDL_SetVideoMode(W_Screen, H_Screen, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE | SDL_RESIZABLE );
	enemy e;
    
    SDL_Surface* bg = NULL;
    backg = IMG_Load("index.jpeg");
    SDL_BlitSurface(bg, NULL, screen, NULL);
    SDL_WM_SetCaption("animation enemy", NULL);
    SDL_Flip(screen);

	//e.spriteleft = IMG_Load("l.png");
	e.spriteright = IMG_Load("r.png");
	e.dst.x = 0;
	e.dst.y = 0;

	SDL_ShowCursor(SDL_DISABLE);
	int c = 1;
	while(c)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		int i;

		for(i = 0; i<MAX_FRAMES; i++)
		{
			e.frame.x = i*(Sint16)SPRITE_W;
			e.frame.y = 0;
			e.frame.w = SPRITE_W;
			e.frame.h = SPRITE_H;
			SDL_BlitSurface(bg, NULL, screen, NULL);
			SDL_BlitSurface(e.spriteright, &e.frame, screen, &e.dst);
			SDL_Flip(screen);
			SDL_Delay(500);
		}
		for(i = (MAX_FRAMES - 1); i>=0; i--)
		{
			e.frame.x = i*(Sint16)SPRITE_W;
			e.frame.y = 0;
			e.frame.w = SPRITE_W;
			e.frame.h = SPRITE_H;
			SDL_BlitSurface(bg, NULL, screen, NULL);
			SDL_BlitSurface(e.spriteleft, &e.frame, screen, &e.dst);
			SDL_Flip(screen);
			SDL_Delay(500);
		}

		switch(event.type)

		{            case SDL_QUIT:
                               c = 0;
                               break;
			case SDL_KEYDOWN:
			    if(event.key.keysym.sym == SDLK_ESCAPE)
			    {
			    	c = 0;
			    }
                       


		}

	}
	SDL_Quit();
return 0;
}
