#pragma once

typedef struct Objet {
	SDL_Surface *sprite;
	int x,y;
} Objet;

void OBJET_Init(Objet *c, int x, int y,const char* path);
void OBJET_Render(Objet *c, SDL_Rect r, SDL_Surface **screen);
