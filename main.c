#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "background.h"
#include "character.h"
#include "enemy.h"
#include "enigme.h"
#include "utilities.h"
#include "menubutton.h"
#include <string.h>

void showFrame(charac c,enemy e, SDL_Surface * timestext, SDL_Rect timePos, SDL_Rect camera,
backgroundMaps bm, SDL_Surface *screen, char whichDirection, timer *t){
	c.livestext = updateLives(&c.lives);
	c.scoretext = updateScore(&c.score);
	timestext = gameTime(t);
	SDL_BlitSurface(bm.map, &camera, screen, NULL);
	  SDL_BlitSurface(c.livestext, NULL, screen, &c.posLives);
	  SDL_BlitSurface(c.scoretext, NULL, screen, &c.scorePos);
	  SDL_BlitSurface(c.hearts, NULL, screen, &c.posheart);
		SDL_BlitSurface(timestext, NULL, screen, &timePos);
		showEnm(e,screen);
	  showChar(c, screen, whichDirection);
		SDL_Flip(screen);
}
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
	//declaration and initializing of everything
		//tranlation..
		backgroundMaps bm;
		Mix_Music * stage1;
		//tranlation..
		bm = initMaps();
		SDL_BlitSurface(bm.splash,NULL, screen, &bm.splashPos);
		SDL_Flip(screen);
		Mix_PauseMusic();
		stage1 = Mix_LoadMUS("Resources/stage1-egypt.mp3");
		Mix_PlayMusic(stage1,-1);
	 SDL_Delay(2000);
SDL_Rect camera;
camera.x = 0;
camera.y = 0;
camera.w = 960;
camera.h = 600;
charac c;
enemy e;
enigme enig;
enigmeData ed;
SDL_Surface * timestext;
SDL_Rect timePos;
timePos.x = 10; timePos.y = 0;
char  whichDirection = 'r';
int x,playgame = 1,asMovement = 0, dontscroll = 0;
	b = restore();
	sta = restoreState();
