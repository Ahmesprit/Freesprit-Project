#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

typedef struct {
 SDL_Surface * spriteleft;
 SDL_Surface * spriteright;
}charac;
typedef struct{
  SDL_Rect pmax;
  SDL_Rect pmin;
  SDL_Rect position;
}characPos;

charac initChar ();
void showChar(characPos *cp, charac c, SDL_Surface * screen);
void animChar (charac * c, characPos cp, SDL_Surface *screen, SDL_Event event);
void moveChar (SDL_Event event, SDL_Rect *posobj);
#endif
