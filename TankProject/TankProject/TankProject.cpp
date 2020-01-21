// TankProject.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <direct.h>
#include <iostream>
#include <vector>
#include "TankClass.h"
#include "Ball.h"
#include "Wall.h"

using namespace sf;
sf::ContextSettings settings;
sf::RectangleShape Button1;
sf::Text Button1Text;
sf::RectangleShape Button2;
sf::Text Button2Text;
sf::Font * font = new sf::Font();
sf::RenderWindow window(sf::VideoMode(1920, 1080), "GameTank", sf::Style::Default, settings);
TankClass Player1 = TankClass();
TankClass Player2;
Vector2f Beta;
Vector2f Beta2;
bool Shoot = false;
bool Shoot2 = false;
bool Menu = true;
bool InGame = false;
bool GameIsInit = false;
int squareSpeed = 3;
static std::vector<Ball> BallList;
static std::vector<Wall> WallList;

void world()
{

	for (int i = 0; i < WallList.size(); i++)
	{

			if (Player1.tank.getGlobalBounds().intersects(WallList[i].wallet.getGlobalBounds()))
			{
				Player1.position.x = Beta.x;
				Player1.position.y = Beta.y;
				squareSpeed = 0;
			}
			if (Player2.tank.getGlobalBounds().intersects(WallList[i].wallet.getGlobalBounds()))
			{
				Player2.position.x = Beta2.x;
				Player2.position.y = Beta2.y;
			}
	}
	if (Player1.tank.getGlobalBounds().intersects(Player2.tank.getGlobalBounds()))
	{
		Player1.position.x = Beta.x;
		Player1.position.y = Beta.y;
		Player2.position.x = Beta2.x;
		Player2.position.y = Beta2.y;
		squareSpeed = 0;
	}
	else
	{
		Beta.x = Player1.position.x;
		Beta.y = Player1.position.y;
		Beta2.x = Player2.position.x;
		Beta2.y = Player2.position.y;
		squareSpeed = 3;
	}
	for (int i = 0; i < BallList.size(); i++)
	{
		for (int y = 0; y < WallList.size(); y++)
		{
			if (WallList[y].wallet.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				if (WallList[y].Orientation == "Up")
				{
					BallList[i].r = -BallList[i].r;
				}
				if (BallList[i].BallLife == 1 && BallList[i].spawned == false)
				{
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0 || BallList[i].BallLife == -1 && BallList[i].spawned == false)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[y].wallet.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				if (WallList[y].Orientation == "Down")
				{
					BallList[i].r = -BallList[i].r;
				}
				if (BallList[i].BallLife == 1 && BallList[i].spawned == false)
				{
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0 || BallList[i].BallLife == -1 && BallList[i].spawned == false)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[y].wallet.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				if (WallList[y].Orientation == "Right")
				{
					BallList[i].u = -BallList[i].u;
				}
				if (BallList[i].BallLife == 1)
				{
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0 || BallList[i].BallLife == -1)
				{
					BallList[i].BallLife += 1;
				}
			}
			if (WallList[y].wallet.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
			{
				if (WallList[y].Orientation == "Left")
				{
					BallList[i].u = -BallList[i].u;
				}
				if (BallList[i].BallLife == 1 && BallList[i].spawned == false)
				{
					BallList.erase(BallList.begin() + i);
					break;
				}
				if (BallList[i].BallLife == 0 || BallList[i].BallLife == -1 && BallList[i].spawned == false)
				{
					BallList[i].BallLife += 1;
				}
			}
		}
		/*if (WallList[0].wallet.getGlobalBounds().intersects(BallList[i].ball.getGlobalBounds()))
		{
			BallList[i].ball.setPosition(Vector2f(BallList[i].ball.getPosition().x, BallList[i].ball.getPosition().y + 25));
			BallList[i].r = -BallList[i].r;
			if (BallList[i].BallLife == 1)
			{
				//BallList.erase(BallList.begin() + i);
				break;
			}
			if (BallList[i].BallLife == 0)
			{
				BallList[i].BallLife += 1;
			}
		}*/
	}
}



void button()
{

	Vector2i MousePos = sf::Mouse::getPosition();
	Vector2f Alpha = Button1.getPosition();
	Vector2f Beta = Button2.getPosition();
	Button1Text.setString("Play");
	Button1Text.setFillColor(sf::Color::White);
	Button1Text.setFont(*font);
	Button1Text.setPosition(Vector2f(Button1.getPosition().x-23, Button1.getPosition().y-20));
#pragma region BoutonPlay
	Button1.setSize(Vector2f(400, 100));
	Button1.setOrigin(Vector2f(200, 50));
	Button1.setPosition(Vector2f(960, 380));

	if (MousePos.x >= Alpha.x - 200 && MousePos.x <= Alpha.x + 200 && MousePos.y >= Alpha.y - 20 && MousePos.y <= Alpha.y + 85)
	{
		Button1.setFillColor(sf::Color::Magenta);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			Menu = false;
			GameIsInit = true;
		}
	}
	else
	{
		Button1.setFillColor(sf::Color::Blue);
	}
#pragma endregion
	Button2.setSize(Vector2f(400, 100));
	Button2.setOrigin(Vector2f(200, 50));
	Button2.setPosition(Vector2f(960, 700));
	Button2Text.setString("Quit");
	Button2Text.setFillColor(sf::Color::White);
	Button2Text.setFont(*font);
	Button2Text.setPosition(Vector2f(Button2.getPosition().x - 23, Button2.getPosition().y - 20));
	if (MousePos.x >= Beta.x - 200 && MousePos.x <= Beta.x + 200 && MousePos.y >= Beta.y - 20 && MousePos.y <= Beta.y + 85)
	{
		Button2.setFillColor(sf::Color::Magenta);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			exit(0);
		}
	}
	else
	{
		Button2.setFillColor(sf::Color::Blue);
	}
		window.draw(Button1);
		window.draw(Button1Text);
		window.draw(Button2);
		window.draw(Button2Text);
}
void InitGame()
{
	if (GameIsInit)
	{
		sf::Texture texture;
		sf::Texture textureViseur;
		sf::Texture textureR;
		sf::Texture textureViseurR;
		if(!texture.loadFromFile("res/tank sans canon bleu.png"))
			printf("pasTank");
		if (!textureViseur.loadFromFile("res/canon tank bleu.png"))
			printf("pasTank");
		if (!textureR.loadFromFile("res/tank sans canon rouge.png"))
			printf("pasTank");
		if (!textureViseurR.loadFromFile("res/canon tank rouge.png"))
			printf("pasTank");
		Player1 = TankClass(Vector2f(150, 800), Vector2f(65, 65), &texture, &textureViseur);
		//Player2 = TankClass(Vector2f(1200, 100), Vector2f(65, 65), &textureR, &textureViseurR);
		int height = window.getSize().y;
		int width = window.getSize().x;
		Wall Up = Wall(Vector2f(0, 0), Vector2f(window.getSize().x, 10), "Up");
		Wall Down = Wall(Vector2f(0, (window.getSize().y) - 3), Vector2f(window.getSize().x, 10), "Down");
		Wall Left = Wall(Vector2f(0, 0), Vector2f(10, height), "Left");
		Wall Right = Wall(Vector2f(window.getSize().x - 3, 0), Vector2f(10, height), "Right");
		WallList.push_back(Up);
		WallList.push_back(Down);
		WallList.push_back(Left);
		WallList.push_back(Right);
		GameIsInit = false;
		InGame = true;

	}
}
void DrawTank()
{
	window.draw(Player1.tank);
	window.draw(Player1.Viseur);
	window.draw(Player2.tank);
	window.draw(Player2.Viseur);
	Player1.SetPosition();
	Player2.SetPosition();
}
void DrawBullet()
{
	for (Ball &Elem : BallList)
	{
		window.draw(Elem.ball);
		Elem.ball.move(Elem.u / 8, Elem.r / 8);
	}
}
void DrawWall()
{
	for (Wall &Elem : WallList)
	{
		window.draw(Elem.wallet);
		Elem.SetPosition();
	}
}
void MoveTanks()
{
	if (sf::Joystick::isConnected(0))
	{
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		float angle = (atan2(x, y) * 180 / 3.141592654);
		if (x > 25)
		{
			Player1.tank.setRotation(-angle);
			Player1.position.x += squareSpeed;
		}
		if (x < -25)
		{
			Player1.tank.setRotation(-angle);
			Player1.position.x -= squareSpeed;
		}
		if (y > 25)
		{
			Player1.tank.setRotation(-angle);
			Player1.position.y += squareSpeed;
		}
		if (y < -25)
		{
			Player1.tank.setRotation(-angle);
			Player1.position.y -= squareSpeed;
		}
		if (sf::Joystick::isConnected(1))
		{
			float x = sf::Joystick::getAxisPosition(1, sf::Joystick::X);
			float y = sf::Joystick::getAxisPosition(1, sf::Joystick::Y);
			float angle = (atan2(x, y) * 180 / 3.141592654);
			if (x > 25)
			{
				Player2.tank.setRotation(-angle);
				Player2.position.x += squareSpeed;
			}
			if (x < -25)
			{
				Player2.tank.setRotation(-angle);
				Player2.position.x -= squareSpeed;
			}
			if (y > 25)
			{
				Player2.tank.setRotation(-angle);
				Player2.position.y += squareSpeed;
			}
			if (y < -25)
			{
				Player2.tank.setRotation(-angle);
				Player2.position.y -= squareSpeed;
			}
		}
	}
}
void Fire()
{
	if (sf::Joystick::isConnected(0))
	{
		float u = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
		float r = sf::Joystick::getAxisPosition(0, sf::Joystick::V);
		if (u > 25 || u < -25 || r>25 || r < -25)
		{
			float angle = (atan2(u, r) * 180) / 3.141592654;
			Player1.Viseur.setRotation(-angle);


			if (!Shoot && sf::Joystick::getAxisPosition(0, Joystick::Z) < -50)
			{
				Ball Balle = Ball(sf::Vector2f(Player1.Viseur.getPosition().x - 7, Player1.Viseur.getPosition().y), 15);
				Balle.spawned = true;
				Balle.u = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
				Balle.r = sf::Joystick::getAxisPosition(0, sf::Joystick::V);
				Balle.BallLife = -1;
				BallList.push_back(Balle);
			}
			if (sf::Joystick::getAxisPosition(0, Joystick::Z) < -50)
			{
				Shoot = true;
			}
			else
			{
				Shoot = false;
			}
		}
		if (sf::Joystick::isConnected(1))
		{
			float u = sf::Joystick::getAxisPosition(1, sf::Joystick::U);
			float r = sf::Joystick::getAxisPosition(1, sf::Joystick::V);
			if (u > 25 || u < -25 || r>25 || r < -25)
			{
				float angle = (atan2(u, r) * 180) / 3.141592654;
				Player2.Viseur.setRotation(-angle);


				if (!Shoot && sf::Joystick::getAxisPosition(1, Joystick::Z) < -50)
				{
					Ball Balle = Ball(sf::Vector2f(Player1.Viseur.getPosition().x - 15, Player2.Viseur.getPosition().y), 15);
					Balle.u = sf::Joystick::getAxisPosition(1, sf::Joystick::U);
					Balle.r = sf::Joystick::getAxisPosition(1, sf::Joystick::V);
					Balle.BallLife = 0;
					BallList.push_back(Balle);
				}
				if (sf::Joystick::getAxisPosition(1, Joystick::Z) < -50)
				{
					Shoot2 = true;
				}
				else
				{
					Shoot2 = false;
				}
			}
		}
	}
}
int main()
{

	if (font->loadFromFile("res/DejaVuSans.ttf") == false)
	{
		printf("no such font");
	}
	window.setVerticalSyncEnabled(true);
	while (window.isOpen())
	{
		sf::Event event;//recup les evenement clavier/pad
		while (window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyReleased:
				break;
			default:
				break;
			}
		}
		
		window.clear();
		if (Menu)
		{
			button();
		}
		if (GameIsInit)
		{
			InitGame();
		}
		if (InGame)
		{
			world();
			MoveTanks();
			Fire();
			DrawBullet();
			DrawTank();
			DrawWall();

		}
		window.display();//ca dessine et ca attend la vsync
	}
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
