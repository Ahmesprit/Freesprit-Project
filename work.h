#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <math.h>
#include <time.h>
typedef struct {
int sec;
int min;
int ticker;
}timer;
typedef struct {
  SDL_Surface *hearts;
  SDL_Rect posLives;
  SDL_Surface *livestext;
  SDL_Surface *timestext;
  SDL_Surface *scoretext;
  SDL_Rect scorePos;
  SDL_Rect posheart;
  SDL_Rect timePos;
}entities;
typedef struct{
  SDL_Rect camera;
  char background[512]; // this is to backup which backgound has been used lastly
char perso[512];
  SDL_Rect persoPos;
  SDL_Rect headPos;
char head[512];
  int score;
  int lives;
  timer t;
}backUpEntries;
SDL_Surface * updateScore(int *score);
SDL_Surface * updateLives(int *lives);
SDL_Surface * gameTime (timer *t);
entities gameEntities();
int checkPrevSession();
int showBackUpMenu();
void onMap(SDL_Event event, SDL_Rect *headPos, SDL_Rect obj);
void scrolling (SDL_Rect * camera, SDL_Event event, SDL_Rect *headPos, SDL_Rect obj);
