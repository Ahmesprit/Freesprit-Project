#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "SDL/SDL_ttf.h"
#include <time.h>
typedef struct{
  SDL_Surface * back;
  FILE * f;
}enigme;
typedef struct {
  char quest [400];
  char c1[50];
 char c2[50];
 char c3[50];
 char x [50];
}enigmeData;
enigme initEnigme();
void showEnigme(enigmeData ed, SDL_Surface *screen, enigme e);
int randomize();
enigmeData generateEnigme(enigme e);
int resolutionEnigme(enigmeData ed, SDL_Event event);
#endif