timer t;
t.sec = 0;
t.min = 3;
t.ticker = 0;
e = initEnm();
c = initChar();
int inWhichDir;
c.lives = sta.hearts;
c.s.shield = sta.shield,
c.s.coins = sta.coins;
c.score = 0;
enig = initEnigme();
SDL_EnableKeyRepeat(120, 10);
showFrame(c,e,timestext, timePos,camera,bm,screen, whichDirection,&t);
SDL_Flip(screen);
			//with keyboard
	   	if(b.mode == 0){
        while(playgame == 1){
			SDL_PollEvent(&event);
			   switch(event.type){
					 case SDL_QUIT:
							 playgame = 0;
						 done =1;
						break;
						case SDL_KEYUP:
						showFrame(c,e,timestext, timePos,camera,bm,screen, whichDirection, &t);
            SDL_Flip(screen);
						break;
						case SDL_KEYDOWN:
	             if(event.key.keysym.sym == SDLK_q){
	              done = 1;
	              playgame = 0;
							}else{
	                moveChar(event, &c.positionChar, inWhichDir);
								 moveEnemy(&e, screen,c.positionChar);
									//back: w15984 h600
                 if((c.positionChar.x >= 480) && (camera.x < 15984-960)){
									 //scrolling
									 c.positionChar.x = 480;
									  scrolling(&camera, event);
										SDL_BlitSurface(bm.mask, &camera, screen, NULL);
										if (detectCollPP(bm.mask,c,screen) == 1){
                      if(event.key.keysym.sym == SDLK_SPACE){
												inWhichDir = 1;
												printf("space\n");
											}else{
												if(event.key.keysym.sym == SDLK_RIGHT){
													printf("right\n");
													inWhichDir = 2;
												}else{
													if(event.key.keysym.sym == SDLK_LEFT){
														inWhichDir = 3;
														printf("left\n");

													}else{
														if(event.key.keysym.sym == SDLK_DOWN){
															inWhichDir = 4;
															printf("down\n");

														}
													}
												}
											}
											 printf("coll\n" );
									   }else{
											 inWhichDir = 0;
										 }
									 if(detectCollBB(c.positionChar, e.position_enemy) == 1){
										 c.positionChar.x -= 150;
										 c.lives--;
									 }
									   c.livestext = updateLives(&c.lives);
		                 c.scoretext = updateScore(&c.score);
		                 timestext = gameTime(&t);
		                 SDL_BlitSurface(bm.map, &camera, screen, NULL);
		                   SDL_BlitSurface(c.livestext, NULL, screen, &c.posLives);
		                   SDL_BlitSurface(c.scoretext, NULL, screen, &c.scorePos);
		                   SDL_BlitSurface(c.hearts, NULL, screen, &c.posheart);
		                   SDL_BlitSurface(timestext, NULL, screen, &timePos);
											 showEnm(e,screen);
											 whichDirection = animChar(c,screen, event,whichDirection);
											 SDL_Flip(screen);
								 }else{
									 if((c.positionChar.x <= 50) && (camera.x != 0)){
										 //scrolling
										 c.positionChar.x = 50;
										  scrolling(&camera, event);
											SDL_BlitSurface(bm.mask, &camera, screen, NULL);
											if (detectCollPP(bm.mask,c,screen) == 1){
	                      if(event.key.keysym.sym == SDLK_SPACE){
													inWhichDir = 1;
													printf("up\n" );
												}else{
													if(event.key.keysym.sym == SDLK_RIGHT){
														inWhichDir = 2;
														printf("right\n");
													}else{
														if(event.key.keysym.sym == SDLK_LEFT){
															inWhichDir = 3;
															printf("left\n");
														}else{
															if(event.key.keysym.sym == SDLK_DOWN){
																inWhichDir = 4;
																printf("down\n");
															}
														}
													}
												}
												 printf("coll\n" );
										   }else{
												 inWhichDir = 0;
											 }
											if(detectCollBB(c.positionChar,e.position_enemy) == 1){
												c.positionChar.x -= 150;
												c.lives--;
											}
										   c.livestext = updateLives(&c.lives);
			                 c.scoretext = updateScore(&c.score);
			                 timestext = gameTime(&t);
			                 SDL_BlitSurface(bm.map, &camera,     screen, NULL);
			                   SDL_BlitSurface(c.livestext, NULL, screen, &c.posLives);
			                   SDL_BlitSurface(c.scoretext, NULL, screen, &c.scorePos);
			                   SDL_BlitSurface(c.hearts, NULL, screen, &c.posheart);
			                   SDL_BlitSurface(timestext, NULL, screen, &timePos);
												 showEnm(e,screen);
												 whichDirection = animChar(c, screen, event,whichDirection);
			                   SDL_Flip(screen);
									 }else{
										 //no scroll
										 SDL_BlitSurface(bm.mask, &camera, screen, NULL);
										 if (detectCollPP(bm.mask,c,screen) == 1){
                       if(event.key.keysym.sym == SDLK_SPACE){
 												inWhichDir = 1;
												printf("up\n");
 											}else{
 												if(event.key.keysym.sym == SDLK_RIGHT){
													printf("right\n");
 													inWhichDir = 2;
 												}else{
 													if(event.key.keysym.sym == SDLK_LEFT){
 														inWhichDir = 3;
														printf("left\n" );
 													}else{
 														if(event.key.keysym.sym == SDLK_DOWN){
 															inWhichDir = 4;
															printf("down\n");
 														}
 													}
 												}
 											}
 											 printf("coll\n" );
 									   }else{
 											 inWhichDir = 0;
 										 }
										 if(detectCollBB(c.positionChar, e.position_enemy) == 1){
											 c.positionChar.x -= 150;
											 c.lives--;
										 }
										 c.livestext = updateLives(&c.lives);
										 c.scoretext = updateScore(&c.score);
										 timestext = gameTime(&t);
										 SDL_BlitSurface(bm.map, &camera, screen, NULL);
											 SDL_BlitSurface(c.livestext, NULL, screen, &c.posLives);
											 SDL_BlitSurface(c.scoretext, NULL, screen, &c.scorePos);
											 SDL_BlitSurface(c.hearts, NULL, screen, &c.posheart);
											 SDL_BlitSurface(timestext, NULL, screen, &timePos);
                        showEnm(e,screen);
												whichDirection = animChar(c,screen, event, whichDirection);
											 SDL_Flip(screen);
									 }
								 }
				     }
        }
	}
      }else{
				//with mouse
         if(b.mode == 1){
					/* while(playgame == 1){
	 			SDL_PollEvent(&event);
	 			   switch(event.type){
	 					 case SDL_QUIT:
	 							 playgame = 0;
	 						 done =1;
	 						break;
							case SDL_MOUSEBUTTONUP:
							showFrame(c,e,timestext, timePos,camera,bm,screen, whichDirection, &t);
							SDL_Flip(screen);
							break;
	 						case SDL_MOUSEBUTTONDOWN:
	 	               moveEnemy(&e, screen,c.positionChar);
									 moveCharByMouse(screen, &c.positionChar,event, whichDirection);
	 									//back: w15984 h600
	                  if((c.positionChar.x >= 480) && (camera.x < 15984-960)){
	 									 //scrolling
	 									 c.positionChar.x = 480;
	 									  scrolling(&camera, event);
	 									   c.livestext = updateLives(&c.lives);
	 		                 c.scoretext = updateScore(&c.score);
	 		                 timestext = gameTime(&t);
	 		                 SDL_BlitSurface(bm.map, &camera, screen, NULL);
	 		                   SDL_BlitSurface(c.livestext, NULL, screen, &c.posLives);
	 		                   SDL_BlitSurface(c.scoretext, NULL, screen, &c.scorePos);
	 		                   SDL_BlitSurface(c.hearts, NULL, screen, &c.posheart);
	 		                   SDL_BlitSurface(timestext, NULL, screen, &timePos);
	 											 if (detectCollPP(bm.mask, c.positionChar) == 1){
	  												printf("coll\n");
	  												c.positionChar.x -= 5;
	  											}else{
														if(detectCollBB(c.positionChar, e.position_enemy) == 1){
															c.positionChar.x -= 150;
															c.lives--;
														}
													}
	 											 animEnm(e,screen, asMovement);
												 SDL_Delay(100);
	 		                   whichDirection = animCharMouse(c,screen, event);
	 		                   SDL_Flip(screen);
	 								 }else{
	 									 if((c.positionChar.x <= 50) && (camera.x != 0)){
	 										 //scrolling
	 										 c.positionChar.x = 50;
	 										  scrolling(&camera, event);
	 										   c.livestext = updateLives(&c.lives);
	 			                 c.scoretext = updateScore(&c.score);
	 			                 timestext = gameTime(&t);
	 			                 SDL_BlitSurface(bm.map, &camera, screen, NULL);
	 			                   SDL_BlitSurface(c.livestext, NULL, screen, &c.posLives);
	 			                   SDL_BlitSurface(c.scoretext, NULL, screen, &c.scorePos);
	 			                   SDL_BlitSurface(c.hearts, NULL, screen, &c.posheart);
	 			                   SDL_BlitSurface(timestext, NULL, screen, &timePos);
	 			                   animEnm(e,screen,asMovement);
	 			                   whichDirection = animChar(c, screen, event,whichDirection);
	 			                   SDL_Flip(screen);
	 												 if (detectCollPP(bm.mask, c.positionChar) == 1) {
	 			                     printf("coll\n");
	 			                   }
	 									 }else{
	 										 //no scroll
	 										 c.livestext = updateLives(&c.lives);
	 										 c.scoretext = updateScore(&c.score);
	 										 timestext = gameTime(&t);
	 										 SDL_BlitSurface(bm.map, &camera, screen, NULL);
	 											 SDL_BlitSurface(c.livestext, NULL, screen, &c.posLives);
	 											 SDL_BlitSurface(c.scoretext, NULL, screen, &c.scorePos);
	 											 SDL_BlitSurface(c.hearts, NULL, screen, &c.posheart);
	 											 SDL_BlitSurface(timestext, NULL, screen, &timePos);
	 											 animEnm(e,screen, asMovement);
	 											 whichDirection = animChar(c, screen, event,whichDirection);
	 											 SDL_Flip(screen);
	 											 if (detectCollPP(bm.mask, c.positionChar) == 1) {
	 		                     printf("coll\n");
	 		                   }
	 									 }
	 								 }
	 				     }
	         }*/
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
