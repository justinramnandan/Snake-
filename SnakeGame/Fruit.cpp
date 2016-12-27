
#include "Fruit.h"

#include "SFML\Graphics.hpp"
#include<cstdlib>
#include <ctime>

// creates a fruit and sets the color and position
Fruit::Fruit(sf::RenderTarget& window)
	: fruit(5)
{

	fruit.setFillColor(sf::Color::Magenta);
	fruit.setPosition(setFruitPosition(window));
}

sf::CircleShape& Fruit::getFruit()
{
	return fruit;
}

sf::CircleShape Fruit::drawFruit()
{
	sf::CircleShape circle;
	circle.setRadius(5);
	circle.setFillColor(sf::Color::Magenta);

	return circle;
}

sf::FloatRect Fruit::bounds() const
{
	return fruit.getGlobalBounds();
}



sf::Vector2f Fruit::setFruitPosition(sf::RenderTarget& window)
{
	srand(time(NULL));
	
	

	int xPos = rand() % (window.getSize().x - 20) +20;
	int yPos = rand() % (window.getSize().y - 20) +20;

	sf::Vector2f next(xPos, yPos);
	
	fruit.setPosition(next);

	return next;
}


void Fruit::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(fruit);
}
