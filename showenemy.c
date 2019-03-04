#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"


 SDL_Surface *ecran 

typedef struct Input Input;
 
void UpdateEvent(Input *in);
 
struct Input {
    char key[SDLK_LAST];
};
 
int main ( int argc, char** argv )
{
    SDL_Surface *ecran = NULL, *mario = NULL;
    SDL_Rect positionMario;
 
    int continuer = 1;
    Input in;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Essais Mario", NULL);
 
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran -> format, 255, 255, 255));
 
    // Chargement de Mario de base
    mario = IMG_Load("mario123.png");
 
    // Position de mario
    positionMario.x = (ecran -> w / 2) - (mario -> w / 2);
    positionMario.y = (ecran -> h / 2) - (mario -> h / 2);
 
    // Affichage de mario
    SDL_BlitSurface(mario, NULL, ecran, &positionMario);
    SDL_Flip(ecran);
 
