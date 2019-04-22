#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "impl.h"
void onMap(SDL_Event event, SDL_Rect *headPos, SDL_Rect obj){
  switch (event.key.keysym.sym){
case SDLK_RIGHT:
     headPos->x = headPos->x + 1;
     break;
case SDLK_LEFT:
     headPos->x = headPos->x - 1;
     break;
}
}
void scrolling (SDL_Rect * camera, SDL_Event event, SDL_Rect *headPos, SDL_Rect obj){
        switch (event.key.keysym.sym){
	case SDLK_RIGHT:
       camera->x = camera->x + 100;
	break;
	case SDLK_LEFT:
       camera->x = camera->x - 100;
	break;
 }
}
