#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include <stdlib.h>
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <stdlib.h>
#include "menubutton.h"
backup restore(){
  backup b;
   int x;
  FILE * f= NULL;
  f = fopen("backupsettings.bin", "rb");
  if(f == NULL){
    printf("file will be created\n");
    f = fopen("backupsettings.bin", "wb");
    b.sound = 0;
    b.music = 0;
    b.mode = 0;
    fwrite(&b, 1, sizeof(b), f);
    fclose(f);
    return b;
  }else{
    printf("already created\n");
    fread(&b, sizeof(b),1, f);
    printf("%d\n", b.sound);
    printf("%d\n", b.music);
    printf("%d\n", b.mode);
  }
  fclose(f);
  return b;
}
settings initSettings(){
  settings set;
	set.back = IMG_Load("Resources/backsettings.png");
	set.backbut = IMG_Load("Resources/back.png");
	set.sound = IMG_Load("Resources/volume.png");
	set.sound2 = IMG_Load("Resources/volume2.png");
	set.music = IMG_Load("Resources/music.png");
	set.music2 = IMG_Load("Resources/music2.png");
	set.joy = IMG_Load("Resources/joy.png");
	set.key = IMG_Load("Resources/key.png");
	set.mou = IMG_Load("Resources/mou.png");
	set.backbutPos.x = 920; set.backbutPos.y=570;
	set.backbutPos.h = set.backbut->h; set.backbutPos.w = set.backbut->w;
	set.backPos.x = 0; set.backPos.y=0;
	set.backPos.h = set.back->h; set.backPos.w = set.back->w;
	set.soundPos.x = 582; set.soundPos.y= 127;
 set.soundPos.h = set.sound->h; set.soundPos.w = set.sound->w;
 set.musicPos.x = 589; set.musicPos.y= 253;
set.musicPos.h = set.music->h; set.musicPos.w = set.music->w;
set.mode.x = 480; set.mode.y= 370;
set.mode.h = set.key->h; set.mode.w = set.key->w;
	return set;
}
void showSettings(settings set, SDL_Surface *screen, backup b){
	SDL_BlitSurface(set.back, NULL, screen, &set.backPos);
	SDL_BlitSurface(set.backbut, NULL, screen, &set.backbutPos);
  if(b.sound == 0){
	SDL_BlitSurface(set.sound, NULL, screen, &set.soundPos);
}else{
  SDL_BlitSurface(set.sound2, NULL, screen, &set.soundPos);
}
if(b.music == 0){
	SDL_BlitSurface(set.music, NULL, screen, &set.musicPos);
}else{
  SDL_BlitSurface(set.music2, NULL, screen, &set.musicPos);
}
 if(b.mode == 0){
	SDL_BlitSurface(set.key, NULL, screen, &set.mode);
}else{
  if(b.mode == 1){
 	SDL_BlitSurface(set.mou, NULL, screen, &set.mode);
 }else{
   if(b.mode == 2){
  	SDL_BlitSurface(set.joy, NULL, screen, &set.mode);
  }else{

  }
 }
}
}
int clicksSettings (settings set, SDL_Event event){
FILE *f=NULL;
backup b;
f = fopen("backupsettings.bin", "rb");
fread(&b, sizeof(b), 1, f);
fclose(f);
    if(((event.button.x <= (set.soundPos.x + set.sound->w)) && (event.button.x >= set.soundPos.x)) &&
    ((event.button.y >= set.soundPos.y) &&(event.button.y <= (set.soundPos.y + set.sound->h)))) {
      if(b.sound == 0){
        b.sound = 1;
        f = fopen("backupsettings.bin", "wb");
        fwrite(&b, 1, sizeof(b), f);
        fclose(f);
      }else{
        b.sound = 0;
        f = fopen("backupsettings.bin", "wb");
        fwrite(&b, 1, sizeof(b), f);
        fclose(f);
      }
    }else{
      if(((event.button.x <= (set.musicPos.x + set.music->w)) && (event.button.x >= set.musicPos.x)) &&
      ((event.button.y >= set.musicPos.y) &&(event.button.y <= (set.musicPos.y + set.music->h)))) {
          if(b.music == 0){
            b.music = 1;
            f = fopen("backupsettings.bin", "wb");
            fwrite(&b, 1, sizeof(b), f);
            fclose(f);
          }else{
            b.music = 0;
            f = fopen("backupsettings.bin", "wb");
            fwrite(&b, 1, sizeof(b), f);
            fclose(f);
          }
      }else{
        if(((event.button.x <= (set.mode.x + set.joy->w)) && (event.button.x >= set.mode.x)) &&
        ((event.button.y >= set.mode.y) &&(event.button.y <= (set.mode.y + set.joy->h)))) {
             if(b.mode == 0){
               b.mode = 1;
               f = fopen("backupsettings.bin", "wb");
               fwrite(&b, 1, sizeof(b), f);
               fclose(f);
             }else{
               if(b.mode == 1){
                 b.mode = 2;
                 f = fopen("backupsettings.bin", "wb");
                 fwrite(&b, 1, sizeof(b), f);
                 fclose(f);
               }else{
                 if(b.mode == 2){
                   b.mode = 0;
                   f = fopen("backupsettings.bin", "wb");
                   fwrite(&b, 1, sizeof(b), f);
                   fclose(f);
                 }
               }
             }
        }else{
          if(((event.button.x <= (set.backbutPos.x + set.backbut->w)) && (event.button.x >= set.backbutPos.x)) &&
          ((event.button.y >= set.backbutPos.y) &&(event.button.y <= (set.backbutPos.y + set.backbut->h)))) {
             return 1;
          }
        }
      }
    }
    return 0;
}
credits initCredits(){
	credits cred;
	cred.back =IMG_Load("Resources/creditsback.png");
	cred.backbut =IMG_Load("Resources/back.png");
	if ((cred.back==NULL) || (cred.backbut == NULL)){
		printf("unable to load background  image %s\n",SDL_GetError());
	}else{
		cred.backPos.x = 0; cred.backPos.y = 0;
		cred.backPos.h = cred.back->h; cred.backPos.w = cred.back->w;
		cred.backbutPos.x = 920; cred.backbutPos.y = 570;
		cred.backbutPos.h = cred.backbut->h; cred.backbutPos.w = cred.backbut->w;
	}
	return cred;
}
void showCredits(credits cred, SDL_Surface * screen){
	SDL_BlitSurface(cred.back, NULL, screen, &cred.backPos);
		SDL_BlitSurface(cred.backbut, NULL, screen, &cred.backbutPos);
}
int clicksCredits(credits cred, SDL_Event event){
	if(((event.button.x <= (cred.backbutPos.x + cred.backbut->w)) && (event.button.x >= cred.backbutPos.x)) && ((event.button.y >= cred.backbutPos.y) && (event.button.y <= (cred.backbutPos.y + cred.backbut->h)))) {
     return 1;
	}else{
		return 0 ;
	}
}
help initHelp(){
	help h;
	h.back =IMG_Load("Resources/backhelp.png");
	h.backbut =IMG_Load("Resources/back.png");
	if ((h.back==NULL) || (h.backbut == NULL)){
		printf("unable to load background  image %s\n",SDL_GetError());
	}else{
		h.backPos.x = 0; h.backPos.y = 0;
		h.backPos.h = h.back->h; h.backPos.w = h.back->w;
		h.backbutPos.x = 920; h.backbutPos.y = 570;
		h.backbutPos.h = h.backbut->h; h.backbutPos.w = h.backbut->w;
	}
	return h;
}
void showHelp(help h, SDL_Surface * screen){
	SDL_BlitSurface(h.back, NULL, screen, &h.backPos);
		SDL_BlitSurface(h.backbut, NULL, screen, &h.backbutPos);
}
int clicksHelp(help h, SDL_Event event){
	if(((event.button.x <= (h.backbutPos.x + h.backbut->w)) && (event.button.x >= h.backbutPos.x)) && ((event.button.y >= h.backbutPos.y) && (event.button.y <= (h.backbutPos.y + h.backbut->h)))) {
     return 1;
	}else{
		return 0 ;
	}
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
    s.coins = 0;
    fwrite(&s, 1, sizeof(s), f);
    fclose(f);
  }else{
    fread(&s,sizeof(s),1, f);
    fclose(f);
  }
  return s;
}
shop initShop(){
  shop sh;
  sh.back =IMG_Load("Resources/shopback.png");
  sh.backbut =IMG_Load("Resources/back.png");
  sh.backerror =IMG_Load("Resources/shoperror.png");
  sh.backwarning =IMG_Load("Resources/shopwarning.png");
  if ((sh.back==NULL) || (sh.backbut == NULL)){
    printf("unable to load background  image %s\n",SDL_GetError());
  }else{
    sh.backPos.x = 0; sh.backPos.y = 0;
    sh.backPos.h = sh.back->h; sh.backPos.w = sh.back->w;
    sh.backbutPos.x = 920; sh.backbutPos.y = 570;
		sh.backbutPos.h = sh.backbut->h; sh.backbutPos.w = sh.backbut->w;
   }
   return sh;
}
void showShop(shop sh, SDL_Surface * screen, state sta){
  SDL_Rect coinsPos;
   char ch[10];
   SDL_Surface *coins = NULL;
   TTF_Font *police = NULL;
   SDL_Color white = {255, 255, 255};
	SDL_BlitSurface(sh.back, NULL, screen, &sh.backPos);
		SDL_BlitSurface(sh.backbut, NULL, screen, &sh.backbutPos);
    if (TTF_Init() < 0) {
      printf("error\n");
  }else{
    police = TTF_OpenFont("Bebas-Regular.ttf", 32);
    if (police == NULL) {
      printf("error dans open font coins\n");
    }else{
      sprintf(ch,"%d",sta.coins);
      coins=TTF_RenderText_Solid(police, ch, white);
  TTF_CloseFont(police);
  TTF_Quit();
  }
  coinsPos.x = 860, coinsPos.y= 30;
  SDL_BlitSurface (coins, NULL, screen, &coinsPos);
}
}

