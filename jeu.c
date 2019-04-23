/**
* @file jeu.c
* @brief this is the main file
* @author hedi 
* 
*/
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "defs.h"
#include "background.h"
#include "voiture.h"
#include "jeu.h"
#include "text.h"
#include <time.h>

/**
* @brief To make everything .
* @param screen the surface
* @return 0 or -1
*/
int jouer(SDL_Surface * screen)
{
	int done = 0;
	int i=0;
	Uint32 t_prev, dt=1; 
	
	Voiture car;
	Background Backg;
	Text txt;
	
	SDL_Event event;
      int keysHeld[323]={0};
TTF_Font *police=NULL;
if (loadVoitureImages(&car)==-1){
		printf("Erreuer Chargement Voiture Images\n");
		return(-1);

	}

	if(loadBackground(&Backg) == -1) {
		printf("Erreuer Chargement Background Images\n");
		return(-1);
	}
	
	if(loadFont(&police) == EXIT_FAILURE){
		printf("Erreuer Chargement Font ttf\n");
		return(-1);
	}

	initBackground(&Backg);
	initVoiture(&car);
	initText(&txt);

	// program Game loop
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


	while(!done) {
          t_prev=SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			// check for messages
			switch (event.type) {
				// exit if the window is closed
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				car.moving=1; //lets move
				keysHeld[event.key.keysym.sym] = 1;
				break;
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = 0;
				car.moving=0;
				car.velocity=0;
				break;
			}
          t_prev=SDL_GetTicks();
			// exit if ESCAPE is pressed
			if (keysHeld[SDLK_ESCAPE])
				done = 1;
			if(keysHeld[SDLK_SPACE]) {                   
				car.velocity=6;
				car.direction=0;//right direction
	                        car.acceleration=10;

				moveVoiture(&car,&Backg,dt);
                                  	
				i++;


			}
if(1000/FPS>dt)
SDL_Delay(1000/FPS-dt);
		} // end of message processing
		i=i%4;
		//Blit the bachground to the backbuffer
		blitBackground(&Backg,screen);

		//Blit Voiture to screen
		if(!car.moving)
			i=0;
		if(car.direction == 0)
			SDL_BlitSurface(car.image[i],NULL,screen,&car.position);
			
		displayText(police,&txt,screen,car,Backg,0);
		
		SDL_Flip(screen);
		
		
		
	}

	                // free loaded bitmap

	freeVoiture(&car);
	freeBackground(&Backg);
	TTF_CloseFont(police);
	return(0);
}

