#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include <math.h>
#include "collision.h"
 
int detectCollCir ( SDL_Surface *obj1 , SDL_Surface *obj2, SDL_Rect rect1, SDL_Rect rect2){
float X1,R2,Y1,X2,R1,Y2,D1,D2;

X1 = rect1.x + (rect1.w/2);
 Y1 = rect1.y + (rect1.h/2);
 R1 = sqrt((rect1.w/2)*(rect1.w/2)+(rect1.h/2)*(rect1.h/2));

X2 = rect2.x + (rect2.w/2);
 Y2 = rect2.y + (rect2.h/2);
 R2 = sqrt((rect2.w/2)*(rect2.w/2)+(rect2.h/2)*(rect2.h/2));

D1=  sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
D2=R1+R2;

  if (D1<=D2)
       {
        return 1;
       }
  else
    {return 0;
    }
}
