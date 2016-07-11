/*********************************************************************
** Program Filename: Critter.h
** Author: Sarah Walter
** Date: July 9, 2016
** Description: This is the header file for the Critter class.
*********************************************************************/


#ifndef CRITTER_H
#define CRITTER_H


class Critter
{
public:
	int timeToBreedCounter;
	int timeToDeathCounter;
	int breedLimit;
	int liveLimit;
	char info;

	Critter();
	~Critter();

	void eat(int);
	int move();
	bool breed();
	bool died();
};

#endif 
