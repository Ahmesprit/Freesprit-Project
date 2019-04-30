#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <time.h>
#include "character.h"
#include <math.h>

typedef struct {
  int x;
  int y;
}positionPers;
typedef struct {
int sec;
int min;
int ticker;
}timer;
SDL_Color GetPixel (SDL_Surface* pSurface,int x, int y,SDL_Surface * screen);
SDL_Surface * gameTime (timer *t);
int detectCollTrig (SDL_Rect rect1, SDL_Rect rect2);
int detectCollPP (SDL_Surface * BackgroundMasque, charac Personnage, SDL_Surface * screen);
int detectCollBB (SDL_Rect Personnage , SDL_Rect Ennemi) ;
void scrolling (SDL_Rect * camera, SDL_Event event);
#endif
