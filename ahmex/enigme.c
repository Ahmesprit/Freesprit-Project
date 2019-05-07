/**
*
*@file enigme.c
*@author Ahmed Debbech
*/
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <time.h>
#include <math.h>
#include "enigme.h"
/**
* @brief to initialize enigma .
* @param nothing
* @return enigme struct
*/
enigme initEnigme (){
  enigme e;
 e.back = IMG_Load("letter.jpg");
 return e;
}
/**
* @brief to show enigma .
* @param ed enigmeData
* @param screen
* @param e
* @return nothing
*/
void showEnigme (enigmeData ed, SDL_Surface *screen, enigme e){
  typedef struct{
    SDL_Rect back;
    SDL_Rect quest;
    SDL_Rect enigma;
    SDL_Rect c1;
    SDL_Rect c2;
    SDL_Rect c3;
  }posenigme;
posenigme pe;
SDL_Surface *questsurf;
SDL_Surface *enigmasurf;
SDL_Surface *c1surf;
SDL_Surface *c2surf;
SDL_Surface *c3surf;
TTF_Font * police;
SDL_Color red = {255,0,0};
SDL_Color white = {0,0,0};
if (TTF_Init() < 0) {
  printf("error\n");
}else{
police = TTF_OpenFont("Bebas-Regular.ttf", 24);
if (police == NULL) {
  printf("error dans open font enigma\n");
}else{
  questsurf = TTF_RenderText_Solid(police, ed.quest, white);
  enigmasurf = TTF_RenderText_Solid(police, ed.enigma, white);
  c1surf = TTF_RenderText_Solid(police, ed.c1, red);
  c2surf = TTF_RenderText_Solid(police, ed.c2, red);
  c3surf = TTF_RenderText_Solid(police, ed.c3, red);
  pe.back.x = 200;
  pe.back.y = 100;
  pe.back.h = questsurf->h;
  pe.back.w = questsurf->w;
  pe.quest.x = 240;
  pe.quest.y = 130;
  pe.enigma.x = 240;
  pe.enigma.y = 250;
  pe.c1.x= 400;
  pe.c1.y= 200;
  pe.c2.x= 550;
  pe.c2.y= 200;
  pe.c3.x= 700;
  pe.c3.y= 200;
  SDL_BlitSurface(e.back, NULL, screen, &pe.back);
  SDL_BlitSurface(questsurf, NULL, screen, &pe.quest);
    SDL_BlitSurface(enigmasurf, NULL, screen, &pe.enigma);
  SDL_BlitSurface(c1surf, NULL, screen, &pe.c1);
  SDL_BlitSurface(c2surf, NULL, screen, &pe.c2);
  SDL_BlitSurface(c3surf, NULL, screen, &pe.c3);
TTF_CloseFont(police);
TTF_Quit();
}
}
}
/**
* @brief to randomize .
* @param Nothing
* @param e
* @return int
*/
int randomize(){
int pos;
 srand(time(NULL));
pos=rand()%(3-1+1)+1;
return pos;
}
/**
* @brief to generate enigma from file.
* @param enigme e
* @return enigmaData
*/
enigmeData generateEnigme(enigme e){
  enigmeData edata;
  int type;
  int w,x,z,y, rand_place,hold;
  type = randomize();
  srand(time(NULL));
  switch (type) {
    case 1:
      w=rand()%(254-1+1)+1;
      x=rand()%(254-0+1)+0;
      z=rand()%(254-0+1)+0;
      sprintf(edata.quest, "Find the missing Y in this IP (Hint: 255-last part)");
      sprintf(edata.enigma, "%d.%d.Y.%d", w,x,z);
      y = 255 - z;
      sprintf(edata.x, "%d", y);
      rand_place = rand()%(3-1+1)+1;
      switch (rand_place) {
        case 1:
        sprintf(edata.c1, "%d", y);
        sprintf(edata.c2, "%d", rand()%(148-1+1)+1);
        sprintf(edata.c3, "%d", rand()%(255-45+1)+45);
        break;
        case 2:
        sprintf(edata.c1, "%d", rand()%(100-22+1)+22);
        sprintf(edata.c2, "%d", y);
        sprintf(edata.c3, "%d", rand()%(200-100+1)+100);
        break;
        case 3:
        sprintf(edata.c1, "%d", rand()%(210-190+1)+190);
        sprintf(edata.c3, "%d", y);
        sprintf(edata.c2, "%d", rand()%(170-70+1)+70);
        break;
      }
    break;
    case 2:
    w=rand()%(10-0+1)+0;
    x=rand()%(10-0+1)+0;
    z=rand()%(10-0+1)+0;
    sprintf(edata.quest, "Say how much this second degree enigma has results");
    sprintf(edata.enigma, "square(%dx) + %dx - %d", w,x,z);
    y = (x*x) - (4 *w*z);
    if(y > 0){
      sprintf(edata.x, "%d", 2);
    }else{
      if(y == 0){
        sprintf(edata.x, "%d", 1);
      }else{
        sprintf(edata.x, "%d", 0);
      }
    }
    sprintf(edata.c1, "%d", 0);
    sprintf(edata.c2, "%d", 1);
    sprintf(edata.c3, "%d", 2);
    break;
    case 3:
    w=rand()%(10-1+1)+1;
    sprintf(edata.quest, "Calculate the surface of this Cube:");
    sprintf(edata.enigma, "The edge of cube is equal to %d", w);
    y = 6*(w*w);
    sprintf(edata.x, "%d", y);
    rand_place = rand()%(3-1+1)+1;
    switch (rand_place) {
      case 1:
      sprintf(edata.c1, "%d", y);
      sprintf(edata.c2, "%d", rand()%(350-1+1)+1);
      sprintf(edata.c3, "%d", rand()%(350-1+1)+1);
      break;
      case 2:
      sprintf(edata.c1, "%d", rand()%(350-1+1)+1);
      sprintf(edata.c2, "%d", y);
      sprintf(edata.c3, "%d", rand()%(350-1+1)+1);
      break;
      case 3:
      sprintf(edata.c1, "%d", rand()%(350-1+1)+1);
      sprintf(edata.c3, "%d", y);
      sprintf(edata.c2, "%d", rand()%(350-1+1)+1);
      break;
    }
    break;
  }
  return edata;
}
/**
* @brief to resolve enigma .
* @param ed enigma Data
* @param event
* @return int
*/
int resolutionEnigme(enigmeData ed, SDL_Event event){
  switch(event.type){
         case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_1){
             if (strcmp (ed.c1, ed.x) == 0) {
               return 1;
             }
            }else{
              if(event.key.keysym.sym == SDLK_2){
                if (strcmp (ed.c2, ed.x) == 0) {
                  return 1;
                }
             }else{
               if(event.key.keysym.sym == SDLK_3){
                 if (strcmp (ed.c3, ed.x) == 0) {
                   return 1;
                 }
               }
             }
            }
}
return 0;
}
