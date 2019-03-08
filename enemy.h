#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

typedef struct {
 SDL_Surface *e;
 SDL_Rect posEnm;
}enemy;

enemy initEnm ();
void showEnm(enemy enm, SDL_Surface * screen);

#endif
