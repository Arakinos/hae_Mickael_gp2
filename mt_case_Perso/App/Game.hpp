#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include <direct.h>
#include <functional>
#include "Entity.hpp"
#include "Lib.hpp"
#include "Particle.h"
#include "Action.hpp"
#include <Box2D/Box2D.h>

using namespace sf;

class Game {
public:
	Entity * Player;
	sf::Font * fnt;
	static Game * me;

	Game();
	std::vector<Particle*> pvec;
	std::vector<Entity*> evec;

	void Init();
	void update(double dt);
	void draw(RenderWindow & win);
};
