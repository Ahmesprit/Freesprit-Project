/**
* @file voiture.c
* @brief this is the voiture file
* @author hedi 
* 
*/
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "voiture.h"
#include "background.h"
#include <stdio.h>
/**
* @brief To load voiture images.
* @param A  type structure voiture
* @return -1 or 0
*/
int loadVoitureImages(Voiture * A)
{
	int i;
	char buf[50];
	char buf0[]="voiture";
	char bmp[]=".bmp";
	for(i=0; i<4; i++) {
		sprintf(buf,"%s%d%s",buf0,i,bmp);
		A->image[i] = SDL_LoadBMP(buf);
		if (A->image[i]== NULL) {
			printf("Unable to load  Voiture bitmap:\n");
			return (-1);
		}
		// set the color of Voiture background (white color) as transparent
		SDL_SetColorKey( A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 255, 255, 255) );
	}
	return(0);
}
/**
* @brief To initialize the car.
* @param A type structure voiture
* @return nothing
*/
void initVoiture(Voiture *A)
{
	A->direction=0;
	A->position.x=0;
	A->position.y=SCREEN_H - A->image[0]->h;
	A->position.w=A->image[0]->w;
	A->position.h=A->image[0]->h;
	A->score=0;
	A->vie=5;
	A->velocity=0; //velocity=0
	A->acceleration=0;
	A->Mass=70;
	A->moving=0;
}
/**
* @brief To move the car .
* @param A type structure voiture
* @param B the background
* @pram dt the time 
* @return nothing
*/
void moveVoiture(Voiture *A,Background *B,Uint32 dt)
{int done=0;
int Tab_input[SDLK_RIGHT];
SDL_Surface *car;
if(Tab_input[SDLK_RIGHT])
A->position.x+=10;
dt=60;
}
/**
* @brief To free the voiture space.
* @param A type structure voiture
* @return nothing
*/
void freeVoiture(Voiture *A)
{
	int i;
	for(i=0; i<4; i++)
		SDL_FreeSurface(A->image[i]);
}
