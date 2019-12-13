#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Entity
{
	
public:
	sf::Vector2f position;
	sf::RectangleShape tank;
	sf::RectangleShape Viseur;
	sf::RectangleShape BoxCollider;
	sf::FloatRect Box;
	sf::Texture *texture;
	sf::Texture *textureViseur;
	Entity(sf::Vector2f pos,sf::Vector2f size,sf::Texture* tex, sf::Texture*texV)
	{
		Viseur.setOrigin((Viseur.getSize().x / 2) + 20, 14);
		BoxCollider.setSize(size);
		tank.setSize(size);
		tank.setOrigin(Vector2f((size.x / 2), (size.y/2)));
		position = pos;
		tank.setFillColor(sf::Color::Magenta);
		tank.setPosition(pos);
		Viseur.setSize(sf::Vector2f(44, 50));
		texture = tex;
		textureViseur = texV;
		if (texture) {
			tank.setTexture(texture);
			tank.setFillColor(sf::Color::White);


		}
		if (textureViseur)
		{
			Viseur.setTexture(textureViseur);
			Viseur.setFillColor(sf::Color::White);
		}
	};
	void SetPosition()
	{
		Viseur.setPosition(position);
		tank.setPosition(position);
	}
};



