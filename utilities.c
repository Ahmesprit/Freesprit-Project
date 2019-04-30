#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "utilities.h"
#include <time.h>
#include "character.h"
#include <math.h>

int detectCollTrig (SDL_Rect rect1, SDL_Rect rect2){
float X1,R2,Y1,X2,R1,Y2,D1,D2;

X1 = rect1.x + (rect1.w/2);
 Y1 = rect1.y + (rect1.h/2);
 if(rect1.w < rect1.h){
	 R1 = rect1.w/2;
 } else{
	 R1 = rect1.h/2;
 }

X2 = rect2.x + (rect2.w/2);
 Y2 = rect2.y + (rect2.h/2);
 if(rect2.w < rect2.h){
 	R2 = rect2.w/2;
 } else{
 	R2 = rect2.h/2;
 }

D1=  sqrt(((X1-X2)*(X1-X2))+((Y1-Y2)*(Y1-Y2)));
D2=R1+R2;

  if (D1<=D2)
       {
        return 1;
       }
  else
    {return 0;
    }
}
int detectCollBB (SDL_Rect Personnage , SDL_Rect Ennemi) {
if (((Personnage.x+ Personnage.w)< Ennemi.x ) || (Personnage.x > (Ennemi. x + Ennemi. w)) ||
 ((Personnage.y + Personnage.h) < Ennemi.y ) || (Personnage.y > (Ennemi. y + Ennemi. h))){
         return 0;
}else{
         return 1;
}
}
SDL_Color GetPixel (SDL_Surface* pSurface, int x, int y, SDL_Surface * screen){
  SDL_Color color;
  Uint32 col = 0;
  char *pPosition = (char*) screen -> pixels;
  pPosition += (screen -> pitch * y);
  pPosition += (screen->format->BytesPerPixel * x);
  memcpy (&col, pPosition, screen->format->BytesPerPixel);
  SDL_GetRGB (col, screen->format, &color.r, &color.g, &color.b);
  return color;
}
int detectCollPP (SDL_Surface * BackgroundMasque, charac Personnage,SDL_Surface * screen){
  SDL_Color colobs ={0,0,0,0};
  SDL_Color colenigme ={255,0,0};
  SDL_Color colladder ={0,255,0};
  SDL_Color colgotten;
  positionPers Pos [8];
int collision = 0, i = 0;
  Pos[0].x = Personnage.positionChar.x;
  Pos[0].y = Personnage.positionChar.y;
  Pos[1].x = Personnage.positionChar.x + (Personnage.spriteright[0]->w /2);
  Pos[1].y = Personnage.positionChar.y;
  Pos[2].x = Personnage.positionChar.x + Personnage.spriteright[0]->w;
  Pos[2].y = Personnage.positionChar.y;
  Pos[3].x = Personnage.positionChar.x;
  Pos[3].y =  Personnage.positionChar.y + (Personnage.spriteright[0]->h/2);
  Pos[4].x = Personnage.positionChar.x;
  Pos[4].y = Personnage.positionChar.y + Personnage.spriteright[0]->h;
  Pos[5].x = Personnage.positionChar.x + (Personnage.spriteright[0]->w /2);
  Pos[5].y =  Personnage.positionChar.y + Personnage.spriteright[0]->h;
  Pos[6].x = Personnage.positionChar.x + Personnage.spriteright[0]->w;
  Pos[6].y = Personnage.positionChar.y + Personnage.spriteright[0]->h;
  Pos[7].x = Personnage.positionChar.x + Personnage.spriteright[0]->w;
  Pos[7].y = Personnage.positionChar.y + (Personnage.spriteright[0]->h/2);
while (i<=7) {
  colgotten = GetPixel(BackgroundMasque, Pos[i].x, Pos[i].y, screen);
printf("=========\n");
printf("R:%d G:%d B:%d\n", colgotten.r, colgotten.g, colgotten.b);
    if ((colobs.r == colgotten.r) &&  (colobs.b == colgotten.b) &&
    (colobs.g == colgotten.g)){
       collision = 1;
       return collision;
    }else{
      if ((colenigme.r == colgotten.r) &&  (colenigme.b == colgotten.b) &&
      (colenigme.g == colenigme.g)){
         collision = 2;
         return collision;
      }else{
        if ((colladder.r == colgotten.r) &&  (colladder.b == colgotten.b) &&
        (colladder.g == colladder.g)){
           collision = 3;
           return collision;
        }else{

        }
      }
    }
    i++;
}
return collision = 0;
}
void scrolling (SDL_Rect * camera, SDL_Event event){

        switch (event.key.keysym.sym){

	case SDLK_RIGHT:
       camera->x = camera->x + 30;
	break;

	case SDLK_LEFT:
       camera->x = camera->x - 30;
	break;
 }
}
SDL_Surface * gameTime (timer *t) {
  char tim[8];
  SDL_Surface * timetext;
  SDL_Delay(1);
  if (t->ticker==60) {
     t->ticker = 0;
      t->sec--;
      if(t->sec == -1){
        t->sec = 59;
        t->min--;
      }
  }else {
     t->ticker++;
  }
if (TTF_Init() < 0) {
  printf("error\n");
}else{
TTF_Font * police = NULL;
SDL_Color noir = {255, 255, 255};
police = TTF_OpenFont("Bebas-Regular.ttf", 32);
if (police == NULL) {
  printf("error in font time\n");
}else{
  if(t->sec < 10){
    sprintf(tim, "0%d : 0%d", t->min, t->sec);
  }else{
sprintf(tim, "0%d : %d", t->min, t->sec);
}
timetext = TTF_RenderText_Solid(police, tim, noir);
TTF_CloseFont(police);
TTF_Quit();
}
}
return timetext;
}
