#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "scro.h"
#include <string.h>
void scrolling (SDL_Rect * camera, SDL_Event event){

        switch (event.key.keysym.sym){

	case SDLK_RIGHT:
       camera->x = camera->x + 20;
               if(camera->x >= 4264-960){
                          camera->x = 0;
               }
	break;

	case SDLK_LEFT:
       camera->x = camera->x - 20;
               if(camera->x <= 4264-960){
                          camera->x = 0;
               }
	break;
 }
}
