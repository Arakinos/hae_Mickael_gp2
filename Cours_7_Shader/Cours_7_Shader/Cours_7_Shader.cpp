// Cours_7_Shader.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Lib.h"

using namespace sf;
static sf::Shader * SimpleShader = nullptr;
static sf::Shader * RedShader = nullptr;
void drawCurve(sf::RenderWindow &win, float now)
{
	sf::VertexArray va(sf::LinesStrip);

	sf::Color red = sf::Color::Red;
	sf::Color blue = sf::Color::Blue;
	int nb = 100;
	float stride = 1280.0 / nb;
	int ofsx = 0;
	for (int i = 0; i < nb+1; i++)
	{
		double ratio = 1.0 * i / nb;
		double Alpha = ofsx + stride * i;
		double Beta = 400;

		
		Alpha = 400 + (cos(ratio * 2 * 3.141569) * (now * 20) * sin(now*ratio));
		Beta = 300 + (sin(ratio * 2 * 3.141569) * (now * 20)/+(ratio*now));
		Alpha = 400 + cos(ratio * 2 * 3.141569) * (ratio * 20);
		Beta = 300 + sin(ratio * 2 * 3.141569) * (ratio * 20);
		sf::Vertex vertex(Vector2f(Alpha, Beta) , i % 2 == 0 ? blue : red);
		va.append(vertex);
		
	}
	win.draw(va);
}
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
sf::Vector2i F1(100,100);
sf::Vector2i F2(150, 200);
sf::Vector2i F3(200, 250);
sf::Vector2i F4(250, 300);
sf::Vector2i F5(300, 350);
void drawCurve2(sf::RenderWindow &win, float now=0)
{
	
	sf::VertexArray va(sf::LinesStrip);
	sf::CircleShape Pastille(25.f);
	Pastille.setFillColor(sf::Color::Yellow);
	sf::Color red = sf::Color::Red;
	sf::Color blue = sf::Color::Blue;
	int nb = 320;
	float stride = 1280.0 / nb;

	std::vector<Vector2f> Points;

	for (int j = 0; j < 8; j++)
	{
		/*Vector2f v(j * 50, j * 50);
		if (j == 0)v.x += 100;
		if (j == 3)v.x += 200;
		Points.push_back(v);*/
		Vector2f v(j * 50, j * 50);
		if (j == 1)v.x = F1.x;
		if (j == 1)v.y = F1.y;
		if (j == 3)v.x = F2.x;
		if (j == 3)v.y = F2.y;
		if (j == 5)v.x = F3.x;
		if (j == 5)v.y = F3.y;
		if (j == 6)v.x = F4.x;
		if (j == 6)v.y = F4.y;
		if (j == 7)v.x = F5.x;
		if (j == 7)v.y = F5.y;
		Points.push_back(v);
	}
	for (int i = 0; i < nb; i++)
	{
		
		double ratio = 1.0*i / nb;
		double x = 0.0;
		double y = 0.0;
		sf::Color c = hsv(ratio * 360, 0.8, 0.8);

		Vector2f pos = Lib::plot2(ratio, Points);
		x = pos.x;
		y = pos.y;

		sf::Vertex vertex(Vector2f(x, y), c);
		va.append(vertex);
	}

	static float doo = 0.0;
	static bool Reverse = true;
	Vector2f pos = Lib::plot2(Reverse? doo:(1-doo), Points);
	Pastille.setPosition(pos.x, pos.y);
	

	doo += 0.01;
	if (doo > 1)
	{
		doo = 0;
		Reverse = !Reverse;
	}
	win.draw(Pastille);
	win.draw(va);
	
}
void MovingSquare(sf::RenderWindow &win, sf::Shape &shp, float now)
{
	
	float moveSpeed = 5.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		moveSpeed = 10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && shp.getPosition().x < 1870)
	{
		shp.setPosition(Vector2f((shp.getPosition().x + moveSpeed), shp.getPosition().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && shp.getPosition().x > 0)
	{
		shp.setPosition(Vector2f((shp.getPosition().x - moveSpeed), shp.getPosition().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		shp.setPosition(Vector2f((shp.getPosition().x), shp.getPosition().y + moveSpeed));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		shp.setPosition(Vector2f((shp.getPosition().x), shp.getPosition().y - moveSpeed));
	}
}   
int main()
{
	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Courbe!",sf::Style::Default); //définit la taille de la fenetre
	//sf::RenderWindow window2(sf::VideoMode(800, 600), "FPS works!"); //définit la taille de la fenetre
	sf::CircleShape shape(100.f); // défit la largeur du cercle
	sf::RectangleShape shaping; // défit la largeur du cercle
	sf::Texture Text;
	Text.loadFromFile("res/WhitePixel.png");
	shaping.setTexture(&Text);
	shaping.setSize(Vector2f(50.0f, 50.0f));
	shaping.setPosition(960, 780);
	shaping.setFillColor(sf::Color::White);
	sf::Text Alpha;
	shape.setFillColor(sf::Color(0xD07FFFff)); // définit la couleur
	shape.setOutlineThickness(4);
	shape.setOutlineColor(sf::Color(0x7F73FFff));
	sf::Clock Clock;
	sf::Time appstart = Clock.getElapsedTime();
	sf::Time frameend = Clock.getElapsedTime();
	sf::Time BeforeDisplay = Clock.getElapsedTime();
	sf::Time frameStart = Clock.getElapsedTime();
	sf::Time PrevframeStart = Clock.getElapsedTime();
	window.setVerticalSyncEnabled(true);
	sf::Font * font = new sf::Font();
	float fps;
	float now = Clock.getElapsedTime().asSeconds();	//float alp = sf::Clock.getElapsedTime();
	if (font->loadFromFile("res/DejaVuSans.ttf") == false)
	{
		printf("no such font");
	}
	if (!sf::Shader::isAvailable)
	{
		printf("No Shader\n");
	}

	SimpleShader = new Shader();
	if (!SimpleShader->loadFromFile("res/simple.vert", "res/simple.frag"))
	{
		printf("Unable to load Shader\n");
	}
	Alpha.setFont(*font);
	while (window.isOpen()) // tant que le fenetre est ouverte
	{
		MovingSquare(window,shaping, Clock.getElapsedTime().asSeconds());
		frameStart = Clock.getElapsedTime();
		sf::Event event; // ?
		while (window.pollEvent(event))
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
			{
				F1 = sf::Mouse::getPosition(window);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
			{
				F2 = sf::Mouse::getPosition(window);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
			{
				F3 = sf::Mouse::getPosition(window);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
			{
				F4 = sf::Mouse::getPosition(window);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
			{
				F5 = sf::Mouse::getPosition(window);
			}
			if (event.type == sf::Event::Closed) // si clique sur fermer fenetre fermer fenetre
				window.close();
		}
		now = Clock.getElapsedTime().asSeconds();	//float alp = sf::Clock.getElapsedTime();
		SimpleShader->setUniform("time", now);
		
		fps = (1.0f / (frameend - PrevframeStart).asSeconds());
		Alpha.setString(std::string("FPS:") + std::to_string(fps));
		window.clear(sf::Color(0x0111FFff)); // vide tout le contenue de la fenetre
		//window.draw(shape); // dessine la forme
		//drawCurve(window, Clock.getElapsedTime().asSeconds());
		//drawCurve2(window, Clock.getElapsedTime().asSeconds());
		window.draw(Alpha); // dessine la forme
		window.draw(shaping,SimpleShader); 
		BeforeDisplay = Clock.getElapsedTime();
		window.display(); // affiche sur la fenetre
		frameend = Clock.getElapsedTime();
		PrevframeStart = frameStart;
	}

	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
