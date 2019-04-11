#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

typedef struct {
 SDL_Surface *obj;
 SDL_Rect posObj;
}object;

object initObj ();
void showObj(object o, SDL_Surface * screen);

#endif
