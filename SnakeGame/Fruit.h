#pragma once

#include "Window.h"
#include<cstdlib>

 class Fruit
{
private:
	 sf::CircleShape fruit;
public:
	Fruit();
	sf::CircleShape getFruit();
	sf::CircleShape drawFruit();
	
	sf::Vector2f setFruitPosition();
	void drawFruitToWindow(sf::RenderWindow&);
};