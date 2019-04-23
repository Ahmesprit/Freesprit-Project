#ifndef BACKGROUND_H
#define BACKGROUND_H
/**
* @struct Background
* @brief struct for Background
*/
#include <SDL/SDL.h>
#include "defs.h"

struct Background{
	SDL_Surface *backgroundImg; /*!< Surface. */
	SDL_Surface *backgroundCollide; /*!< Surface. */
	SDL_Rect backgroundPos; /*!< Rectangle*/
};
typedef struct Background Background;

int loadBackground(Background *Backg);
void initBackground(Background *Backg);
void freeBackground(Background *Backg);
void blitBackground(Background*Backg,SDL_Surface *screen);

#endif
