#pragma once
#include <SFML/Graphics.hpp>
#include "GridCell.h"

class Grid {

public:
	Grid(int size, int dim, float currentTime);
	~Grid();

	void update(float deltaTime, float wait);
	void draw(sf::RenderWindow& window);
	void clear();

	void setStatus(int i, int j, bool status);
	int getCellSize();

private:
	GridCell*** grid;
	int cellDim;
	float currentTime;

	int numAliveNeighbours(int x, int y, int size); //will not account for negative or too high indicies
};