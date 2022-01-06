#include "HUD.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

HUD::HUD() 
{
	if (!this->font.loadFromFile("font/Lato-Regular.ttf")) std::cout << "Error loading font file" << std::endl;
}

void HUD::displayHUD(sf::RenderWindow& window, bool running, float gameSpeed) 
{
	this->state.setFont(this->font);
	this->speed.setFont(this->font);
	this->instr.setFont(this->font);

	this->state.setCharacterSize(16);
	this->speed.setCharacterSize(16);
	this->instr.setCharacterSize(16);

	this->state.setFillColor(sf::Color::Blue);
	this->speed.setFillColor(sf::Color::Blue);
	this->instr.setFillColor(sf::Color::Blue);

	this->state.setPosition(sf::Vector2f(5, 5));
	this->speed.setPosition(sf::Vector2f(5, 23));
	this->instr.setPosition(sf::Vector2f(5, 39));

	std::string state = running ? "running" : "editing";
	this->state.setString("state: " + state);

	this->speed.setString("delay: " + std::to_string(gameSpeed).substr(0, 5));

	this->instr.setString("press 'R' to run\npress 'E' to edit\npress 'C' to clear\npress UP/DOWN for speed");

	window.draw(this->state);
	window.draw(this->speed);
	window.draw(this->instr);
}