#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "work.h"
#include <string.h>
#include <math.h>
#include <time.h>

SDL_Surface * updateScore(int *score){
  char ch[10];
  SDL_Surface *scoring = NULL;
  TTF_Font *police = NULL;
  SDL_Color noir = {255, 255, 255};
  if (TTF_Init() < 0) {
    printf("error\n");
}else{
  police = TTF_OpenFont("Bebas-Regular.ttf", 32);
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
sprintf(tim, "0%d : %d", t->min, t->sec);
timetext = TTF_RenderText_Solid(police, tim, noir);
TTF_CloseFont(police);
TTF_Quit();
}
}
return timetext;
}
entities gameEntities(){
  entities e;
  e.hearts = IMG_Load("hearts.png");
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
enemy initEnm (){
  enemy e;
  e.spriteleft = IMG_Load("l.png");
	e.spriteright = IMG_Load("r.png");
if((e.spriteleft == NULL) && (e.spriteright == NULL)){
  printf("enable to load the image\n");
}
  return e;
}
void showEnm(enemyPos *enm, enemy e, SDL_Surface * screen){
  SDL_Rect camera;
  camera.x = 0;
  camera.y = 0;
  camera.h = 61;
  camera.w = 65;
enm->position_enemy.h = e.spriteleft->h;
enm->position_enemy.w = e.spriteleft->w;
 SDL_BlitSurface(e.spriteleft, &camera, screen, &enm->position_enemy);
}
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
    {
      return 0;
    }
}
