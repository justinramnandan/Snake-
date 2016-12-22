#include "Borders.h"

sf::RectangleShape leftBorder()
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(10, window.getSize().y));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(0, 0);

	return rect;

}
sf::RectangleShape topBorder()
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(window.getSize().x, 10));
	rect.setFillColor(sf::Color::Cyan);
	rect.setPosition(0, 0);

	return rect;
}
sf::RectangleShape bottomBorder()
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(window.getSize().x, 10));
	rect.setFillColor(sf::Color::Blue);
	rect.setPosition(0, window.getSize().y-10);

	return rect;
}
sf::RectangleShape rightBorder()
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(10, window.getSize().y));
	rect.setFillColor(sf::Color::Yellow);
	rect.setPosition(window.getSize().x-10,0 );

	return rect;
}


