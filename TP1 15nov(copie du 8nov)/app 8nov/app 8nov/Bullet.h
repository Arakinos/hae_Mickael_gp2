#pragma once

#include <SFML/Graphics.hpp>
#include <random>


class Bullet
{
	bool left;
	bool right;
	public:
		sf::Vector2f position;
		sf::CircleShape Shape;
		float speed;
		Bullet(sf::Vector2f _pos,float size, sf::Color Color)
		{
			Shape.setRadius((size));
			position = _pos;
			Shape.setFillColor(Color);
			Shape.setPosition(_pos);
		};
		void SetPosition()
		{
			Shape.setPosition(position);
		}
};

