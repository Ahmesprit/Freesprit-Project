#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
typedef struct{
SDL_Rect posback;
SDL_Rect posbutgame;
SDL_Rect posbutsettings;
SDL_Rect posbutshop;
SDL_Rect posbutsound;
SDL_Rect posbutmusic;
SDL_Rect posbutcredits;
SDL_Rect posbutabout;
SDL_Rect posbuthelp;
SDL_Rect posbutquit;
}rectMenuComponents;

void showMenu(menuComponents mc, rectMenuComponents * rmc);
void showMap(backgroundMaps);
void showEnemy(enemy en);
void showObject(object o);
void showEngime(enigme e);
void showChar (character);
#endif
