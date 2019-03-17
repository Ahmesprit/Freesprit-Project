#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "SDL/SDL_ttf.h"

typedef struct{
  SDL_Surface * back;
  FILE * f;
}enigme;

void initEnigme();
void showEnigme(enigme e);

#endif 
