#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "impl.h"

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
int main() {
int x = 0;
SDL_Surface *screen;
SDL_Surface * back;
SDL_Rect pos;
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL:%s \n",SDL_GetError());
return 1;
}
screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
printf("No sounds %s\n",Mix_GetError());
        return 1;
}
SDL_WM_SetCaption( "Freesprit", NULL);
int done = 0;
SDL_Event event;
SDL_Surface * obj1, *completed;
SDL_Surface * line;
SDL_Surface * head;
SDL_Rect linePos;
SDL_Rect rect1;
SDL_Rect camera;
SDL_Rect headPos, completedPos;
back = IMG_Load("backgroundstage1.png");
obj1 = IMG_Load("obj1.jpg");
head = IMG_Load("head.png");
completed = IMG_Load("stagecompleted.png");
rect1.x = 700;
rect1.y = 300;
rect1.h = obj1->h;
rect1.w = obj1->w;
camera.x = 0;
camera.y = 0;
camera.h = 600;
camera.w = 960;
completedPos.x = 0;
completedPos.y = 0;
completedPos.h = 600;
completedPos.w = 960;
line = IMG_Load("line.png");
linePos.x = 50;
linePos.y = 500;
linePos.h = line->h;
linePos.w = line->w;
headPos.x = 80;
headPos.y = 550;
headPos.h = head->h;
headPos.w = head->w;
pos.x = 0; pos.y = 0; pos.h =back->h; pos.w= back->w;
SDL_BlitSurface(back, &camera, screen, &pos);
SDL_BlitSurface(obj1, NULL, screen, &rect1);
SDL_BlitSurface(line, NULL, screen, &linePos);
SDL_BlitSurface(head, NULL, screen, &headPos);
SDL_Flip(screen);
SDL_EnableKeyRepeat(120, 100);
//Game loop starts
while (done == 0){
  while(SDL_PollEvent(&event) == 1){
    x=0;
  switch (event.key.keysym.sym){
         case SDLK_UP:
          rect1.y-=10;
  break;
         case SDLK_DOWN:
         rect1.y+=10;
  break;
  case SDLK_RIGHT:
         rect1.x+=10;
  break;
  case SDLK_LEFT:
         rect1.x-=10;
  break;
   }

SDL_BlitSurface(back, &camera, screen, &pos);
SDL_BlitSurface(obj1, NULL, screen, &rect1);
SDL_BlitSurface(line, NULL, screen, &linePos);
SDL_BlitSurface(head, NULL, screen, &headPos);
   SDL_Flip(screen);
   //back: w15984 h600
                if((rect1.x >= 480) && (camera.x < 15984-960)){
                  //scrolling
                  rect1.x = 480;
                   scrolling(&camera, event, &headPos,rect1);
                   onMap(event, &headPos, rect1);
                   SDL_BlitSurface(back, &camera, screen, &pos);
                   SDL_BlitSurface(obj1, NULL, screen, &rect1);
                   SDL_BlitSurface(line, NULL, screen, &linePos);
                   SDL_BlitSurface(head, NULL, screen, &headPos);
                      SDL_Flip(screen);
                }else{
                  if(camera.x > 15984-960){
                        back= IMG_Load("backgroundstage2.png");
                        camera.x = 0;
                        camera.y = 0;
                        camera.h = 600;
                        camera.w = 960;
                        pos.x = 0; pos.y = 0; pos.h =back->h; pos.w= back->w;
                        obj1 = IMG_Load("obj2.png");
                        SDL_BlitSurface(completed, NULL, screen, &completedPos);
                        SDL_Flip(screen);
                        SDL_Delay(1000);
                        rect1.x = 700;
                        rect1.y = 300;
                        rect1.h = obj1->h;
                        rect1.w = obj1->w;
                        headPos.x = 80;
                        headPos.y = 550;
                        headPos.h = head->h;
                        headPos.w = head->w;

                  }else{
                  if((rect1.x <= 50) && (camera.x != 0)){
                    //scrolling
                     scrolling(&camera, event,&headPos,rect1);
                     onMap(event, &headPos, rect1);
                     SDL_BlitSurface(back, &camera, screen, &pos);
                     SDL_BlitSurface(obj1, NULL, screen, &rect1);
                     SDL_BlitSurface(line, NULL, screen, &linePos);
                     SDL_BlitSurface(head, NULL, screen, &headPos);
                     SDL_Flip(screen);
                  }else{
                    //no scroll
                    onMap(event, &headPos, rect1);
                    SDL_BlitSurface(back, &camera, screen, &pos);
                    SDL_BlitSurface(obj1, NULL, screen, &rect1);
                    SDL_BlitSurface(line, NULL, screen, &linePos);
                    SDL_BlitSurface(head, NULL, screen, &headPos);
                      SDL_Flip(screen);
                  }
                }
                }
}
}
//end game loop
SDL_FreeSurface(screen);
SDL_Quit();

return 0;
}
