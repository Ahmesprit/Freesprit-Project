#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "management.h"
#include <string.h>
#include <time.h>

SDL_Surface * updateScore(int *score){
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
SDL_Surface * updateLives(int *lives){
char ch[10];
  SDL_Rect poslives;
SDL_Surface *livestext;
  poslives.x=900;
  poslives.y=10;
  poslives.w = 0;
  poslives.h = 0;
	if (TTF_Init() < 0) {
    printf("error\n");
}else{
  TTF_Font *police = NULL;
  SDL_Color noir = {255, 255, 255};
  police = TTF_OpenFont("Bebas-Regular.ttf", 32);
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
       camera->x = camera->x + 480;
	break;

	case SDLK_LEFT:
       camera->x = camera->x - 480;
	break;
 }
}
entities gameEntities(){
  entities e;
  e.hearts = IMG_Load("Resources/hearts.png");
  e.scorePos.x = 480;
  e.scorePos.y = 10;
    e.posLives.x = 900;
    e.posLives.y = 10;
    e.timePos.x = 10;
    e.timePos.y = 10;
  e.posheart.x = 910;
  e. posheart.y = 10;
   e.posheart.w = e.hearts->w;
   e.posheart.h = e.hearts->h;
   return e;
}
