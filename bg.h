#ifndef BG_H_INCLUDED
#define BG_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

typedef struct {
   SDL_Surface *map;
   SDL_Surface *mask;
   SDL_Surface * splash;
   SDL_Rect splashPos;
   SDL_Rect posMap;
}backgroundMaps;


backgroundMaps initMaps();
void showMaps(backgroundMaps bm, SDL_Surface *screen);

#endif
