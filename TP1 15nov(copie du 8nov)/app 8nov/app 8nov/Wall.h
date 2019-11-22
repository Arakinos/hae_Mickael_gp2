#pragma once
#include <SFML/Graphics.hpp>
class Wall
{
public:
	sf::Vector2f position;
	sf::RectangleShape wallet;
	Wall(sf::Vector2f pos, sf::Vector2f size)
	{
		wallet.setSize(size);
		position = pos;
		wallet.setFillColor(sf::Color::Magenta);
		wallet.setPosition(pos);

	};
	void SetPosition()
	{
		wallet.setPosition(position);
	}
};

