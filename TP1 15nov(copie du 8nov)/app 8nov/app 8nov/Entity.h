#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	sf::Vector2f position;
	sf::RectangleShape tank;
	Entity(sf::Vector2f pos, sf::Vector2f size)
	{
		tank.setSize(size);
		tank.setOrigin(size.x / 2, size.y / 2);
		position = pos;
		tank.setFillColor(sf::Color::Magenta);
		tank.setPosition(pos);

	};
	void SetPosition()
	{
		tank.setPosition(position);
	}

};

