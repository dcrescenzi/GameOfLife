#pragma once
#include <SFML/Graphics.hpp>

class HUD {

private:
	sf::Font font;

	sf::Text state;
	sf::Text speed;
	sf::Text instr;

public:
	void displayHUD(sf::RenderWindow& window, bool running, float gameSpeed);

	HUD();
};