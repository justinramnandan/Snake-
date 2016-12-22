
#include "Fruit.h"


Fruit::Fruit()
{
	fruit = drawFruit();
	fruit.setPosition(setFruitPosition());
}

sf::CircleShape Fruit::getFruit()
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

sf::Vector2f Fruit::setFruitPosition()
{
	srand(time(NULL));
	
	int xPos;
	int yPos;

	xPos = rand() % window.getSize().x - 20;
	yPos = rand() % window.getSize().y - 20;

	return sf::Vector2f(xPos, yPos);
}

void Fruit::drawFruitToWindow(sf::RenderWindow& window)
{
	window.draw(fruit);
}
