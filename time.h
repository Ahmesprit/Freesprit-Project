#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>





typedef struct
{
        SDL_Surface * temps;
	SDL_Rect position_temps;

	int heure;

	int minute;

	int seconde;


	TTF_Font *police;

	int tempsactuel;
	int tempsprecedent;



}temps;


void afficher_chrono();


#endif // TIME_H_INCLUDED
