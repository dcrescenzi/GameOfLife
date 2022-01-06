#include "Editor.h"
#include <iostream>

void Editor::update(Grid& g, sf::RenderWindow& window)
{
	sf::Vector2i mousepos;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mousepos = sf::Mouse::getPosition(window);

		g.setStatus(mousepos.x / g.getCellSize(), mousepos.y / g.getCellSize(), true);
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		mousepos = sf::Mouse::getPosition(window);

		g.setStatus(mousepos.x / g.getCellSize(), mousepos.y / g.getCellSize(), false);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) g.clear();
}