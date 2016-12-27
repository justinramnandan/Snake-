#pragma once

#include "Sfml/Graphics/CircleShape.hpp"
#include <SFML\Graphics/Drawable.hpp>

#include <SFML\Graphics.hpp>



 class Fruit: public sf::Drawable
{
private:
	//this function needs a reference to the window
	//make it private and static
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	 sf::CircleShape fruit;
public:
	//constructor for the fruit takes a reference to the window
	sf::Vector2f setFruitPosition(sf::RenderTarget& window);
	//constructor for fruit
	Fruit(sf::RenderTarget& window);
	// getter method for fruit
	sf::CircleShape& getFruit();
	// creates the fruit and sets the color of the fruit
	sf::CircleShape drawFruit();
	

	// Inherited via Drawable
	sf::FloatRect bounds() const;
 };