
#include "Snake.h"

//constructor for snake 
//inserts a snakeNode at the beginning of snake

Snake::Snake(SnakeNode sn)
{
	//insert first body part
	snake.insert(snake.end(), sn);
	
}


double Snake::getXPos()
{
	return xPos;
}

double Snake::getYPos()
{
	return yPos;
}

//detcts for changes in derections using direction enum
void Snake::changePosition()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		dir = UP;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		dir = DOWN;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		dir = LEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		dir = RIGHT;
	}
}



Direction Snake::getPosition()
{
	return dir;
}

//detects movement of the snake
void Snake::move(double & xPos, double & yPos)
{
	if (dir == UP)
	{
		for (SnakeNode sn : snake)
		{
			
			sn.bodyPart.move(0, -1);
			yPos--;
		}
	}

	else if (dir == DOWN)
	{
		for (SnakeNode sn : snake)
		{
			sn.bodyPart.move(0, 1);
			yPos++;
		}
	}

	else if (dir == LEFT)
	{
		for (SnakeNode sn : snake)
		{
			sn.bodyPart.move(-1, 0);
			xPos--;
		}
	}
	else if (dir == RIGHT)
	{
		for (SnakeNode sn : snake)
		{
			sn.bodyPart.move(1,0);
			xPos++;
		}
	}

}

bool Snake::collide(sf::RectangleShape& topBorder, sf::RectangleShape& bottomBorder, sf::RectangleShape& leftBorder, sf::RectangleShape& rightBorder)
{
	/*
	Currently what I have for the collide method
	Trying to detect if the head of the snake collides with any of the four borders
	Tried doing this using the getGlobalBounds() of snake and seeing if it intersects with the borders

	Probable causes:
	1) Issue may be how the borders are drawn and their position is my theory
		a)snake.front().bodyPart.getGlobalBounds().intersects(leftBorder.getGlobalBounds()) returns true
		b) may be an issue with how the border is drawn or where it is positioned?

	*/

	bool flag = false;
	
	
	if (snake.front().bodyPart.getGlobalBounds().intersects(topBorder.getGlobalBounds())||
		snake.front().bodyPart.getGlobalBounds().intersects(bottomBorder.getGlobalBounds())||
		snake.front().bodyPart.getGlobalBounds().intersects(leftBorder.getGlobalBounds())||
		snake.front().bodyPart.getGlobalBounds().intersects(rightBorder.getGlobalBounds()))
	{
		flag = true;
		
	}
	
	return flag;
}



//not complete
void Snake::grow()
{
	//if eaten grow the snake
		
		//to grow the snake create a new SnakeNode
		SnakeNode newPart;
		//link new node to the back of the snake
		snake.insert(snake.end(), newPart);
	
}






