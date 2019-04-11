#ifndef SCRO_H_INCLUDED
#define SCRO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <time.h>


void scrolling (SDL_Rect * camera, SDL_Event event);

#endif
