/*********************************************************************
** Program Filename: Doodlebug.cpp
** Author: Sarah Walter
** Date: July 9, 2016
** Description: This is the implementation file for the Doodlebug class.
*********************************************************************/

#include "Doodlebug.h"


/*
** Constructor which holds liveLimit, breedLimit, and info symbol for Doodlebugs
*/
Doodlebug::Doodlebug()
{
	liveLimit = 3;
	breedLimit = 8;

	timeToBreedCounter = 0;
	timeToDeathCounter = 0;

	info = 'D';
}


/*
** Copy constructor: copies lifetime and eat parameters, moves it into
** proper cell in matrix. Used when doodlebug eats ant and takes its place.
*/
Doodlebug::Doodlebug(const Critter* cri)
{
	liveLimit = cri->liveLimit;
	breedLimit = cri->breedLimit;

	timeToBreedCounter = cri->timeToBreedCounter;
	timeToDeathCounter = cri->timeToDeathCounter;

	info = 'D';
}


/* Destructor */
Doodlebug::~Doodlebug()
{

}
