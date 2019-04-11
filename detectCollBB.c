#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
 #include <stdbool.h>
 #include "detectCollBB.h"
bool detectCollBB( SDL_Surface *Player , SDL_Surface *C_Object , SDL_Rect position , SDL_Rect position1  )
 {
	 
	 if (((position.x+position.w < position1.x)||(position.y+position.h<position1.y))  || ((position.x >position1.x + position1.w)||(position.y+position.h>position1.y+position1.h)))
     {
		 return true ; 
	 }
   else 
return false ; 
	 
	 
}
