#ifndef MOUVEMENT_H_INCLUDED
#define MOUVEMENT_H_INCLUDED

void moveKeyboard (SDL_Surface *screen, SDL_Event event, SDL_Rect * posobj, SDL_Surface * obj, SDL_Surface *back, SDL_Rect *posback, SDL_Rect *camera);
void scrolling (SDL_Surface *back, SDL_Rect * camera, SDL_Event, SDL_Surface *screen);
#endif
