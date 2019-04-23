#ifndef TEXT_H
#define TEXT_H
/**
* @struct Text
* @brief struct for Text
*/
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "voiture.h"
#include "background.h"

struct Text {
	SDL_Surface *textDt; /*!< Surface. */
	SDL_Surface *textPosition; /*!< Surface. */
	SDL_Surface *textVitesse; /*!< Surface. */
	SDL_Surface *textAcceleration; /*!< Surface. */
};
typedef struct Text Text;


void initText(Text *T);
int loadFont(TTF_Font **police);
void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,Voiture V,Background Bg,Uint32 dt);

#endif
