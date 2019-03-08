#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

typedef struct {
 SDL_Surface *ch;
 SDL_Rect posChr;
 int lives;
}character;

character initChar ();
void showChar(character chr, SDL_Surface * screen);

#endif
