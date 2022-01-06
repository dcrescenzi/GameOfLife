#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "GridCell.h"

Grid::Grid(int size, int dim, float currentTime) 
{
	this->currentTime = 0.0f;

	this->cellDim = dim;
	this->grid = new GridCell** [cellDim];

	int cellWidth = (int)size / dim;

	for (int i = 0; i < cellDim; i++) 
	{
		this->grid[i] = new GridCell* [cellDim];

		for (int j = 0; j < cellDim; j++) 
		{
			this->grid[i][j] = new GridCell(i * cellWidth, j * cellWidth, cellWidth, false);
		}
	}
}
Grid::~Grid() 
{
	for (int i = 0; i < this->cellDim; i++)
	{
		for (int j = 0; j < this->cellDim; j++)
		{
			delete this->grid[i][j];
		}

		delete[] this->grid[i];
	}

	delete[] this->grid;
}

void Grid::update(float deltaTime, float wait) 
{
	if (this->currentTime >= wait)
	{
		currentTime -= wait;

		int aliveAdj;

		for (int i = 1; i < this->cellDim-1; i++)
		{
			for (int j = 1; j < this->cellDim-1; j++)
			{
				aliveAdj = numAliveNeighbours(i, j, this->cellDim);

				if (this->grid[i][j]->getAlive()) //cell is alive
				{
					if ((aliveAdj < 2) || (aliveAdj > 3))
					{
						this->grid[i][j]->setDelay(true);
						this->grid[i][j]->setDelayState(false);
					}
				}
				else //cell is dead
				{
					if (aliveAdj == 3)
					{
						this->grid[i][j]->setDelay(true);
						this->grid[i][j]->setDelayState(true);
					}
				}
			}
		}

		for (int i = 1; i < this->cellDim - 1; i++)
		{
			for (int j = 1; j < this->cellDim - 1; j++)
			{
				if (this->grid[i][j]->getDelay())
				{
					if (this->grid[i][j]->getDelayState()) this->grid[i][j]->setAlive(true);
					else this->grid[i][j]->setAlive(false);

					this->grid[i][j]->setDelay(false);
				}
			}
		}

	} else this->currentTime += deltaTime;
}

void Grid::draw(sf::RenderWindow& window) 
{
	for (int i = 0; i < this->cellDim; i++)
	{
		for (int j = 0; j < this->cellDim; j++)
		{
			this->grid[i][j]->draw(window);
		}
	}
}

void Grid::clear() 
{
	for (int i = 0; i < this->cellDim; i++)
	{
		for (int j = 0; j < this->cellDim; j++)
		{
			this->grid[i][j]->setAlive(false);
		}
	}
}

void Grid::setStatus(int i, int j, bool status) 
{
	if (i < 0 || i > cellDim - 1 || j < 0 || j > cellDim - 1) return;

	this->grid[i][j]->setAlive(status);
}

int Grid::getCellSize() 
{
	return this->grid[0][0]->getDim();
}

int Grid::numAliveNeighbours(int xOff, int yOff, int size) 
{
	int total = 0;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (!((i == 0) && (j == 0))) 
			{
				if(this->grid[xOff + i][yOff + j]->getAlive() == true) total++;
			}
		}
	}

	return total;
}