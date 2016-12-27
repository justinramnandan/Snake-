
#pragma once

#include "SFML\Graphics.hpp"

#include <list>
// needed as paramters for certain functions therefore included
class Borders;
class Fruit;
//function to create a body part

//enum to track direction moving
enum class Direction
{
	Left,Right,Up,Down
};


//snake class inherits drawable and transformable
class Snake : public sf::Drawable, public sf::Transformable
{
private:
	// the snake list takes in these SnakeNodes / inherits from drawable and transformable
	struct SnakeNode : public sf::Drawable, sf::Transformable
	{
		sf::RectangleShape bodyPart;
		SnakeNode();

			// Inherited via Drawable
			virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	};
	//snake list
	std::list<SnakeNode> snake;
	//enum to track direction of snake
	Direction dir;
public:
	//constructor
	Snake();
	//updates position of the snake
	void update();
	// return the direction
	Direction direction();
	// sets the direction
	Direction direction(Direction dir);
	//check for collision with a border
	bool collide( const Borders& border);
	//checks for a collision with a fruit
	bool collide(const Fruit& fruit);
	

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

};


