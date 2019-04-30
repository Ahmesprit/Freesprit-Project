#ifndef MENUBUTTON_H_INCLUDED
#define MENUBUTTON_H_INCLUDED
#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "character.h"
typedef struct{
SDL_Surface *back;
SDL_Surface * backbut;
SDL_Surface * sound;
SDL_Surface * sound2;
SDL_Surface * music;
SDL_Surface * music2;
SDL_Surface * joy;
SDL_Surface * key;
SDL_Surface * mou;
SDL_Rect backPos;
SDL_Rect backbutPos;
SDL_Rect soundPos;
SDL_Rect musicPos;
SDL_Rect mode;
}settings;
typedef struct{
  SDL_Surface * back;
  SDL_Surface * backbut;
  SDL_Rect backPos;
  SDL_Rect backbutPos;
}credits;
typedef struct{
  SDL_Surface * back;
  SDL_Surface * backbut;
  SDL_Rect backPos;
  SDL_Rect backbutPos;
}help;
typedef struct{
  int sound;
  int music;
  int mode;
}backup;
typedef struct{
  SDL_Surface * back;
  SDL_Surface * backwarning;
  SDL_Surface * backerror;
  SDL_Rect backPos;
  SDL_Surface * backbut;
  SDL_Rect backbutPos;
}shop;

backup restore();
settings initSettings();
void showSettings(settings set, SDL_Surface *screen, backup b);
int clicksSettings (settings set, SDL_Event event);
credits initCredits();
void showCredits(credits cred, SDL_Surface * screen);
int clicksCredits(credits cred, SDL_Event event);
help initHelp();
void showHelp(help h, SDL_Surface * screen);
int clicksHelp(help h, SDL_Event event);
shop initShop();
void showShop(shop sh, SDL_Surface * screen, state sta);
int clicksShop(shop sh, SDL_Event event, state *sta, SDL_Surface *screen);

#endif
