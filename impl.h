#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

/**
* @struct Background
* @brief struct for backround
*/
void onMap(SDL_Event event, SDL_Rect *headPos, SDL_Rect obj);
void scrolling (SDL_Rect * camera, SDL_Event event, SDL_Rect *headPos, SDL_Rect obj);
