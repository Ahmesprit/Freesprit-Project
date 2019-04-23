/**
* @file text.c
* @brief this is the text file
* @author hedi 
* 
*/
#include "text.h"
/**
* @brief To initialize the Text T .
* @param T the Text
* @return Nothing
*/
void initText(Text *T)
{
	T->textDt=NULL;
	T->textPosition=NULL;
	T->textVitesse=NULL;
	T->textAcceleration=NULL;
}
/**
* @brief To load the Font .
* @param police the police to wirte with
* @return EXIT_FAILURE or EXIT_SUCCESS
*/
int loadFont(TTF_Font **police)
{
	if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return EXIT_FAILURE;
	}
	*police = TTF_OpenFont("../images/Ubuntu-Title.ttf", 20);
	return EXIT_SUCCESS;
}

/**
* @brief To display the Text .
* @param police the police to wirte with
*@param T the text
*@param screen the surface
*@param V type voiture
*@param bg the background
@param dt the time
* @return nothing
*/
void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,Voiture V,Background Bg,Uint32 dt)
{
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Rect positionTextDt;
	SDL_Rect positionTextPos;
	SDL_Rect positionTextVitesse;
	SDL_Rect positionTextAcceleration;

	positionTextDt.x=SCREEN_W-300;
	positionTextPos.x=SCREEN_W-300;
	positionTextVitesse.x=SCREEN_W-300;
	positionTextAcceleration.x=SCREEN_W-300;

	positionTextDt.y=20;
	positionTextPos.y=50;
	positionTextVitesse.y=80;
	positionTextAcceleration.y=110;

	char DT[50];
	char vitesse[50];
	char acceleration[50];
	char position[50];

	//dt
dt=25;
	sprintf(DT,"dt= %d ms",dt);
	T->textDt = TTF_RenderText_Shaded(police,DT,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textDt, SDL_SRCCOLORKEY, SDL_MapRGB(T->textDt->format, 255, 255, 255));

	//position
	sprintf(position,"pos x=%d pixels",V.position.x);
	T->textPosition = TTF_RenderText_Shaded(police,position,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textPosition, SDL_SRCCOLORKEY, SDL_MapRGB(T->textPosition->format, 255, 255, 255));
	//vitesse
	sprintf(vitesse,"vitesse= %f m/s",V.velocity);
	T->textVitesse = TTF_RenderText_Shaded(police,vitesse,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textVitesse, SDL_SRCCOLORKEY, SDL_MapRGB(T->textVitesse->format, 255, 255, 255));
	//acceleration
	sprintf(acceleration,"acceleration= %f m/s/s",V.acceleration);
	T->textAcceleration = TTF_RenderText_Shaded(police,acceleration,couleurNoire, couleurBlanche);
	SDL_SetColorKey(T->textAcceleration, SDL_SRCCOLORKEY, SDL_MapRGB(T->textAcceleration->format, 255, 255, 255));
	//clean screen &&
	//Flip the backbuffer to the primary Hardware Video Memory
	SDL_BlitSurface(T->textDt,NULL,screen,&positionTextDt);
	SDL_BlitSurface(T->textPosition,NULL,screen,&positionTextPos);
	SDL_BlitSurface(T->textVitesse,NULL,screen,&positionTextVitesse);
	SDL_BlitSurface(T->textAcceleration,NULL,screen,&positionTextAcceleration);

}
/**
* @brief To free the Font .
* @param police the police to wirte with
* @return nothing
*/
void freeFont(TTF_Font **police)
{
	TTF_CloseFont(*police); /* Doit être avant TTF_Quit() */
    TTF_Quit();	
}
