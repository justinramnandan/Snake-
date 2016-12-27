#include "Snake.h"
#include "Borders.h"
#include "Fruit.h"

//construcor for SnakeNode
Snake::SnakeNode::SnakeNode()
	:bodyPart({10, 10})
{

}
//constructof for snake
Snake::Snake()
	:dir(Direction::Left)
{
	//insert first body part
	snake.emplace_front();
	
}



Direction Snake::direction()
{
	return dir;
}

Direction Snake::direction(Direction dir)
{
	return this->dir = dir;
}


void Snake::update()
{
	//create a vector that gets the current position of the snake
	sf::Vector2f previous = getPosition();
	// use a switch that takes in the current direction and uodate the position accordingly
	switch (dir)
	{
	case Direction::Left:
		previous += {-10, 0};
		break;
	case Direction::Right:
		previous += {10, 0};
		break;
	case Direction::Up:
		previous += {0, -10};
		break;
	case Direction::Down:
		previous += {0,10};
		break;

	}
	// set position to new position
	setPosition(previous);

	for (SnakeNode& sn : snake)
	{
		auto temp = sn.getPosition();
		sn.setPosition(previous);
		previous = temp;
	}
	
}

bool Snake::collide(const Borders& borders)
{

//get the floatRect for each border 
auto left = borders.getLeft();
auto right = borders.getRight();
	
auto top = borders.getTop();
auto bot = borders.getBottom();

//get the floatRect of the head of the snake
auto bnds = getTransform().transformRect(snake.front().bodyPart.getGlobalBounds());
// return if there is a collision or not
return left.intersects(bnds) || right.intersects(bnds) || top.intersects(bnds)|| bot.intersects(bnds);
}



//not complete
bool Snake::collide(const Fruit& fruit)
{
	//if eaten grow the snake
	
	auto mouth = getTransform().transformRect(snake.front().bodyPart.getGlobalBounds());
	if (mouth.intersects(fruit.bounds()))
	{
		auto back = snake.back().getPosition();
		snake.emplace_back();
		switch (dir)
		{
		case Direction::Left:
			back += {10, 0};
			break;
		case Direction::Right:
			back += {-10, 0};
			break;
		case Direction::Up:
			back += {0, 10};
			break;
		case Direction::Down:
			back += {0, -10};
			break;

		}



		snake.back().setPosition(back);
		return true;
	}
	else
	{
		return false;
	}

	
	
}

void Snake::SnakeNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

	states.transform = getTransform();
	target.draw(bodyPart, states);

}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& sn : snake)
	{
		target.draw(sn, getTransform());
	}
}
