#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

typedef struct{
  int shield; //number of shields
  int hearts; //number of hearts
  int highscore; //number
  int higherjumps; // yes or no
  int enigmahelp; //yes or no
  int coins; //number
 }state;
typedef struct {
 SDL_Surface * spriteleft[11];
 SDL_Surface * spriteright[11];
 SDL_Surface *shoot;
 SDL_Surface * jump;
 SDL_Surface *shoot_left;
 SDL_Surface * jump_left;
 SDL_Rect pmaxChar;
 SDL_Rect pminChar;
 SDL_Rect positionChar;
 SDL_Surface *livestext;
 SDL_Surface *scoretext;
 SDL_Rect scorePos;
 SDL_Rect posheart;
 SDL_Surface *hearts;
 SDL_Rect posLives;
 int lives;
 int score;
 state s;
}charac;

charac initChar ();
void showChar(charac c, SDL_Surface * screen, char whichDirection);
char animChar (charac c, SDL_Surface *screen, SDL_Event event, char whichDirection);
void moveChar (SDL_Event event, SDL_Rect *posobj, int inWhichDir);
void moveCharByMouse(SDL_Surface *screen,SDL_Rect * persoPos, SDL_Event event, char whichDirection);
char animCharMouse (charac c, SDL_Surface *screen, SDL_Event event);
SDL_Surface * updateScore(int *score);
SDL_Surface * updateLives(int *lives);
state restoreState();
#endif
