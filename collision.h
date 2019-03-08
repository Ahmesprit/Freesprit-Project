#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

int detectCollCir (SDL_Surface *obj1 ,SDL_Surface *obj2, SDL_Rect posobj1, SDL_Rect posobj2);
int detectCollBB(SDL_Surface *image, SDL_Rect position);
#endif
