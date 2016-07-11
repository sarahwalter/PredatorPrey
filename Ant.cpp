/*********************************************************************
** Program Filename: Ant.cpp
** Author: Sarah Walter
** Date: July 9, 2016
** Description: This is the implementation file for the Ant class.
*********************************************************************/

#include "Ant.h"



/*
** Constructor which holds liveLimit, breedLimit, and info symbol for Ants
*/
Ant::Ant()
{
	liveLimit = 10;
	breedLimit = 3;

	timeToBreedCounter = 0;
	timeToDeathCounter = 0;
	info = 'A';
}


/* Destuctor */
Ant::~Ant()
{

}
