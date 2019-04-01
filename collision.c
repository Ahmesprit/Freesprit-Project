#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "collision.h"
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
if (((Personnage.x+ Personnage.w)< Ennemi. x ) || (Personnage.x > (Ennemi. x + Ennemi. w)) ||
 ((Personnage.y + Personnage.h) < Ennemi. y ) || (Personnage.y > (Ennemi. y + Ennemi. h))){
         return 0;
}else{
         return 1;
}
}
SDL_Color GetPixel (SDL_Surface* pSurface, int x, int y){
  SDL_Color color;
  Uint32 col = 0;
  char *pPosition = (char*) pSurface -> pixels;
  pPosition += (pSurface -> pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col, pPosition, pSurface->format->BytesPerPixel);
  SDL_GetRGB (col, pSurface->format, &color.r, &color.g, &color.b);
  return (color);
}
int detectCollPP (SDL_Surface * BackgroundMasque, SDL_Rect Personnage){
  SDL_Color colobs ={0,0,0} ;
  SDL_Color colgotten;
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
  colgotten = GetPixel(BackgroundMasque, Pos[i].x, Pos[i].y);
while ((i<=7) && (collision == 0)) {
    if ((colobs.r == colgotten.r) &&  (colobs.b == colgotten.b) &&
  (colobs.g == colgotten.g)){
       collision = 1;
    }else{
      i++;
    }
}
return collision;
}
