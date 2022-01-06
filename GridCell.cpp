#include "GridCell.h"
#include <iostream>

GridCell::GridCell(int x, int y, int dim, bool alive) 
{
	this->cell = sf::RectangleShape(sf::Vector2f((float)dim, (float)dim));
	this->cell.setPosition(float(x), float(y));
	this->alive = alive;

	this->delayFlag = false;
	this->delayState = false;
}
GridCell::~GridCell() {}

void GridCell::draw(sf::RenderWindow& window) 
{
	if (this->alive) this->cell.setFillColor(sf::Color::Black);
	else this->cell.setFillColor(sf::Color::White);

	window.draw(this->cell);
}

int GridCell::getDim() 
{
	return this->cell.getSize().x;
}

bool GridCell::getAlive() 
{
	return this->alive;
}

void GridCell::setAlive(bool state) 
{
	this->alive = state;
}

bool GridCell::getDelay() 
{
	return this->delayFlag;
}

void GridCell::setDelay(bool flag) 
{
	this->delayFlag = flag;
}

bool GridCell::getDelayState() 
{
	return this->delayState;
}

void GridCell::setDelayState(bool state) 
{
	this->delayState = state;
}