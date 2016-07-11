/*********************************************************************
** Program Filename: Doodlebug.h
** Author: Sarah Walter
** Date: July 9, 2016
** Description: This is the header file for the Doodlebug class.
*********************************************************************/


#ifndef DOODLEBUG_H
#define DOODLEBUG_H
#include "Critter.h"

class Doodlebug : public Critter
{
public:
	Doodlebug();
	Doodlebug(const Critter* cri);
	~Doodlebug();
};


#endif 