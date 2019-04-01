#ifndef MANAGEMENT_H_INCLUDED
#define MANAGEMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <time.h>
typedef struct {
int sec;
int min;
}timer;
SDL_Surface * updateScore(int *score, SDL_Surface *screen);
SDL_Surface * updateLives(int *lives, SDL_Surface *hearts);
SDL_Surface * gameTime (timer *t);
void scrolling (SDL_Rect * camera, SDL_Event event);
#endif
