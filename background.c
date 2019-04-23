/**
* @file background.c
* @brief this is the background file
* @author hedi 
* 
*/
#include "background.h"
/**
* @brief To load the background .
* @param backg the background
* @return -1 or 0
*/
int loadBackground(Background *Backg)
{
	// load background
	Backg->backgroundImg = SDL_LoadBMP("../images/background.bmp");
	if (Backg->backgroundImg == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}

	Backg->backgroundCollide = SDL_LoadBMP("../images/background.bmp");
	if (Backg->backgroundCollide == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return (-1);
	}
	return (0);
}

/**
* @brief To initialize the background .
* @param backg the background
* @return nothing
*/

void initBackground(Background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;
	Backg->backgroundPos.w=SCREEN_W;
	Backg->backgroundPos.h=SCREEN_H;
}
/**
* @brief To blit the background .
* @param backg the background
* @param screen the surface
* @return nothing
*/
void blitBackground(Background*Backg,SDL_Surface *screen)
{

	if(Backg->backgroundPos.x>Backg->backgroundImg->w-SCREEN_W)
		Backg->backgroundPos.x=0;
	if(Backg->backgroundPos.x<0)
		Backg->backgroundPos.x=Backg->backgroundImg->w-SCREEN_W;
	SDL_BlitSurface(Backg->backgroundImg, &(Backg->backgroundPos), screen,NULL); 

}
/**
* @brief To free the background .
* @param backg the background
* @return nothing
*/
void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}
