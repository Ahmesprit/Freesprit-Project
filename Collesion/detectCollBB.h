#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h" 
#include <stdbool.h>
bool detectCollBB( SDL_Surface *image , SDL_Surface *image1 , SDL_Rect position , SDL_Rect position1  );
 
#endif

