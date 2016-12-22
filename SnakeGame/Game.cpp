

#include "Game.h"
#include <iostream>

void game(sf::RenderWindow& window)
{

	//set frame rate to 60 frames per second
	window.setFramerateLimit(60);
	//variable to track different events that take place

	//use this to draw the snake only the first time
	bool firstIteration = true;
	//fruit object
	Fruit fruit;
	//creating head of snake
	SnakeNode head;
	//creating snake object
	Snake snake(head);
	double xPos = 0;
	double yPos = 0;

	// x position and y position of snake variables


	sf::RectangleShape top = topBorder();
	sf::RectangleShape left = leftBorder();
	sf::RectangleShape bottom = bottomBorder();
	sf::RectangleShape right = rightBorder();

	//main loop
	//do this while the window is open
	while (window.isOpen())
	{

		do
		{
			//clears the window
			window.clear();
			//draws the borders
			//drawBorders(window);
			//drawing the fruit

			window.draw(top);
			window.draw(left);
			window.draw(bottom);
			window.draw(right);

			fruit.drawFruitToWindow(window);

			//drawing the snake

			for (SnakeNode s : snake.snake)
			{
				//set the start position of the snake
				if (firstIteration == true)
				{
					// try creating a setPosition function for the snake similiar to what you did for fruit
					
					s.bodyPart.setPosition(window.getSize().x / 2, window.getSize().y / 2);
					xPos = window.getSize().x / 2;
					yPos = window.getSize().y / 2;
					
				}
				else {
					//else set the position of the snake to the new position
					s.bodyPart.setPosition(xPos, yPos);


				}
				//draw the snake
				window.draw(s.bodyPart);
				

				}
					
			    //set it to false after drawing the snake the first time
				firstIteration = false;


				sf::Event event;
				//poll event pops the most recent event that has taken place
				while (window.pollEvent(event))
				{

					//if most recent event is close button close the window
					if (event.type == sf::Event::Closed)
					{
						window.close();
					}

				}
				//detect for change in position
				snake.changePosition();
				
				//move the snake and update the x and y coordinates
				snake.move(xPos, yPos);

				//display window
				window.display();


			


		} while (!snake.collide(top, bottom, left,right));

		//keeps printing this in an infinite loop?

		if (snake.collide(top,bottom,left,right) == true)
		{
			std::cout << "Game Over" << std::endl;
		}
	}
}