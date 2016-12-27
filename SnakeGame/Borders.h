#pragma once

#include <SFML/Graphics.hpp>

class Borders : public  sf::Drawable
{
public:
	Borders(sf::RenderTarget& target);

	sf::FloatRect getLeft() const;
	sf::FloatRect getRight() const;
	sf::FloatRect getTop() const;
	sf::FloatRect getBottom() const;

private:

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	sf::RectangleShape left;
	sf::RectangleShape top;
	sf::RectangleShape bottom;
	sf::RectangleShape right;
};




 