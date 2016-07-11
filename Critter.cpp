/*********************************************************************
** Program Filename: Critter.cpp
** Author: Sarah Walter
** Date: July 9, 2016
** Description: This is the implementation file for the Critter class.
*********************************************************************/

#include "Critter.h"
#include <time.h>
#include <cstdlib>


/* Constructor */
Critter::Critter()
{
	/* Initialize counters to zero */
	timeToBreedCounter = 0;
	timeToDeathCounter = 0;
}


/* Destructor */
Critter::~Critter()
{

}



/*********************************************************************
** Function: eat(int x)
** Description: If critter is doodlebug that moves to ant, critter eats,
** set timeToDeathCounter to 0
** Parameters: Critter type and position
** Pre-Conditions: Only Doodlebugs eat && only when on an ant
** Post-Conditions: Time to death counter is reset
*********************************************************************/
void Critter::eat(int x)
{
	if ((info == 'D') && (x == 1))
	{
		timeToDeathCounter = 0;
	}
	else timeToDeathCounter++;
}



/*********************************************************************
** Function: move()
** Description: Move critter randomly on game board
** Parameters: Starting position of critter
** Pre-Conditions: Item can move/isn't trapped
*********************************************************************/
int Critter::move()
{
	return ((rand() % 4) + 1);
}



/*********************************************************************
** Function: breed()
** Description: Check critter type and breeding counter. If it is time,
** the critter breeds and counter is reset.
** Parameters: Critter type and timeToBreedCounter
** Pre-Conditions: It is time for the critter to breed
** Post-Conditions: Either critter will breed and there will be another critter
** of that type and counter is reset, OR counter increments.
*********************************************************************/
bool Critter::breed()
{
	/* If it's an ant and it's time for it to breed */
	if (info == 'A' && timeToBreedCounter == breedLimit)
	{
		timeToBreedCounter = 0;
		return true;
	}
	/* If it's a doodlebug and time to breed */
	else if (info == 'D' && timeToBreedCounter == breedLimit)
	{
		timeToBreedCounter = 0;
		return true;
	}

	/* Otherwise just increment counter */
	timeToBreedCounter++;

	return false;
}



/*********************************************************************
** Function: died()
** Description: If critter has reached liveLimit, it dies and is removed
** from the board.
** Parameters: Critter's timeToDeathCounter and liveLimit
*********************************************************************/
bool Critter::died()
{
	if (timeToDeathCounter >= liveLimit)
		return true;

	return false;
}
