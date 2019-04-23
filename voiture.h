#ifndef Voiture_H
#define Voiture_H
/**
* @struct Voiture
* @brief struct for Voiture
*/
#include <SDL/SDL.h>
#include "background.h"

		

		
struct Voiture{
	SDL_Rect position; /*!< Rectangle*/
	SDL_Surface * image[4]; /*!< Surface. */
	int score; /*!< The score of the game */
	int vie;/*!< Lives of your car */

	int direction; //0:right 1:left 2:up /*!< Your direction */
	int moving; //0:not moving 1:moving /*!< if the car moving 0 if the car not moving 1 */
	float Mass;/*!< The mass of your car */

	double velocity; /*!< the velocity of your car */
	double acceleration;/*!< the acceleration of your car */
};
typedef struct Voiture Voiture;

int loadVoitureImages(Voiture * A);

void initVoiture(Voiture *A);

void moveVoiture(Voiture *A,Background *B,Uint32 dt);


void freeVoiture(Voiture *A);

#endif
