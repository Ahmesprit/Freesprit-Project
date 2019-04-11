#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "detectCollBB.h"
 #include <stdbool.h>
int main()
{
SDL_Surface *screen , *image , *image1; 
SDL_Rect position , position1 ; 
SDL_Event event ; 
int done=0 ,x,y ; 




 if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode (1100 ,  900 , 16 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     } 
     SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  255 ,  255 ,  255 )); 
  
     image  =  IMG_Load( "koura.png" ); 
     if  ( image  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     position.x  =  50 ; 
     position.y  =  50 ; 
     position.w  =  image -> w ; 
     position.h  =  image -> h ; 
         SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen);
          image1  =  IMG_Load( "bn.png" ); 
     if  ( image1  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     position1.x  =  600 ; 
     position1.y  =  150; 
     position1.w  =  image1 -> w ; 
     position1.h  =  image1 -> h ; 
         SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
          


      while  ( done==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 done  =  1 ; 
                 break ;  
                 
             case SDL_KEYDOWN : 
                     switch( event.key.keysym.sym )
                        {
							case SDLK_RIGHT : 
							position.x+=50;
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  255 ,  255 ,  255 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen);
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
							break ; 
							case SDLK_LEFT : 
							position.x-=50 ;
							
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  255 ,  255,  255 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen); 
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
							break ; 
							case SDLK_UP : 
							position.y-=50 ;
							
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  255 ,  255 ,  255 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen); 
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
							break ; 
							case SDLK_DOWN  : 
						    position.y+=50;
						    
							    SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  255 ,  255 ,  255 )); 
							             SDL_BlitSurface(image, NULL, screen, &position);
          SDL_Flip(screen);
                   SDL_BlitSurface(image1, NULL , screen, &position1);
          SDL_Flip(screen);
        

							break ;
						}

 if (detectCollBB(image,image1,position,position1)==false)
 { 
printf("collesion \n");

	            SDL_Flip(screen);  

	 }
						  
break ;  
}
}
}



return 0 ; 
}
bool detectCollBB( SDL_Surface *image , SDL_Surface *image1 , SDL_Rect position , SDL_Rect position1  )
 {
	 
	 if (((position.x+position.w < position1.x)||(position.y+position.h<position1.y))  || ((position.x >position1.x + position1.w)||(position.y+position.h>position1.y+position1.h)))
     {
		 return true ; 
	 }
   else 
return false ; 
	 
	 
}
