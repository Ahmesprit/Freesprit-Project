/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for multiplayer
*
*/
#include <stdlib.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
void scrolling (SDL_Rect * camera1, SDL_Rect * camera2, SDL_Event event){
        switch (event.key.keysym.sym){
	case SDLK_RIGHT:
       camera1->x = camera1->x +30;
	break;

	case SDLK_LEFT:
       camera1->x = camera1->x -30;
	break;
  case SDLK_z:
       camera2->x = camera2->x +30;
  break;

  case SDLK_a:
       camera2->x = camera2->x -30;
  break;
 }
}
void onMap(SDL_Event event, SDL_Rect *headPos, SDL_Rect obj){
  obj.x = obj.x + 500;
     headPos->x = (float)(obj.x * 789)/15984;
}
int main(int argc, char *argv[])
{
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface* pScreen = SDL_SetVideoMode(1000,1000,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 0, 0, 0));
SDL_ShowCursor(SDL_DISABLE);
 SDL_Event event;
//load
SDL_Surface* pImage1 = IMG_Load("backgroundstage1.png");
SDL_Surface* pImage2 = IMG_Load("backgroundstage1.png");
SDL_Surface* perso1 = IMG_Load ("1.png");
SDL_Surface* perso2 = IMG_Load ("obj2.png");
SDL_Surface * head = IMG_Load("head.png");
SDL_Surface * obj = IMG_Load("obj.png");
SDL_Surface * line = IMG_Load("line.png");

