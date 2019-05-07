#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <math.h>
#include <time.h>
#include "work.h"


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

if (police == NULL) {
  printf("error in font time\n");
}else{
sprintf(tim, "0%d : %d", t->min, t->sec);
timetext = TTF_RenderText_Solid(police, tim, noir);
TTF_CloseFont(police);
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
int checkPrevSession(){
  FILE * f = fopen("backupgame.bin", "rb");
  if(f == NULL){
    printf("no sessions found\n");
    f = fopen("backupgame.bin", "wb");
      fclose(f);
    return 0;
  }else{
    printf("there's a session\n");
      fclose(f);
    return 1;
  }
}
int showBackUpMenu(){
  int pick, x;
  x = checkPrevSession();
  if(x == 1){
    printf("1. start a new game\n");
    printf("2. resume previous game\n");
    do{
    printf("give your choice\n");
    scanf("%d", &pick);
  }while ((pick != 1) && (pick !=2));
  }else{
    printf("1. start a new game\n");
    do{
    printf("give your choice\n");
    scanf("%d", &pick);
  }while (pick != 1);
  }
  return pick;
}
void onMap(SDL_Event event, SDL_Rect *headPos, SDL_Rect obj){
  switch (event.key.keysym.sym){
case SDLK_RIGHT:
     headPos->x = headPos->x + 1;
     break;
case SDLK_LEFT:
     headPos->x = headPos->x - 1;
     break;
}
}
void scrolling (SDL_Rect * camera, SDL_Event event, SDL_Rect *headPos, SDL_Rect obj){
        switch (event.key.keysym.sym){
	case SDLK_RIGHT:
       camera->x = camera->x + 100;
	break;
	case SDLK_LEFT:
       camera->x = camera->x - 100;
	break;
 }
}