int clicksShop(shop sh, SDL_Event event, state *sta, SDL_Surface *screen){
  FILE *f = fopen("state.bin", "rb");
  if(f == NULL){
    printf("error\n");
  }else{
  if(((event.button.x <= (sh.backbutPos.x + sh.backbut->w)) && (event.button.x >= sh.backbutPos.x)) && ((event.button.y >= sh.backbutPos.y) && (event.button.y <= (sh.backbutPos.y + sh.backbut->h)))) {
     return 1;
	}else{
    //on click first choice
    if(((event.button.x <= (34 + 150)) && (event.button.x >= 34)) && ((event.button.y >= 167) && (event.button.y <= (167 + 350)))) {
      if(sta->higherjumps == 0){
        if(sta->coins>=30){
          sta->higherjumps = 1;
          sta->coins -= 30;
          fwrite(sta, sizeof(sta), 1, f);
        }else{
          SDL_BlitSurface(sh.backerror, NULL, screen, &sh.backPos);
        }
      }else{
         SDL_BlitSurface(sh.backwarning, NULL, screen, &sh.backPos);
      }
    }else{
      //on click second choice
      if(((event.button.x <= (252 + 150)) && (event.button.x >= 252)) && ((event.button.y >= 167) && (event.button.y <= (167 + 350)))) {
          if(sta->coins>=50){
            sta->shield +=2;
            sta->coins -= 50;
            fwrite(sta, sizeof(sta), 1, f);
          }else{
            SDL_BlitSurface(sh.backerror, NULL, screen, &sh.backPos);
          }
      }else{
        //on click third choice
        if(((event.button.x <= (475 + 150)) && (event.button.x >= 475)) && ((event.button.y >= 167) && (event.button.y <= (167 + 350)))){
            if(sta->coins>=100){
              sta->enigmahelp += 5;
              sta->coins -= 100;
              fwrite(sta, sizeof(sta), 1, f);
            }else{
              SDL_BlitSurface(sh.backerror, NULL, screen, &sh.backPos);
            }
        }else{
          //on click fourth choice
          if(((event.button.x <= (703 + 150)) && (event.button.x >= 703)) && ((event.button.y >= 167) && (event.button.y <= (167 + 350)))) {
            if(sta->coins>=300){
              (sta->hearts)++;
              sta->coins -= 300;
              fwrite(sta, sizeof(sta), 1, f);
            }else{
              SDL_BlitSurface(sh.backerror, NULL, screen, &sh.backPos);
            }
          }
        }
      }
    }
	}
  fclose(f);
}
  return 0 ;
}
