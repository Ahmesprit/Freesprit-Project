#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"


/**
* @struct object
* @brief struct for the object
*/

typedef struct {
 SDL_Surface *obj;  /*!< Surface. */
 SDL_Rect posObj; /*!< Rectangle*/
}object;

object initObj ();
void showObj(object o, SDL_Surface * screen);

#endif
