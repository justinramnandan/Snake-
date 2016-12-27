

#include "Game.h"
#include "Borders.h"
#include "Fruit.h"
#include "Snake.h"
#include <iostream>


// text object
void game()
{
	//creating the renderwindow
	sf::RenderWindow window(sf::VideoMode(640, 480), "Snake");

	//set frame rate to 10 frames per second

	window.setFramerateLimit(10);

	//variable to track different events that take place

	//use this to draw the snake only the first time
	bool firstIteration = true;
	//fruit object
	Fruit fruit(window);
	
	//borders object
	Borders borders(window);
	
	//creating snake object
	Snake snake;
	
	snake.setPosition(static_cast<sf::Vector2f>(window.getSize()) / 2.f);

	//main loop
	
	while (window.isOpen() && !snake.collide(borders))
	{
		//do event handling first
		sf::Event event;
		while (window.pollEvent(event))
		{

			//if most recent event is close button close the window
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				// change the direction the snake is going
				case sf::Keyboard::Left:
					snake.direction(Direction::Left);
					break;

				case sf::Keyboard::Right:
					snake.direction(Direction::Right);
					break;

				case sf::Keyboard::Up:
					snake.direction(Direction::Up);
					break;

				case sf::Keyboard::Down:
					snake.direction(Direction::Down);
					break;

				//exits the program is esc key is pressed
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
			}
		}
			//clears the window
			window.clear();
			// draws the fruit
			window.draw(fruit);

			//drawing the snake
			window.draw(snake);
			//draw the borders
			window.draw(borders);

			// if snake collides with fruit reset the position of the fruit
			//snake.collide function takes care of growing the snake
			if (snake.collide(fruit))
			{
				fruit.setFruitPosition(window);
			}
			// deals with movement fo the snake
			snake.update();

				//display the content drawn to the window
				window.display();

	}

	
}