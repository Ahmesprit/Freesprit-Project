#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "background.h"
#include "collision.h"
#include "character.h"
#include "enemy.h"
#include "enigme.h"
#include "management.h"
#include "menubutton.h"
#include <string.h>
//this struct is for generat settings of the game

int main(){
menuComponents mc;
menuPosComponents mpc;
settings set;
credits cred;
help h;
shop sh;
backup b;
state sta;
soundClicks sc;
char pickFromMenu[50];
butControl bc;
bc.sound = 0; //false: button sound not pressed yet
bc.music = 0; //false: button music not pressed yet
SDL_Surface *screen;
Mix_Music * music;
char pause;
SDL_Event event;
int menuNotOver = 0, quitsection = 0;
int done=0;
int playgame = 2, stopMenu=1, soundHoverStopFlag;
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
//Game loop starts
int pass = 0;
strcpy(pickFromMenu, "");
while (done == 0){
//poll event for menu
stopMenu = 1; pass = 0;
while(menuNotOver == 0){
  if(stopMenu == 1){
  showMenu(&mc, &mpc, screen, bc);
   }
 while((SDL_PollEvent(&event) == 1) && (pass == 0)){
      switch(event.type){
        case SDL_QUIT:
        menuNotOver = 1;
        done =1;
        pass = 1;
        break;
           case SDL_MOUSEMOTION:
                if(menuMotion(&mc, &mpc, screen, &event, bc, &sc) == 1){
                     stopMenu = 0;
                   }else{
                     stopMenu = 1;
                   }
           break;
           case SDL_MOUSEBUTTONDOWN:
                menuClicks(&mc, &mpc, screen, &event, music, &sc, &bc, pickFromMenu);
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
    backgroundMaps bm;
    bm = initMaps();
    playgame = 1;
    Mix_Music * stage1;
     SDL_BlitSurface(bm.splash,NULL, screen, &bm.splashPos);
     SDL_Flip(screen);
     Mix_PauseMusic();
     stage1 = Mix_LoadMUS("Resources/fatrat.mp3");
     Mix_PlayMusic(stage1,-1);
    SDL_Delay(2000);
    //initializing of game
    SDL_Rect camera;
    characPos cp;
    SDL_Rect posback, posLives, posScore;
    charac c;
    enemyPos ep;
    enemy e;
    entities ent;
    SDL_Surface * timestext, *livestext, *scoretext;
    enigme enig;
    enigmeData ed;
    int lives = 5;
    int score = 0;
    timer t;
    t.sec = 0;
    t.min = 0;
    int x, noscrolling = 1;
    camera.x = 0;
    camera.y = 0;
    camera.w = 960;
    camera.h = 600;
    e = initEnm();
    c = initChar();
    enig = initEnigme();
    SDL_EnableKeyRepeat(10, 10);
    ent = gameEntities();
    ent.livestext = updateLives(&lives);
    ent.scoretext = updateScore(&score);
    SDL_BlitSurface(bm.map, &camera, screen, NULL);
      SDL_BlitSurface(ent.livestext, NULL, screen, &ent.posLives);
      SDL_BlitSurface(ent.scoretext, NULL, screen, &ent.scorePos);
      SDL_BlitSurface(ent.hearts, NULL, screen, &ent.posheart);
      showEnm(&ep,e,screen);
      showChar(&cp,c, screen);
      ent.timestext = gameTime(&t);
      SDL_BlitSurface(ent.timestext, NULL, screen, &ent.timePos);
        SDL_Flip(screen);
    while(playgame == 1 ){
      while(SDL_PollEvent(&event) == 1){
         switch(event.type){
           case SDL_QUIT:
               playgame = 0;
             done =1;
            break;
                case SDL_KEYDOWN:
                   if(event.key.keysym.sym == SDLK_m){
                    done = 1;
                    playgame = 0;
                   }else{
                     score++;
                     moveEnemy(&ep, screen);
                     moveChar(event, &cp.position);
                     if((cp.position.x >= 930) && ((camera.x <= 4264) && (camera.x >= 0))){
                       scrolling(&camera, event);
                     ent.livestext = updateLives(&lives);
                     ent.scoretext = updateScore(&score);
                     cp.position.x = 10;
                       SDL_BlitSurface(bm.map, &camera, screen, NULL);
                       SDL_BlitSurface(ent.livestext, NULL, screen, &ent.posLives);
                       SDL_BlitSurface(ent.scoretext, NULL, screen, &ent.scorePos);
                       SDL_BlitSurface(ent.hearts, NULL, screen, &ent.posheart);
                       animEnm(&e, ep,screen);
                       animChar(&c, cp, screen, event);
                       SDL_Flip(screen);
                    }else{
                      ent.livestext = updateLives(&lives);
                      ent.scoretext = updateScore(&score);
                      SDL_BlitSurface(bm.map, &camera, screen, NULL);
                        SDL_BlitSurface(ent.livestext, NULL, screen, &ent.posLives);
                        SDL_BlitSurface(ent.scoretext, NULL, screen, &ent.scorePos);
                        SDL_BlitSurface(ent.hearts, NULL, screen, &ent.posheart);
                        animEnm(&e, ep,screen);
                        animChar(&c, cp, screen, event);
                        SDL_Flip(screen);
                    }
                         if (detectCollPP(bm.mask, cp.position) == 1) {
                           noscrolling = 0;
                         }else{
                    if(detectCollBB(cp.position, ep.position_enemy) == 1){
                      if(lives == 0){
                        SDL_Surface * lose;
                        lose = IMG_Load("Resources/lose.jpg");
                        SDL_Rect poslose = {0,0,lose->h, lose->w};
                        SDL_BlitSurface(lose, NULL, screen, &poslose);
                        SDL_Flip(screen);
                     }else{
                       lives--;
                       ent.livestext = updateLives(&lives);
                       ent.scoretext = updateScore(&score);
                       cp.position.x -= 40;
                       cp.position.y -= 40;
                       SDL_BlitSurface(bm.map, &camera, screen, NULL);
                         SDL_BlitSurface(ent.livestext, NULL, screen, &ent.posLives);
                         SDL_BlitSurface(ent.scoretext, NULL, screen, &ent.scorePos);
                         SDL_BlitSurface(ent.hearts, NULL, screen, &ent.posheart);
                         animEnm(&e, ep,screen);
                         animChar(&c, cp, screen, event);
                           SDL_Flip(screen);
                      }
                    }
                   }
                 }
                 }
    }
  }
}else{
	if (strcmp(pickFromMenu, "settings") == 0) {
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT){
      done = 1;
    }else{
    set = initSettings();
		quitsection = 0;
		while(quitsection == 0){
		b = restore();
    showSettings(set, screen, b);
    SDL_Flip(screen);
          SDL_PollEvent(&event);
        switch(event.type){
          case SDL_MOUSEBUTTONDOWN:
       quitsection = clicksSettings(set,event);
       if(quitsection == 1){
         strcpy(pickFromMenu, "");
         menuNotOver = 0;
       }
       break;
     }
    }
  }
	}else{
		if (strcmp(pickFromMenu, "shop") == 0) {
			sta = restoreState();
			SDL_PollEvent(&event);
			if(event.type == SDL_QUIT){
				done =1;
			}else{
			sh = initShop();
			showShop(sh, screen, sta);
			SDL_Flip(screen);
			quitsection = 0;
			while(quitsection == 0){
						SDL_PollEvent(&event);
					switch(event.type){
						case SDL_MOUSEBUTTONDOWN:
				 quitsection = clicksShop(sh,event,&sta, screen);
				 SDL_Flip(screen);
				 if(quitsection == 1){
					 strcpy(pickFromMenu, "");
					 menuNotOver = 0;
				 }
				 break;
				 case SDL_MOUSEMOTION:
				 showShop(sh, screen, sta);
				 SDL_Flip(screen);
				 break;
			 }
			}
		}
		}else{
			if (strcmp(pickFromMenu, "credits") == 0) {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT){
          done =1;
        }else{
        cred = initCredits();
        showCredits(cred, screen);
        SDL_Flip(screen);
        quitsection = 0;
        while(quitsection == 0){
              SDL_PollEvent(&event);
            switch(event.type){
              case SDL_MOUSEBUTTONDOWN:
           quitsection = clicksCredits(cred,event);
           if(quitsection == 1){
             strcpy(pickFromMenu, "");
             menuNotOver = 0;
           }
           break;
         }
        }
      }
			}else{
				if (strcmp(pickFromMenu, "help") == 0){
          SDL_PollEvent(&event);
          if(event.type == SDL_QUIT){
            done =1;
          }else{
          h = initHelp();
          showHelp(h, screen);
          SDL_Flip(screen);
          quitsection = 0;
          while(quitsection == 0){
                SDL_PollEvent(&event);
              switch(event.type){
                case SDL_MOUSEBUTTONDOWN:
             quitsection = clicksHelp(h,event);
             if(quitsection == 1){
               strcpy(pickFromMenu, "");
               menuNotOver = 0;
            }
             break;
           }
          }
        }
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
