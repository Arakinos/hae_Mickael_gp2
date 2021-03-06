#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include <direct.h>
#include <functional>

#include "Lib.hpp"
#include "Particle.h"
#include "Action.hpp"
#include <Box2D/Box2D.h>

#include "Entity.hpp"
#include "Dijkstra.h"

using namespace sf;

class Game {
public:
	sf::Font * fnt;

	static Game * me;

public:
	std::vector< Particle * >	pvec;
	std::vector< Entity * >		evec;
	std::vector<Vector2i>		platforms;
	std::vector<Vector2f>		platformsF;

	Game() {

	}

	Entity *				player;

	void init();
	void makePlatforms();
	void makePlatforms2(Vector2f s1);
	void update(double dt);
	void draw(RenderWindow & win);
	bool willCollide(int cx, int cy);
	void togglePlatform(int cx, int cy);
	Dijkstra dijo;
};
