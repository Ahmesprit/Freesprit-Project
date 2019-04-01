#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "management.h"
#include <string.h>
#include <time.h>

SDL_Surface * updateScore(int *score, SDL_Surface * screen){
  char ch[10];
  SDL_Surface *scoring = NULL;
  TTF_Font *police = NULL;
  SDL_Color noir = {255, 255, 255};
  if (TTF_Init() < 0) {
    printf("error\n");
}else{
  police = TTF_OpenFont("/home/ahmeddebbech/Desktop/Freesprit/Bebas-Regular.ttf", 32);
  if (police == NULL) {
    printf("error dans open font scorerect\n");
  }else{
    sprintf(ch,"%d",*score);
    scoring=TTF_RenderText_Solid(police, ch, noir);
TTF_CloseFont(police);
TTF_Quit();
}
}
   return scoring;
}
SDL_Surface * updateLives(int *lives, SDL_Surface *hearts){
char ch[10];
  SDL_Rect poslives;
SDL_Rect poshearts;
SDL_Surface *livestext;
  poslives.x=900;
  poslives.y=10;
  poslives.w = 0;
  poslives.h = 0;
 poshearts.x= 910;
  poshearts.y= 10;
  poshearts.w = hearts->w;
  poshearts.h = hearts->h;
	if (TTF_Init() < 0) {
    printf("error\n");
}else{
  TTF_Font *police = NULL;
  SDL_Color noir = {255, 255, 255};
  police = TTF_OpenFont("/home/ahmed/Desktop/Freesprit/Bebas-Regular.ttf", 32);
  if (police == NULL) {
    printf("error dans open font\n");
  }else{
  sprintf(ch, "%d", *lives);
  livestext=TTF_RenderText_Solid(police, ch, noir);
TTF_CloseFont(police);
TTF_Quit();
}
}
return livestext;
}
SDL_Surface * gameTime (timer *t) {
  char tim[8];
  SDL_Surface *timetext;
SDL_Delay(1000);
if (t->sec==60) {
    t->min++;
    t->sec =0;
}else {
   t->sec++;
}
if (TTF_Init() < 0) {
  printf("error\n");
}else{
TTF_Font * police = NULL;
SDL_Color noir = {255, 255, 255};
police = TTF_OpenFont("/home/ahmeddebbech/Desktop/Freesprit/Bebas-Regular.ttf", 32);
if (police == NULL) {
  printf("error in font time\n");
}else{
sprintf(tim, "0%d : %d", t->min, t->sec);
timetext = TTF_RenderText_Solid(police, tim, noir);
TTF_CloseFont(police);
TTF_Quit();
}
}
return timetext;
}
void scrolling (SDL_Rect * camera, SDL_Event event){

        switch (event.key.keysym.sym){

	case SDLK_RIGHT:
       camera->x = camera->x + 100;
               if(camera->x >= 4264-960){
                          camera->x = 0;
               }
	break;

	case SDLK_LEFT:
       camera->x = camera->x - 100;
               if(camera->x <= 4264-960){
                          camera->x = 0;
               }
	break;
 }
}
