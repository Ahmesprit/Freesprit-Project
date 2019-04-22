/**
* @file rotozoom.c
*/


#include"entite.h"
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include<time.h>
#include <SDL/SDL_rotozoom.h>

/**
* @brief initialize the object  .
* @param E entity
* @param x abcisse
* @param y ordonnée
* @return Nothing
*/


void OBJET_Init(ent *E, int x, int y){
	E->image_entite = IMG_Load("enemy.png");
	E->x = x;
	E->y = y;
}


/**
* @brief rotation et zoom de l'entite  .
* @param E entite
* @param ecran l'ecran
* @param backg background
* @param positionFond
* @return Nothing
*/


void rotation_enemy(ent E, SDL_Surface* ecran,SDL_Surface *backg,SDL_Rect positionFond)
{
    SDL_Surface  *rotation = NULL;

    SDL_Rect rect;

    SDL_Event event;
    //E.image_entite = IMG_Load("VIE+.png");
    double angle = 0;
    double zoom = 1;
    int sens = 1;
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    int TEMPS=30;

while(continuer)

{

        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 2;
            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));

        }
        rotation = rotozoomSurface(E.image_entite, angle, zoom, 0);
       E.dst.x = 200;

       E.dst.y =  200;
        SDL_BlitSurface(backg , NULL, ecran, &positionFond);
        SDL_BlitSurface(rotation , NULL, ecran, &E.dst);
       SDL_FreeSurface(rotation);
        if(zoom >= 2){sens = 0;}
        else if(zoom <= 0.5)
             {
                 sens = 1;
             }
        if(sens == 0){zoom -= 0.02;}
        else{zoom += 0.02;}
        SDL_Flip(ecran);

   }
}
