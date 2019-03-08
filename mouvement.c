#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "mouvement.h"
#include <math.h>

//you must add '-lm' in terminal to link file
void moveKeyboard (SDL_Surface *screen, SDL_Event event, SDL_Rect *posobj, SDL_Surface *obj, SDL_Surface *back, SDL_Rect *posback, SDL_Rect *camera){
switch (event.key.keysym.sym){
       case SDLK_UP:
        posobj->y-=50;
	break;

       case SDLK_DOWN:
       posobj->y+=50;
    
	break;
     
	case SDLK_RIGHT:
       posobj->x+=50;

	break;

	case SDLK_LEFT:
       posobj->x-=50;
	break;
 }
SDL_BlitSurface(back, camera, screen, NULL);
SDL_Flip(screen);
SDL_BlitSurface(obj, NULL, screen, posobj);
SDL_Flip(screen);

}
void scrolling (SDL_Surface *back, SDL_Rect * camera, SDL_Event event, SDL_Surface *screen){
 
        switch (event.key.keysym.sym){

	case SDLK_RIGHT:
       camera->x = camera->x + 50;
               if(camera->x >= 4267-960){
                          camera->x = 0; 
               }
	break;

	case SDLK_LEFT:
       camera->x = camera->x - 50;
               if(camera->x >= 4267-960){
                          camera->x = 0; 
               }
	break;
 }
      SDL_BlitSurface(back, camera, screen, NULL);
              SDL_Flip(screen);
}
