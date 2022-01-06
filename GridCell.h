#pragma once

#include <SFML/Graphics.hpp>

class GridCell {

private:
	sf::RectangleShape cell;
	bool alive;
	bool delayFlag;
	bool delayState;

public:

	GridCell(int x, int y, int dim, bool alive);
	~GridCell();

	void draw(sf::RenderWindow& window);

	int getDim();

	bool getAlive();
	void setAlive(bool state);

	bool getDelay();
	void setDelay(bool flag);

	bool getDelayState();
	void setDelayState(bool state);
};