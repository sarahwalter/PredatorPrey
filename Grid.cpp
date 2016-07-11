/*********************************************************************
** Program Filename: Grid.cpp
** Author: Sarah Walter
** Date: July 9, 2016
** Description: This is the implementation file for the Grid class.
*********************************************************************/


#include "Grid.h"

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;



Grid::Grid(Critter *critters[20][20])
{
	/* Initialize all to zero */
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			critters[i][j] = NULL;
		}
	}
}


Grid::~Grid()
{

}


/*********************************************************************
** Function: initialize(Critter *critters[20][20])
** Description: Randomly place ants and doodlebugs into the matrix
** Parameters: Matrix, can't place two critters in one space
*********************************************************************/
void Grid::initialize(Critter *critters[20][20])
{
	int i = 0;

	/* Plant 5 doodle bugs on random places in the matrix */
	while (i < 5)
	{
		int m = 0, n = 0;

		/* Run until an empty space is found */
		while (critters[m][n] != NULL)
		{
			m = rand() % 20;
			n = rand() % 20;
		}

		/* Put new doodlebug in empty space */
		critters[m][n] = new Doodlebug;

		i++;
	}

	i = 0;				/* Reset counter */

	/* Do the same for 100 ants */
	while (i < 100)
	{
		int m = 0, n = 0;

		while (critters[m][n] != NULL)
		{
			m = rand() % 20;
			n = rand() % 20;
		}

		critters[m][n] = new Ant;

		i++;
	}
}


/*********************************************************************
** Function: printMatrix(Critter *critters[20][20])
** Description: Prints the matrix
** Parameters: Position of critters in matrix
*********************************************************************/
void Grid::printMatrix(Critter *critters[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		cout << "\t|";
		for (int j = 0; j < 20; j++)
		{
			if (critters[i][j] != NULL)
			{
				if (critters[i][j]->info == 'A')
					cout << "A";
				else cout << "D";
			}
			else cout << " ";
		}
		cout << "|" << endl;
	}

	cout << endl << endl;
}


/*********************************************************************
** Function: isFinished(Critter *critters[20][20])
** Description: Runs through the matrix, if it finds a doodlebug it returns false.
** I elaborate on this in my design document, but I found under the conditions given
** in the end only the ants survive.
** Parameters: Critters in matrix.
*********************************************************************/
bool Grid::isFinished(Critter *critters[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (critters[i][j] != NULL)
			if (critters[i][j]->info == 'D')
				return false;
		}
	}

	return true;
}


/*********************************************************************
** Function: doTurn(Critter *critters[20][20])
** Description: Handles the turn. Starts by breeding as appropriate.
** Then goes through moving and eating. This implementation is discussed
** in my design document.
** Parameters: Critter positions, breed counters.
*********************************************************************/
void Grid::doTurn(Critter *critters[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (critters[i][j] != NULL)
			{
				bool b = critters[i][j]->breed();

				if (b)
				{
					/* Try to place another critter above current one */
					if ((i != 0) && (critters[i - 1][j] == NULL))
					{
						if (critters[i][j]->info == 'D')
							critters[i - 1][j] = new Doodlebug;
						else
							critters[i - 1][j] = new Ant;
					}
					else if ((j != 19) && (critters[i][j + 1] == NULL))
					{
						/* Try to place new critter to the right */
						if (critters[i][j]->info == 'D')
							critters[i][j + 1] = new Doodlebug;
						else
							critters[i][j + 1] = new Ant;
					}
					else if ((i != 19) && (critters[i + 1][j] == NULL))
					{
						/* Try to place beneath */
						if (critters[i][j]->info == 'D')
							critters[i + 1][j] = new Doodlebug;
						else
							critters[i + 1][j] = new Ant;
					}
					else if ((j != 0) && (critters[i][j - 1] == NULL))
					{
						/* Try to place to the left */
						if (critters[i][j]->info == 'D')
							critters[i][j - 1] = new Doodlebug;
						else
							critters[i][j - 1] = new Ant;
					}
				}
				/* This concludes the breeding */

				int m = critters[i][j]->move();

				if (critters[i][j]->info == 'D')
				{
					switch (m)
					{
					case 0:
						if (i != 0)
						{
							if (critters[i - 1][j] != NULL)
							{
								if (critters[i - 1][j]->info == 'A')
								{
									/* Move object, Doodlebug "eats" Ant above itself */
									delete critters[i - 1][j];
									critters[i][j]->eat(1);
								}
								else
								{
									critters[i][j]->eat(0);
								}
							}
							else
							{
								critters[i][j]->eat(0);
							}
							critters[i - 1][j] = new Doodlebug(critters[i][j]);
							delete critters[i][j];
							critters[i][j] = NULL;
						}
						else
							critters[i][j]->eat(0);
						break;
					case 1:
						if (j != 19)
						{
							/* Move object. Doodlebug eats ant to the right of itself */
							if (critters[i][j + 1] != NULL)
							{
								if (critters[i][j + 1]->info == 'A')
								{
									delete critters[i][j + 1];
									critters[i][j]->eat(1);
								}
								else
								{
									critters[i][j]->eat(0);
								}
							}
							else
							{
								critters[i][j]->eat(0);
							}
							critters[i][j + 1] = new Doodlebug(critters[i][j]);
							delete critters[i][j];
							critters[i][j] = NULL;
						}
						else
							critters[i][j]->eat(0);
						break;

					/*
					** Try to move down and see if it's possible
					*/
					case 2:
						if (i != 19)
						{
							if (critters[i + 1][j] != NULL)
							{
								if (critters[i + 1][j]->info == 'A')
								{
									delete critters[i + 1][j];
									critters[i][j]->eat(1);
								}
								else
								{
									critters[i][j]->eat(0);
								}
							}
							else
							{
								critters[i][j]->eat(0);
							}
							critters[i + 1][j] = new Doodlebug(critters[i][j]);
							delete critters[i][j];
							critters[i][j] = NULL;
						}
						else
							critters[i][j]->eat(0);
						break;

					/*
					** Try to move left and see if it's possible
					*/
					case 3:
						if (j != 0)
						{
							if (critters[i][j - 1] != NULL)
							{
								if (critters[i][j - 1]->info == 'A')
								{
									delete critters[i][j - 1];
									critters[i][j]->eat(1);
								}
								else
								{
									critters[i][j]->eat(0);
								}
							}
							else
							{
								critters[i][j]->eat(0);
							}
							critters[i][j - 1] = new Doodlebug(critters[i][j]);
							delete critters[i][j];
							critters[i][j] = NULL;
						}
						else
							critters[i][j]->eat(0);
						break;
					}
				}
			}
		}
	}
}
