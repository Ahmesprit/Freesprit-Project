#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>


/**
* @struct ent
* @brief struct for the entity
*/


typedef struct ent {
	SDL_Surface *image_entite;
	int x,y;
	SDL_Rect dst;
} ent;
void OBJET_Init(ent *E, int x, int y);
void rotation_enemy(ent E, SDL_Surface* ecran,SDL_Surface *backg,SDL_Rect positionFond);



#endif // ENTITE_H_INCLUDED
