#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

charac initChar (){
  charac c;
  char ch[512];
  int i;
  for (i = 0; i < 12; i++) {
      sprintf(ch, "Resources/azizsprite/%d.png", i+1);
    c.spriteright[i] = IMG_Load(ch);
  }
  for (i = 0; i < 11; i++) {
      sprintf(ch, "Resources/azizspriteleft/%d.png", i+1);
    c.spriteleft[i] = IMG_Load(ch);
  }
  c.shoot = IMG_Load("Resources/azizsprite/aziz-shoot.png");
  c.jump = IMG_Load("Resources/azizsprite/aziz-jump.png");
  c.shoot_left = IMG_Load("Resources/azizsprite/aziz-shoot-left.png");
  c.jump_left = IMG_Load("Resources/azizsprite/aziz-jump-left.png");
  c.hearts = IMG_Load("Resources/hearts.png");
  c.positionChar.x = 150;
  c.positionChar.y = 350;
  c.scorePos.x = 480;
  c.scorePos.y = 10;
  c.posLives.x = 900;
  c.posLives.y = 10;
  c.posheart.x = 910;
  c.posheart.y = 10;
  c.posheart.w = c.hearts->w;
  c.posheart.h = c.hearts->h;
  return c;
}
void showChar(charac c, SDL_Surface * screen, char whichDirection){
  if(whichDirection == 'r'){
c.positionChar.h = c.spriteright[0]->h;
c.positionChar.w = c.spriteright[0]->w;
 SDL_BlitSurface(c.spriteright[0], NULL, screen, &c.positionChar);
}else{
  if(whichDirection == 'l'){
  c.positionChar.h = c.spriteleft[0]->h;
  c.positionChar.w = c.spriteleft[0]->w;
   SDL_BlitSurface(c.spriteleft[0], NULL, screen, &c.positionChar);
}
}
}
char animChar (charac c, SDL_Surface *screen, SDL_Event event, char whichDirection){
  static int i=0, j=0;
  if (event.key.keysym.sym == SDLK_RIGHT) {
    j=13;
    if (i > 12){
       i = 0;
     SDL_BlitSurface(c.spriteright[i], NULL, screen, &c.positionChar);
     whichDirection = 'r';
     return whichDirection;
    }else{
  SDL_BlitSurface(c.spriteright[i], NULL, screen, &c.positionChar);
    i++;
  whichDirection = 'r';
  return whichDirection;
}
}else{
  if (event.key.keysym.sym == SDLK_LEFT) {
    i=13;
    if (j > 12){
       j = 0;
     SDL_BlitSurface(c.spriteleft[j], NULL, screen, &c.positionChar);
     whichDirection = 'l';
     return whichDirection;
    }else{
  SDL_BlitSurface(c.spriteleft[j], NULL, screen, &c.positionChar);
j++;
  whichDirection = 'l';
  return whichDirection;
}
}else{
  if(event.key.keysym.sym == SDLK_SPACE){
    if(whichDirection == 'l'){
      SDL_BlitSurface(c.jump_left, NULL, screen, &c.positionChar);
    }else{
    SDL_BlitSurface(c.jump, NULL, screen, &c.positionChar);
  }
}
}
}
return whichDirection;
}
void moveChar (SDL_Event event, SDL_Rect *posobj, int inWhichDir){
switch (event.key.keysym.sym){
  case SDLK_SPACE:
  if(inWhichDir != 1){
    posobj->y -=10;
  }
  break;
  case SDLK_RIGHT:
    if(inWhichDir != 2){
      posobj->x +=10;
    }
  break;
  case SDLK_LEFT:
    if(inWhichDir != 3){
        posobj->x -= 10;
      }
   break;
   case SDLK_DOWN:
     if(inWhichDir != 4){
         posobj->y += 10;
       }
    break;
  }

}
void moveCharByMouse(SDL_Surface *screen,SDL_Rect * persoPos, SDL_Event event, char whichDirection){
  switch(event.type){
         case SDL_MOUSEBUTTONDOWN:
             if(event.button.button == SDL_BUTTON_LEFT){
              persoPos->x += 10;
           }
         break;
   }
}
char animCharMouse (charac c, SDL_Surface *screen, SDL_Event event){
  char dir;
  static int i,j;
  if (event.button.x >= 480) {
     j = 13;
    if (i > 12){
       i = 0;
     SDL_BlitSurface(c.spriteright[i], NULL, screen, &c.positionChar);
     dir = 'r';
     return dir;
    }else{
      i++;
      SDL_BlitSurface(c.spriteright[i], NULL, screen, &c.positionChar);
      dir = 'r';
      return dir;
}
  }else{
    j = 13;
    if (j > 12){
       j = 0;
     SDL_BlitSurface(c.spriteleft[j], NULL, screen, &c.positionChar);
     dir = 'r';
     return dir;
    }else{
    j++;
  SDL_BlitSurface(c.spriteleft[j], NULL, screen, &c.positionChar);
  dir = 'r';
  return dir;
}
  }
  return 'n';

}
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
    sprintf(ch,"Score: %d",*score);
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
state restoreState(){
  state s;
  FILE *f = NULL;
  f = fopen("state.bin", "rb");
  if(f == NULL){
    printf("creating a state file\n");
    f = fopen("state.bin", "wb");
    s.shield = 0;
    s.hearts = 5;
    s.highscore = 0;
    s.higherjumps = 0;
    s.enigmahelp = 0;
    s.coins = 300;
    fwrite(&s, 1, sizeof(s), f);
    fclose(f);
  }else{
    fread(&s,sizeof(state),1, f);
    fclose(f);
  }
  return s;
}
