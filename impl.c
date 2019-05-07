/**
* @file imp.c
*/
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "impl.h"

/**
* @brief To initialize head position 
* @param headpos
* @return Nothing
*/
void onMap(SDL_Event event, SDL_Rect *headPos, SDL_Rect obj){
  obj.x = obj.x + 480;
     headPos->x = (float)(obj.x * 789)/15984;
}

/**
* @brief To do the scrolling 
* @param camera
* @param headpos
* @param camera
* @return Nothing
*/
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
