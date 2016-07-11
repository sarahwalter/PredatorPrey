/*********************************************************************
** Program Filename: main.cpp
** Author: Sarah Walter
** Date: July 9, 2016
** Description: This is the main implementation file.
*********************************************************************/

#include <iostream>

#include "Ant.h"
#include "Doodlebug.h"
#include "Grid.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
	/* 20x20 array of critters */
	Critter* critters[20][20];
	Grid grid(critters);

	/* Random seed for critter placement */
	srand(time(NULL));

	grid.initialize(critters);

	/* Print matrix */
	grid.printMatrix(critters);

	/* End of initialization */


	/*
	** While the game is still in progress, keep making turns and printing the matrix
	*/
	while (!grid.isFinished(critters))
	{
		grid.doTurn(critters);

		grid.printMatrix(critters);

		cin.get();
	}

	/* Deallocating all allocated memory */
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (critters[i][j] != NULL)
			{
				delete critters[i][j];
			}
		}
	}

	return 0;
}


