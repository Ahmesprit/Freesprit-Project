/**
* @file main.c
* @brief Testing Program.
* @author Hedi
* @version 0.0
* @date Apr 16.04.2019
*/
#include "defs.h"
#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "defs.h"
#include "background.h"
#include "voiture.h"
#include "jeu.h"
#include "text.h"
#include <time.h>
int main ( int argc, char** argv )
{

	SDL_Surface *screen;
int done=0;
	// initialize SDL video
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "Unable to init SDL: %s\n", SDL_GetError() );
		return 1;
	}
	// make sure SDL cleans up before exit
	atexit(SDL_Quit);

	// create a new window
	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,SDL_HWSURFACE|SDL_DOUBLEBUF | SDL_SRCALPHA);
	if ( !screen ) {
		printf("Unable to set 600x300 video: %s\n", SDL_GetError());
		return 1;
	}





jouer(screen);



	


	// all is well ;)
	printf("Exited cleanly\n");
	return 0;
}


