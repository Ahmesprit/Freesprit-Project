#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED
typedef struct{
SDL_Surface *screen;
SDL_Surface *back1;
SDL_Surface *back2;
SDL_Surface *back3;
SDL_Surface *back4;
SDL_Surface *back5;
SDL_Surface *back7;
SDL_Surface *back8;
SDL_Surface *back9;
SDL_Surface *butgame;
SDL_Surface *butsettings;
SDL_Surface *butshop;
SDL_Surface *butgame2;
SDL_Surface *butsettings2;
SDL_Surface *butshop2;
SDL_Surface *butcredits2;
SDL_Surface *butcredits;
SDL_Surface *butsound;
SDL_Surface *butmusic;
SDL_Surface *butsound2;
SDL_Surface *butmusic2;
SDL_Surface *buthelp;
SDL_Surface *butquit;
SDL_Surface *butquit2;
}menuComponents;

typedef struct {
   SDL_Surface *map1;
SDL_Surface *map2;
SDL_Surface *map3;
SDL_Surface *map4;
SDL_Surface *map5;
SDL_Surface *map6;

}backgroundMaps;

typedef struct {
   SDL_Surface *obj;
 //objects are way to be added here
}object;

 typedef struct {
   SDL_Surface *enm;
 //objects are way to be added here
}enemy;

typedef struct {
   SDL_Surface *eng;
 //objects are way to be added here
}enigme;

typedef struct {
   SDL_Surface *aziz;
SDL_Surface *ons;
SDL_Surface *amine;
SDL_Surface *ahmed;
SDL_Surface *hedi;
 //objects are way to be added here
}character;

menuComponents initMenu(menuComponents mc);
backgroundMaps initMaps (backgroundMaps bm);
object initObject (object o);
enigme initEngime(enigme e);
character initChar(character ch);
#endif 
