#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class TankClass
{

	public:
		sf::Vector2f position;
		sf::RectangleShape tank;
		sf::RectangleShape Viseur;
		sf::RectangleShape BoxCollider;
		static sf::Texture *BaseText;
		sf::Texture *texture;
		sf::Texture *textureViseur;
		TankClass(sf::Vector2f pos, sf::Vector2f size, sf::Texture* tex  , sf::Texture*texV )
		{
			BoxCollider.setSize(size);
			tank.setSize(size);
			tank.setOrigin(Vector2f((size.x / 2), (size.y / 2)));
			position = pos;
			//tank.setFillColor(sf::Color::Magenta);
			tank.setPosition(pos);
			Viseur.setSize(sf::Vector2f(20, 50));
			Viseur.setOrigin((Viseur.getSize().x / 2), 0);
			texture = tex;
			textureViseur = texV;
			if (texture) {
				tank.setTexture(texture);
			//	tank.setFillColor(sf::Color::White);
			}
			tank.setTexture(texture);
			if (textureViseur)
			{
				Viseur.setTexture(textureViseur);
				Viseur.setFillColor(sf::Color::White);
			}
			Viseur.setTexture(textureViseur);
		};
		TankClass()
		{
			int i = 0;
		}
		void SetPosition()
		{
			Viseur.setPosition(position);
			tank.setPosition(position);
		}
};


