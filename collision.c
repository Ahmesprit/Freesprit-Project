#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "collision.h"
#include <math.h>
 
int detectCollCir ( SDL_Surface *obj1 , SDL_Surface *obj2, SDL_Rect posobj1, SDL_Rect posobj2){

int opp,adj,hyp;
 adj = abs(posobj1.y-posobj2.y);	
opp = abs(posobj1.x-posobj2.x); 
hyp = sqrt(pow(opp,2)) + sqrt(pow(adj,2));
if (hyp == 0){
   return 1;
}else{
   return 0 ;
 }
}

int detectCollBB(SDL_Surface *image, SDL_Rect position){

}

