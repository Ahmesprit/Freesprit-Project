#ifndef COLLPP_H_INCLUDED
#define COLLPP_H_INCLUDED
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

SDL_Color GetPixel (SDL_Surface* pSurface, int x, int y);
int detectCollPP (SDL_Surface * BackgroundMasque, SDL_Rect Personnage);
backgroundMaps initMaps();
void showMaps(backgroundMaps bm, SDL_Surface *screen);
void deplacementSouris(SDL_Surface *screen,SDL_Surface *perso ,SDL_Rect * persoPos, SDL_Event event);
void depKeyboard (SDL_Rect* persoPos, SDL_Event event);
#endif
