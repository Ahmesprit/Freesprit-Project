#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
typedef struct {
  int x;
  int y;
}positionPers;
int detectCollTrig (SDL_Rect rect1, SDL_Rect rect2);
int detectCollPP (SDL_Surface * BackgroundMasque, SDL_Rect Personnage);
int detectCollBB (SDL_Rect Personnage , SDL_Rect Ennemi) ;
#endif
