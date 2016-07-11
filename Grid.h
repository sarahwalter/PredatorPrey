/*********************************************************************
** Program Filename: Grid.h
** Author: Sarah Walter
** Date: July 9, 2016
** Description: This is the header file for the Grid class.
*********************************************************************/


#ifndef GRID_H
#define GRID_H

#include "Critter.h"
#include "Ant.h"
#include "Doodlebug.h"

class Grid
{
public:
	Grid(Critter *critters[20][20]);
	~Grid();

	void initialize(Critter *critters[20][20]);
	void printMatrix(Critter *critters[20][20]);
	bool isFinished(Critter *critters[20][20]);
	void doTurn(Critter *critters[20][20]);
};

#endif 