//positions
SDL_Rect pos_screen1,pos_screen2,pos_perso1,pos_perso2, posline, poshead, posobj, camera1, camera2;
int continuer=1;
camera1.x = 0;
camera1.h = 500;
camera1.w = 1000;
camera1.y = 0;
camera2.x = 0;
camera2.y = 0;
camera2.h = 500;
camera2.w = 1000;
pos_screen1.x = 0;
pos_screen1.y = 0;
pos_screen2.x=0;
pos_screen2.y=500; // y/2
pos_perso1.x=100;
pos_perso1.y=200;
pos_perso2.x=100;
pos_perso2.y=700;
posline.y = 500;
posline.x = 100;
poshead.y = 530;
poshead.x = 100;
posobj.y = 530;
posobj.x = 100;
//fill_blit_flip
SDL_SetColorKey(perso1, SDL_SRCCOLORKEY, SDL_MapRGB(perso1->format, 255, 255,255));
SDL_SetColorKey(perso2, SDL_SRCCOLORKEY, SDL_MapRGB(perso2->format, 255, 255,255));
SDL_EnableKeyRepeat(10,10);
SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 255, 255, 255));
SDL_BlitSurface(pImage1,&camera1,pScreen,&pos_screen1);
SDL_BlitSurface(pImage2,&camera2,pScreen,&pos_screen2);
SDL_BlitSurface (perso1,NULL,pScreen,&pos_perso1);
SDL_BlitSurface(line,NULL,pScreen,&posline);
SDL_BlitSurface(head,NULL,pScreen,&poshead);
SDL_BlitSurface(obj,NULL,pScreen,&posobj);
SDL_SetColorKey(perso1, SDL_SRCCOLORKEY, SDL_MapRGB(perso1->format, 255, 255,255));
SDL_BlitSurface (perso2,NULL,pScreen,&pos_perso2);
SDL_SetColorKey(perso2, SDL_SRCCOLORKEY, SDL_MapRGB(perso2->format, 255, 255,255));
SDL_Flip(pScreen);
 while (continuer == 1){
     SDL_WaitEvent(&event);
     switch(event.type){
         case SDL_QUIT:
             continuer = 0;
             break;
          case SDL_KEYDOWN:
             //First Scenario 1
             if(event.key.keysym.sym == SDLK_RIGHT){
               pos_perso1.x += 10;
             }else{
               if(event.key.keysym.sym == SDLK_LEFT){
                 pos_perso1.x -= 10;
               }else{
                 if(event.key.keysym.sym == SDLK_a){
                   pos_perso2.x -= 10;
                 }else{
                   if(event.key.keysym.sym == SDLK_z){
                     pos_perso2.x += 10;
                   }
                 }
               }
             }
          if((pos_perso1.x >= 500) &&  (camera1.x < 15984-1000)){
            //scrolling
            pos_perso1.x = 500;
            scrolling(&camera1, &camera2, event);
            onMap(event, &poshead, camera1);
            SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 255, 255, 255));
            SDL_BlitSurface(pImage1,&camera1,pScreen,&pos_screen1);
            SDL_BlitSurface(pImage2,&camera2,pScreen,&pos_screen2);
            SDL_BlitSurface (perso1,NULL,pScreen,&pos_perso1);
            SDL_BlitSurface(line,NULL,pScreen,&posline);
            SDL_BlitSurface(head,NULL,pScreen,&poshead);
            SDL_BlitSurface(obj,NULL,pScreen,&posobj);
            SDL_SetColorKey(perso1, SDL_SRCCOLORKEY, SDL_MapRGB(perso1->format, 255, 255,255));
            SDL_BlitSurface (perso2,NULL,pScreen,&pos_perso2);
            SDL_SetColorKey(perso2, SDL_SRCCOLORKEY, SDL_MapRGB(perso2->format, 255, 255,255));
            SDL_Flip(pScreen);
          }else{
           //Second scenario 2
          if((pos_perso1.x <= 50) && (camera1.x != 0)){
             //scrolling
             pos_perso1.x = 50;
             scrolling(&camera1, &camera2, event);
             onMap(event, &poshead, camera1);
             SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 255, 255, 255));
             SDL_BlitSurface(pImage1,&camera1,pScreen,&pos_screen1);
             SDL_BlitSurface(pImage2,&camera2,pScreen,&pos_screen2);
             SDL_BlitSurface (perso1,NULL,pScreen,&pos_perso1);
             SDL_BlitSurface(line,NULL,pScreen,&posline);
             SDL_BlitSurface(head,NULL,pScreen,&poshead);
             SDL_BlitSurface(obj,NULL,pScreen,&posobj);
             SDL_SetColorKey(perso1, SDL_SRCCOLORKEY, SDL_MapRGB(perso1->format, 255, 255,255));
             SDL_BlitSurface (perso2,NULL,pScreen,&pos_perso2);
             SDL_SetColorKey(perso2, SDL_SRCCOLORKEY, SDL_MapRGB(perso2->format, 255, 255,255));
             SDL_Flip(pScreen);
          }else{
             //Third Scenario 3
             //no scroll
             SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 255, 255, 255));
             SDL_BlitSurface(pImage1,&camera1,pScreen,&pos_screen1);
             SDL_BlitSurface(pImage2,&camera2,pScreen,&pos_screen2);
             SDL_BlitSurface (perso1,NULL,pScreen,&pos_perso1);
             SDL_BlitSurface(line,NULL,pScreen,&posline);
             SDL_BlitSurface(head,NULL,pScreen,&poshead);
             SDL_BlitSurface(obj,NULL,pScreen,&posobj);
             SDL_SetColorKey(perso1, SDL_SRCCOLORKEY, SDL_MapRGB(perso1->format, 255, 255,255));
             SDL_BlitSurface (perso2,NULL,pScreen,&pos_perso2);
             SDL_SetColorKey(perso2, SDL_SRCCOLORKEY, SDL_MapRGB(perso2->format, 255, 255,255));
             SDL_Flip(pScreen);
          }
         }
         //second screen
         if((pos_perso2.x >= 500) &&  (camera2.x < 15984-1000)){
           //scrolling
           pos_perso2.x = 500;
           scrolling(&camera1, &camera2, event);
           onMap(event, &posobj, camera2);
           SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 255, 255, 255));
           SDL_BlitSurface(pImage1,&camera1,pScreen,&pos_screen1);
           SDL_BlitSurface(pImage2,&camera2,pScreen,&pos_screen2);
           SDL_BlitSurface (perso1,NULL,pScreen,&pos_perso1);
           SDL_BlitSurface(line,NULL,pScreen,&posline);
           SDL_BlitSurface(head,NULL,pScreen,&poshead);
           SDL_BlitSurface(obj,NULL,pScreen,&posobj);
           SDL_SetColorKey(perso1, SDL_SRCCOLORKEY, SDL_MapRGB(perso1->format, 255, 255,255));
           SDL_BlitSurface (perso2,NULL,pScreen,&pos_perso2);
           SDL_SetColorKey(perso2, SDL_SRCCOLORKEY, SDL_MapRGB(perso2->format, 255, 255,255));
           SDL_Flip(pScreen);
         }else{
          //Second scenario 2
         if((pos_perso2.x <= 50) && (camera2.x != 0)){
            //scrolling
            pos_perso2.x = 50;
            scrolling(&camera1, &camera2, event);
            onMap(event, &posobj, camera2);
            SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 255, 255, 255));
            SDL_BlitSurface(pImage1,&camera1,pScreen,&pos_screen1);
            SDL_BlitSurface(pImage2,&camera2,pScreen,&pos_screen2);
            SDL_BlitSurface (perso1,NULL,pScreen,&pos_perso1);
            SDL_BlitSurface(line,NULL,pScreen,&posline);
            SDL_BlitSurface(head,NULL,pScreen,&poshead);
            SDL_BlitSurface(obj,NULL,pScreen,&posobj);
            SDL_SetColorKey(perso1, SDL_SRCCOLORKEY, SDL_MapRGB(perso1->format, 255, 255,255));
            SDL_BlitSurface (perso2,NULL,pScreen,&pos_perso2);
            SDL_SetColorKey(perso2, SDL_SRCCOLORKEY, SDL_MapRGB(perso2->format, 255, 255,255));
            SDL_Flip(pScreen);
         }else{
            //Third Scenario 3
            //no scroll
            SDL_FillRect(pScreen, NULL, SDL_MapRGB(pScreen->format, 255, 255, 255));
            SDL_BlitSurface(pImage1,&camera1,pScreen,&pos_screen1);
            SDL_BlitSurface(pImage2,&camera2,pScreen,&pos_screen2);
            SDL_BlitSurface (perso1,NULL,pScreen,&pos_perso1);
            SDL_BlitSurface(line,NULL,pScreen,&posline);
            SDL_BlitSurface(head,NULL,pScreen,&poshead);
            SDL_BlitSurface(obj,NULL,pScreen,&posobj);
            SDL_SetColorKey(perso1, SDL_SRCCOLORKEY, SDL_MapRGB(perso1->format, 255, 255,255));
            SDL_BlitSurface (perso2,NULL,pScreen,&pos_perso2);
            SDL_SetColorKey(perso2, SDL_SRCCOLORKEY, SDL_MapRGB(perso2->format, 255, 255,255));
            SDL_Flip(pScreen);
         }
         }

        break;
     }
 }

//free
SDL_FreeSurface(pImage1);
SDL_FreeSurface(pImage2);

SDL_Quit();


    return EXIT_SUCCESS;

}
