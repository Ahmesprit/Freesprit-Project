#ifndef MENUBUTTON_H_INCLUDED
#define MENUBUTTON_H_INCLUDED
#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>

typedef struct{
SDL_Surface *settingsback;
SDL_Surface *butback;
SDL_Surface *buton1;
SDL_Surface *butoff1;
SDL_Surface *buton2;
SDL_Surface *butoff2;
SDL_Surface *butone1;
SDL_Surface *butone2;
SDL_Surface *buttwo1;
SDL_Surface *buttwo2;
SDL_Surface *butselection1;
SDL_Surface *butselection2;
}settingsComponents;

typedef struct{
SDL_Rect possettingsback;
SDL_Rect posbutback;
SDL_Rect posbuton;
SDL_Rect posbutoff;
SDL_Rect posbutone1;
SDL_Rect posbutone2;
SDL_Rect posbuttwo1;
SDL_Rect posbuttwo2;
SDL_Rect posbutselection1;
SDL_Rect posbutselection2;
}settingsPosComponents;

//for settings button
void initSettings(settingsComponents * setc, settingsPosComponents * spc);
void showSettings(settingsComponents * setc, settingsPosComponents * spc, SDL_Surface *screen);

// for
#endif
