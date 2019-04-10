#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "collpp.h"
//renvoie la couleur d’un pixel sur une surface //
SDL_Color GetPixel (SDL_Surface* pSurface, int x, int y){
  SDL_Color color;
  Uint32 col = 0;
//Determine position
  char *pPosition = (char*) pSurface -> pixels;
  pPosition += (pSurface -> pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col, pPosition, pSurface->format->BytesPerPixel);
//Determine position
  SDL_GetRGB (col, pSurface->format, &color.r, &color.g, &color.b);
  return (color);
}
int detectCollPP (SDL_Surface * BackgroundMasque, SDL_Rect Personnage){
  typedef struct{
    int x;
    int y;
  }positionPers;
//init couleur de l obs//
  SDL_Color colobs ={0,0,0} ;
// colorgotten :pixel du mas
  SDL_Color colgotten;
//init pos perso//
  positionPers Pos [8];
int collision = 0, i = 0;
  Pos[0].x = Personnage.x;
  Pos[0].y = Personnage.y;
  Pos[1].x = Personnage.x + (Personnage.w /2);
  Pos[1].y = Personnage.y;
  Pos[2].x = Personnage.x + Personnage.w;
  Pos[2].y = Personnage.y;
  Pos[3].x = Personnage.x;
  Pos[3].y =  Personnage.y + (Personnage.h/2);
  Pos[4].x = Personnage.x;
  Pos[4].y = Personnage.y + Personnage.h;
  Pos[5].x = Personnage.x + (Personnage.w /2);
  Pos[5].y =  Personnage.y + Personnage.h;
  Pos[6].x = Personnage.x + Personnage.w;
  Pos[6].y = Personnage.y + Personnage.h;
  Pos[7].x = Personnage.x + Personnage.w;
  Pos[7].y = Personnage.y + (Personnage.h/2);
  
while ((i<=7) && (collision == 0)) {
colgotten = GetPixel(BackgroundMasque, Pos[i].x, Pos[i].y);
    if ((colobs.r == colgotten.r) || (colobs.b == colgotten.b) ||
  (colobs.g == colgotten.g)){
       collision = 1;
    }else{
      i++;
    }
}
return collision;
}

backgroundMaps initMaps(){
backgroundMaps bm;
   bm.map = IMG_Load("backgroundstage1.png");
	 bm.mask = SDL_LoadBMP("masque.bmp");

   bm.posMap.x=0;
bm.posMap.y=0;
bm.posMap.w=960;
bm.posMap.h=600;
 return bm;
}
void showMaps(backgroundMaps bm, SDL_Surface *screen){
 
  SDL_BlitSurface(bm.map,NULL, screen, &bm.posMap);
}
void deplacementSouris(SDL_Surface *screen,SDL_Surface *perso ,SDL_Rect * persoPos, SDL_Event event){
  switch(event.type){
         case SDL_MOUSEBUTTONDOWN:
             if(event.button.button == SDL_BUTTON_LEFT){
              persoPos->x = event.button.x;
             persoPos->y = event.button.y;
           }
         break;
}
}
void depKeyboard (SDL_Rect* persoPos, SDL_Event event){
  switch (event.key.keysym.sym){
         case SDLK_UP:
          persoPos->y-=10;
  break;
         case SDLK_DOWN:
         persoPos->y+=10;
  break;

  case SDLK_RIGHT:
         persoPos->x+=10;
  break;
  case SDLK_LEFT:
          persoPos->x-=10;
  break;
   }
}
int main() {
  int mode; // 0 pours souris 1 pour clavier
  printf("donner le mode de jeux\n");
  scanf("%d", &mode);
SDL_Surface *screen;
backgroundMaps bm;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL:%s \n",SDL_GetError());
return 1;
}
screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Freesprit", NULL);
int done = 0;
SDL_Surface * perso;
SDL_Rect persoPos;
SDL_Event event;
bm = initMaps();
showMaps(bm, screen);
perso = IMG_Load("soso.png");
persoPos.x = 0; persoPos.y = 0;
SDL_EnableKeyRepeat(20,10);
persoPos.h = perso->h; persoPos.w = perso->w;
SDL_BlitSurface(perso, NULL, screen, &persoPos);
SDL_Flip(screen);
while(done == 0){
  while(SDL_PollEvent(&event) == 1){
    if(mode == 0){
    deplacementSouris(screen,perso ,&persoPos,event);
    }else{
    depKeyboard(&persoPos, event);
 }
 SDL_BlitSurface(bm.map, NULL, screen, &bm.posMap);
SDL_BlitSurface(perso, NULL, screen, &persoPos);
SDL_Flip(screen);
if(detectCollPP(bm.mask, persoPos) == 1){
  
  done = 1;
}
}
}
//end game loop
SDL_FreeSurface(screen);
SDL_Quit();
return 0;
}
