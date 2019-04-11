#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
void apply_surface (int x,int y, SDL_Surface* source, SDL_Surface* destination);
void inputInit(void);
void affichage();
void setrects(SDL_Rect* clip);



#endif
