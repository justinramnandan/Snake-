#include "Borders.h"

//constructor that intializes the borders
Borders::Borders(sf::RenderTarget & target)
	:left({10.f, static_cast<float>(target.getSize().y)}),
	right({ 10.f, static_cast<float>(target.getSize().y)}),
	top ({ static_cast<float>(target.getSize().x), 10.f}),
	bottom({ static_cast<float>(target.getSize().x), 10.f})
{
	//colors
	left.setFillColor(sf::Color::Red);
	right.setFillColor(sf::Color::Yellow);
	top.setFillColor(sf::Color::Cyan);
	bottom.setFillColor(sf::Color::Cyan);
	bottom.setFillColor(sf::Color::Blue);
	// set position
	left.setPosition(0, 0);
	right.setPosition(target.getSize().x - right.getSize().x, 0);
	top.setPosition(0, 0);
	bottom.setPosition(0, target.getSize().y - bottom.getSize().y);

}
// get bounds of left
sf::FloatRect Borders::getLeft() const
{
	return left.getGlobalBounds();
}
// get bpunds of right
sf::FloatRect Borders::getRight() const
{
	return right.getGlobalBounds();
}
// get bounds of top
sf::FloatRect Borders::getTop() const
{
	return top.getGlobalBounds();
}
// get bounds of bottom
sf::FloatRect Borders::getBottom() const
{
	return bottom.getGlobalBounds();
}
// draw the borders
void Borders::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(left);
	target.draw(right);
	target.draw(top);
	target.draw(bottom);

}
