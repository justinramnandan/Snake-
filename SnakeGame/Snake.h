
#pragma once

#include "SFML\Graphics.hpp"

#include <list>

//function to create a body part
static sf::RectangleShape drawBodyPart()
{
	sf::RectangleShape part;
	part.setSize(sf::Vector2f(10, 10));
	part.setFillColor(sf::Color::Green);

	return part;
}

//enum to track direction moving
enum Direction{LEFT,RIGHT,UP,DOWN};

//body parts for the snake

struct SnakeNode
{
	sf::RectangleShape bodyPart;
	
	SnakeNode()
	{
		bodyPart = drawBodyPart();
		
	}

};





//snake class
class Snake
{
public:
	std::list<SnakeNode> snake;
	Direction dir;
	//want to track the x and y location of the head to track collision 
	//working on the implementation of this
	
	double xPos, yPos;


	Snake(SnakeNode sn);
	void changePosition();
	Direction getPosition();
	void move(double & xPos,double & yPos);
	double getXPos();
	double getYPos();
	
	
	bool collide(sf::RectangleShape& topBorder, sf::RectangleShape& bottomBorder, sf::RectangleShape& leftBorder, sf::RectangleShape& rightBorder);

	void grow();
	
};


