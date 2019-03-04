#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
void showMenu(menuComponents mc, rectMenuComponents rmc){
rmc.posback.x=0;
rmc.posback.y=0;
rmc.posback.w=mc.back1->w;
rmc.posback.h=mc.back1->h;
rmc.posbutgame.x = 150;
rmc.posbutgame.y = 220;
rmc.posbutgame.w=mc.butgame->w;
rmc.posbutgame.h=mc.butgame->h;
rmc.posbutsettings.x = 150;
rmc.posbutsettings.y = 270;
rmc.posbutsettings.w=mc.butsettings->w;
rmc.posbutsettings.h=mc.butsettings->h;
rmc.posbutsettings.x = 150;
rmc.posbutsettings.y = 270;
rmc.posbutsettings.w=mc.butsettings2->w;
rmc.posbutsettings.h=mc.butsettings2->h;
rmc.posbutshop.x = 150;
rmc.posbutshop.y = 320;
rmc.posbutshop.w=mc.butshop->w;
rmc.posbutshop.h=mc.butshop->h;
rmc.posbutshop.x = 150;
rmc.posbutshop.y = 320;
rmc.posbutshop.w=mc.butshop2->w;
rmc.posbutshop.h=mc.butshop2->h;
rmc.posbutcredits.x = 150;
rmc.posbutcredits.y = 370;
rmc.posbutcredits.w=mc.butcredits->w;
rmc.posbutcredits.h=mc.butcredits->h;
rmc.posbutcredits.x = 150;
rmc.posbutcredits.y = 370;
rmc.posbutcredits.w=mc.butcredits2->w;
rmc.posbutcredits.h=mc.butcredits2->h;
rmc.posbutquit.x = 150;
rmc.posbutquit.y = 420;
rmc.posbutquit.w=mc.butquit->w;
rmc.posbutquit.h=mcbutquit->h;
rmc.posbutquit.x = 150;
rmc.posbutquit.y = 420;
rmc.posbutquit.w=mc.butquit2->w;
rmc.posbutquit.h=mc.butquit2->h;
rmc.posbuthelp.x = 910;
rmc.posbuthelp.y = 10;
rmc.posbuthelp.w=mc.buthelp->w;
rmc.posbuthelp.h=mc.buthelp->h;
rmc.posbutmusic.x = 910;
rmc.posbutmusic.y = 450;
rmc.posbutmusic.w=mc.butmusic->w;
rmc.posbutmusic.h=mc.butmusic->h;
rmc.posbutsound.x = 10;
rmc.posbutsound.y = 450;
rmc.posbutsound.w=mc.butsound->w;
rmc.posbutsound.h=mc.butsound->h;
SDL_BlitSurface(back1,NULL,screen,&posback);
SDL_Flip(mc.screen);

SDL_BlitSurface(mc.butgame,NULL,mc.screen,&rmc.posbutgame);
SDL_BlitSurface(mc.butsettings,NULL,mc.screen,&rmc.posbutsettings);
SDL_BlitSurface(mc.butshop,NULL,mc.screen,&rmc.posbutshop);
SDL_BlitSurface(mc.butcredits,NULL,mc.screen,&rmc.posbutcredits);
SDL_BlitSurface(mc.butquit,NULL,mc.screen,&rmc.posbutquit);
SDL_BlitSurface(mc.buthelp,NULL,mc.screen,&rmc.posbuthelp);
SDL_BlitSurface(mc.butmusic,NULL,mc.screen,&rmc.posbutmusic);
SDL_BlitSurface(mc.butsound,NULL,mc.screen,&rmc.posbutsound);
SDL_Flip(mc.screen);
}
