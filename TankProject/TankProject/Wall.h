#pragma once
#include <SFML/Graphics.hpp>
class Wall
{
public:
	sf::Vector2f position;
	sf::RectangleShape wallet;
	sf::String Orientation;
	Wall(sf::Vector2f pos, sf::Vector2f size, sf::String Ori)
	{
		wallet.setSize(size);
		position = pos;
		wallet.setFillColor(sf::Color::Magenta);
		wallet.setPosition(pos);
		Orientation = Ori;

	};
	void SetPosition()
	{
		wallet.setPosition(position);
	}
};

