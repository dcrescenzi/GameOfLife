#include <SFML/Graphics.hpp>
#include <iostream>

#include "Grid.h"
#include "Editor.h"
#include "HUD.h"

int main() 
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "Conway's Game of Life", sf::Style::Close | sf::Style::Resize);
	
	float deltaTime = 0.0f;
	sf::Clock clock;

	Grid grid(900, 100, 0.0f);	
	Editor editor;
	HUD hud;

	bool running = true;
	float speed = 0.5;

	while (window.isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event e;
		while (window.pollEvent(e)) 
		{ 
			switch (e.type) 
			{
				case sf::Event::Closed:
					window.close();
					break;
			}

			if (e.type == e.Closed) window.close();
		}

		//===

		window.clear();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) running = true;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) running = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) speed += 0.05f;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) speed -= 0.05f;

		speed = (speed <= 0.001) ? 0.001 : speed;

		if (running) grid.update(deltaTime, speed);
		else editor.update(grid, window);
		
		grid.draw(window);
		hud.displayHUD(window, running, speed);

		window.display();

		//===
	}

	return (0);
}