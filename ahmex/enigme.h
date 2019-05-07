/**
* @file enigme.h
*/
#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "SDL/SDL_ttf.h"
#include <time.h>
/**
* @struct enigme
* @brief this struct is to set the basic entities of an enigma
*/
typedef struct{
  SDL_Surface * back; /*! this for the background image of the enigma*/
}enigme;
/**
* @struct enigmaData
* @brief this contains all the entities that are needed.
*/
typedef struct {
  char quest [400];/*!the question*/
  char enigma[400];/*! the enigma data*/
  char c1[50];/*! choice 1*/
  char c2[50];/*! choice 2*/
  char c3[50];/*! choice 3*/
  char x [50];/*! solution*/
}enigmeData;
enigme initEnigme();
void showEnigme(enigmeData ed, SDL_Surface *screen, enigme e);
int randomize();
enigmeData generateEnigme(enigme e);
int resolutionEnigme(enigmeData ed, SDL_Event event);
#endif
