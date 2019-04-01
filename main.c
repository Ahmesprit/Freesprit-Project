#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "background.h"
#include "collision.h"
#include "character.h"
#include "enemy.h"
#include "enigme.h"
#include "management.h"
#include "menubutton.h"
#include <string.h>
//this struct is for generat settings of the game
typedef struct {
  int sound;
  int music;
  int time; // to change look and fill of the time
  int score; // to change look and fill of the score
}settings;

int main(){
menuComponents mc;
menuPosComponents mpc;
settingsComponents setc;
settingsPosComponents spc;
soundClicks sc;
char pickFromMenu[50];
int soundHoverStopFlag = 0;
butControl bc;
bc.sound = 0; //false: button sound not pressed yet
bc.music = 0; //false: button music not pressed yet
SDL_Surface *screen;
Mix_Music * music;
char pause;
SDL_Event event;
int menuNotOver = 0;
int done=0;
int playgame = 2;
//initializing the screen
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initializeSDL:%s \n",SDL_GetError());
	return 1;
}

screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
	printf("No sounds %s\n",Mix_GetError());
        return 1;
}
SDL_WM_SetCaption( "Freesprit", NULL);

//initializing menu and music
initSound(&music, &sc);
Mix_PlayMusic(music,-1);
initMenu(&mc, &mpc);
initMaps();
//Game loop starts
int pass = 0;
strcpy(pickFromMenu, "");
while (done == 0){
//poll event for menu
while(menuNotOver == 0){
  showMenu(&mc, &mpc, screen, bc);
 while((SDL_PollEvent(&event) == 1) && (pass == 0)){
      switch(event.type){
           case SDL_MOUSEMOTION:
                menuMotion(&mc, &mpc, screen, &event, bc, &sc, soundHoverStopFlag);
           break;
           case SDL_MOUSEBUTTONDOWN:
                menuClicks(&mc, &mpc, screen, &event, music, &sc, &bc, &soundHoverStopFlag, pickFromMenu);
                if (strcmp(pickFromMenu, "") != 0) {
                	pass = 1;
                  menuNotOver = 1;
                }
              break;
}
}
}
  if (strcmp(pickFromMenu, "playgame") == 0) {
    //translation
    playgame = 1;
    SDL_Surface * splash;
    SDL_Rect splashPos;
    Mix_Music * stage1;
     splash = IMG_Load("Resources/splash1.jpg");
     splashPos.x = 0;
     splashPos.y = 0;
     splashPos.h = splash->h;
     splashPos.w = splash->w;
     SDL_BlitSurface(splash,NULL, screen, &splashPos);
     SDL_Flip(screen);
     Mix_PauseMusic();
     stage1 = Mix_LoadMUS("Resources/fatrat.mp3");
     Mix_PlayMusic(stage1,-1);
    SDL_Delay(2000);
    //initializing of game
    SDL_Rect camera;
    characPos cp;
    SDL_Rect posback;
    SDL_Surface *back;
    charac c;
    SDL_Surface *mask;
    enemyPos ep;
    enemy e;
    enigme enig;
    enigmeData ed;
     char ch[50];
    SDL_Rect eee;
    int lives = 5;
    int score = 0;
    timer t;
    t.sec = 0;
    t.min = 0;
      SDL_Surface *hearts;
      hearts = IMG_Load("Resources/hearts.png");
    SDL_Rect poshearts;
    SDL_Rect poslives;
    SDL_Surface *livestext;
    SDL_Surface *timestext;
    TTF_Font *police = NULL;
    SDL_Surface *scoresurf;
    SDL_Rect scorerect;
    SDL_Rect timerect;
    scorerect.x = 480;
    scorerect.y = 10;
      poslives.x = 900;
      poslives.y = 10;
      poslives.w = 0;
      poslives.h = 0;
    poshearts.x = 910;
     poshearts.y = 10;
     poshearts.w = hearts->w;
     poshearts.h = hearts->h;
    int x;
    camera.x = 0;
    camera.y = 0;
    camera.w = 960;
    camera.h = 600;
    back = IMG_Load("Resources/backgroundstage1.png"); //background
    mask = SDL_LoadBMP("Resources/masque.bmp"); //mask
    e = initEnm(); //ennemy
    c = initChar();
    enig = initEnigme();
    posback.x = 0;
    posback.y = 0;
    posback.h = back->h;
    posback.w = back->w;
    SDL_EnableKeyRepeat(100, 120);
    if (TTF_Init() < 0) {
      printf("error\n");
    }else{
    SDL_Color noir = {255, 255, 255};
    police = TTF_OpenFont("/home/ahmeddebbech/Desktop/Freesprit/Bebas-Regular.ttf", 32);
    if (police == NULL) {
      printf("error dans open font score\n");
    }else{
    sprintf(ch,"%d",lives);
    livestext=TTF_RenderText_Solid(police, ch, noir);
    TTF_CloseFont(police);
    TTF_Quit();
    }
    }
    if(TTF_Init() < 0) {
        printf("error\n");
    }else{
      SDL_Color noir = {255, 255, 255};
      police = TTF_OpenFont("/home/ahmeddebbech/Desktop/Freesprit/Bebas-Regular.ttf", 32);
      if (police == NULL) {
        printf("error dans open font \n");
      }else{
      sprintf(ch, "%d", score);
     scoresurf = TTF_RenderText_Solid(police, ch, noir);
    TTF_CloseFont(police);
    TTF_Quit();
    }
    }
    SDL_BlitSurface(back, &camera, screen, NULL);
    SDL_BlitSurface(hearts, NULL, screen, &poshearts);
      SDL_BlitSurface(livestext, NULL, screen, &poslives);
      SDL_BlitSurface(scoresurf, NULL, screen, &scorerect);
      showEnm(&ep,e,screen);
      showChar(&cp,c, screen);
      timestext = gameTime(&t);
      timerect.x = 10;
      timerect.y = 10;
      timerect.h = timestext->h;
      timerect.w = timestext->w;
      SDL_BlitSurface(timestext, NULL, screen, &timerect);
        SDL_Flip(screen);
    while(playgame == 1){
      while(SDL_PollEvent(&event) == 1){
         switch(event.type){
                case SDL_KEYDOWN:
                   if(event.key.keysym.sym == SDLK_m){
                    done = 1;
                    playgame = 0;
                   }else{
                     moveKeyboard (event, &cp.position);
                     scrolling(&camera, event);
                     scoresurf = updateScore (&score, screen);
                     moveEnemy(&ep, screen);
  									 SDL_BlitSurface(back, &camera, screen, NULL);
                     SDL_BlitSurface(timestext, NULL, screen, &timerect);
                     animEnm(&e, ep, screen);
                     animChar(&c, cp, screen,event);
                     SDL_Flip(screen);
                   }
           }
    }
  }
}else{
	if (strcmp(pickFromMenu, "settings") == 0) {
		//poll event for settings window
		pass =0;
///code here
		 while((SDL_PollEvent(&event) == 1) && (pass == 0)){
					switch(event.type){
							 case SDL_MOUSEBUTTONDOWN:
										if (strcmp(pickFromMenu, "") != 0) {
											pass = 1;
										}
									break;
		     }
		}
	}else{
		if (strcmp(pickFromMenu, "shop") == 0) {

		}else{
			if (strcmp(pickFromMenu, "credits") == 0) {

			}else{
				if (strcmp(pickFromMenu, "help") == 0){

				}else{
          if (strcmp(pickFromMenu, "quit") == 0){
                   done =1;
  				}
        }
			}
		}
	}
}
}
//end game loop
SDL_FreeSurface(screen);
Mix_FreeMusic(music);
SDL_Quit();
return 0;
}
