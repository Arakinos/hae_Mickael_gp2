// app 8nov.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

// app 8nov.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Lib.h"
#include <direct.h>
#include "Entity.h"
#include "Bullet.h"
#include"Box2D/Box2D.h"



using namespace sf;
static std::vector<Entity> CharList;
static std::vector<Bullet> BulletList;
sf::Color hsv(int hue, float sat, float val)
{
	hue %= 360;
	while (hue < 0) hue += 360;

	if (sat < 0.f) sat = 0.f;
	if (sat > 1.f) sat = 1.f;

	if (val < 0.f) val = 0.f;
	if (val > 1.f) val = 1.f;

	int h = hue / 60;
	float f = float(hue) / 60 - h;
	float p = val * (1.f - sat);
	float q = val * (1.f - sat * f);
	float t = val * (1.f - sat * (1 - f));

	switch (h)
	{
	default:
	case 0:
	case 6: return sf::Color(val * 255, t * 255, p * 255);
	case 1: return sf::Color(q * 255, val * 255, p * 255);
	case 2: return sf::Color(p * 255, val * 255, t * 255);
	case 3: return sf::Color(p * 255, q * 255, val * 255);
	case 4: return sf::Color(t * 255, p * 255, val * 255);
	case 5: return sf::Color(val * 255, p * 255, q * 255);
	}
}
static Vector2f shPos(0, 0);
int fireball = 20;
int squareSpeed = 3;
sf::FloatRect boundingBox;
Vector2f Alpha;
sf::FloatRect otherBox;
bool collision = false;
bool collisionR = false;
bool collisionL = false;
bool collisionU = false;
bool collisionD = false;
Vector2f Beta;
//b2Vec2 gravity(0.0f, -10.0f);
void world(sf::RenderWindow &win)
{
	if (CharList[0].tank.getGlobalBounds().intersects(CharList[1].tank.getGlobalBounds()))
	{
		CharList[0].position.x = Beta.x;
		CharList[0].position.y = Beta.y;
		squareSpeed = 0;
		/*if (collision==false)
		{
			Alpha = CharList[0].position;
			printf("collision",collision);
			collision = true;
		}
		if (collision == true)
		{
			CharList[0].position = Alpha;
		}

		boundingBox = CharList[0].tank.getGlobalBounds();
		//boundingBox.left
		squareSpeed = 3;*/
	}
	else
	{
		/*if (collision == true)
		{
			collisionD = false;
			collisionR= false;
			collisionL= false;
			collisionU = false;
			collision = false;
		}*/
		Beta.x = CharList[0].position.x;
		Beta.y = CharList[0].position.y;
		squareSpeed = 3;
	}

}
void drawTank(sf::RenderWindow &win)
{
	for (Entity &Elem : CharList)
	{
		win.draw(Elem.tank);
		Elem.SetPosition();
	}
}
void drawBall(sf::RenderWindow &win)
{
	for (Bullet &Elem : BulletList)
	{
		win.draw(Elem.Shape);
		Elem.SetPosition();
	}
}
/*void Firegun(sf::RenderWindow&win)
{
	sf::RectangleShape ball(Vector2f(20, 20));
	ball.setFillColor(sf::Color::Green);
	ball.setPosition(ballpos);
	win.draw(ball);

}*/



int main()
{
	sf::RectangleShape Viseur;
	Viseur.setFillColor(sf::Color::Blue);
	Viseur.setOrigin(Vector2f(0, 5));
	Viseur.setSize(Vector2f(60, 10));
	Entity Player = Entity(Vector2f(20, 20), Vector2f(30, 30));
	Entity Ennemy = Entity(Vector2f(80, 80), Vector2f(30, 30));
	Bullet PongBall(Vector2f(400, 300), 20, sf::Color::Red);
	CharList.push_back(Player);
	CharList.push_back(Ennemy);
	BulletList.push_back(PongBall);

#pragma region Box2D

	/*b2World world2(gravity);
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	b2Body* groundBody = world2.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);*/

#pragma endregion

	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;
	static RectangleShape sh;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Box2D works!", sf::Style::Default, settings);
	window.setVerticalSyncEnabled(true);
	while (window.isOpen())//on passe tout le temps DEBUT DE LA FRAME 
	{
		Viseur.setPosition(CharList[0].position);
		sf::Event event;//recup les evenement clavier/pad
		while (window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
		world(window);
		sf::Vector2i globalPosition = sf::Mouse::getPosition();
		
		if (sf::Joystick::isConnected)
		{
			float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			if (x > 25 /*collisionL == false*/)
			{
				//Alpha = CharList[0].position;
				CharList[0].position.x += squareSpeed;
				/*if (collision == true)
				{
					collisionL = true;
					squareSpeed = 20;
				}
				collisionL = false;*/
			}

		}
		if (sf::Joystick::isConnected)
		{
			float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			if (x < -25 /*collisionR == false*/)
			{
				//Alpha = CharList[0].position;
				CharList[0].position.x -= squareSpeed;
				/*if (collision == true)
				{
					collisionR = true;
					squareSpeed = 20;
				}
				collisionR = false;*/

			}

		}
		if (sf::Joystick::isConnected)
		{
			float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
			if (y > 25 /*collisionU ==false*/)
			{
				//Alpha = CharList[0].position;
				CharList[0].position.y += squareSpeed;
				/*if (collision == true)
				{
					collisionU = true;
					squareSpeed = 20;
				}
				collisionU = false;*/

			}

		}
		if (sf::Joystick::isConnected)
		{
			float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
			if (y < -25)
			{
				Alpha = CharList[0].position;
				CharList[0].position.y -= squareSpeed;
			}

		}

		/*if (collision)
		{
			printf("Blocked");
			CharList[0].position = Alpha;
		}*/

		window.clear();//nettoie la frame
		drawTank(window);
		drawBall(window);
		window.draw(Viseur);

		window.display();//ca dessine et ca attend la vsync
	}
	return 0;
}