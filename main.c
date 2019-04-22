/**
* @file main.c
*/



#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include"entite.h"

/*void setrects(SDL_Rect* clip , int LI , int HI , int frames )
{
int i ;

clip[0].x=0 ;
clip[0].y=0;
clip[0].w=LI;
clip[0].h=HI;
for (i=1;i<frames;i++)
{
clip[i].x=clip[i-1].x+LI;
clip[i].y=0;
clip[i].w=LI;
clip[i].h=HI;
}
}*/
int main()

{

ent E;
SDL_Rect rect1[6];
SDL_Rect position;
int continuer =1;
position.x=0;
position.y=0;
 SDL_Surface  *rotation = NULL;

    SDL_Rect rect;

    SDL_Event event;

    double angle = 0;

    double zoom = 1;

    int sens = 1;


    int tempsPrecedent = 0, tempsActuel = 0;
    int TEMPS=30;

   SDL_Surface* screen = NULL;

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
    screen = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE | SDL_RESIZABLE );



    SDL_Surface* backg = NULL;
    backg = IMG_Load("backgroundstage1.png");
    SDL_BlitSurface(backg, NULL, screen,& position);
    SDL_WM_SetCaption("animation enemy", NULL);
    SDL_Flip(screen);


OBJET_Init(&E,1000,200);
//setrects(rect1,153,139,6);
while(continuer)
{
/*animation_entite_droite(&E[0],rect1,screen,backg, position);
enemy_va_x(& E[0]);*/






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
        SDL_BlitSurface(backg , NULL, screen, &position);
        SDL_BlitSurface(rotation , NULL, screen, &E.dst);
        SDL_FreeSurface(rotation);

        if(zoom >= 2){sens = 0;}
        else if(zoom <= 0.5)
             {
                 sens = 1;
             }

        if(sens == 0){zoom -= 0.02;}
        else{zoom += 0.02;}

        SDL_Flip(screen);



}




}
