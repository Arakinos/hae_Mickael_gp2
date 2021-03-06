#include "Game.hpp"
#include "Entity.hpp"
#include <SFML/Graphics.hpp>

Game* Game::me = nullptr;

static bool wasPressed[sf::Keyboard::KeyCount];

void Game::init()
{
	RectangleShape *sh = new RectangleShape(Vector2f(12, 24));
	sh->setFillColor(sf::Color::White);
	sh->setOrigin(6, 24);
	
	Entity * ent = new Entity(sh);
	ent->setPosPixel(100, 600);
	
	player = ent;
	me = this;

	evec.push_back(ent);

	memset(wasPressed, 0, sizeof(wasPressed));

	makePlatforms();
}

void Game::makePlatforms() {
	int cScreenWidth = 1280 / Entity::CELL_WIDTH;
	int cScreenHeight = 720 / Entity::CELL_WIDTH;


	for (int a = 8; a < 15; a++)
	{
		for (int i = 8; i < 15; i++)
		{
			platforms.push_back(Vector2i(a, cScreenHeight - i));
		}
	}
	for (int a = 20; a < 35; a++)
	{
		for (int i = 15; i < 50; i++)
		{
			platforms.push_back(Vector2i(a, cScreenHeight - i));
		}
	}
	for (int a = 50; a < 55; a++)
	{
		for (int i = 8; i < 18; i++)
		{
			platforms.push_back(Vector2i(a, cScreenHeight - i));
		}
	}
	for (int a = 65; a < 80; a++)
	{
		for (int i = 25; i < 35; i++)
		{
			platforms.push_back(Vector2i(a, cScreenHeight - i));
		}
	}
}


void Game::update(double dt){

	for (auto it = evec.begin(); it != evec.end();) {
		Entity * ent = *it;
		ent->update(dt);
		it++;
	}

	wasPressed[sf::Keyboard::Up] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
}

void Game::draw(RenderWindow & win)
{
	for (auto it = evec.begin(); it != evec.end();) {
		Entity * ent = *it;
		ent->draw(win);
		it++;
	}

	auto CW = Entity::CELL_WIDTH;
	RectangleShape cell;
	cell.setFillColor(sf::Color(0x918EF0ff));
	cell.setSize(Vector2f(CW, CW));
	for (Vector2i & pl : platforms) {
		cell.setPosition(pl.x * CW, pl.y * CW);
		win.draw(cell);
	}

	for (auto it = pvec.begin(); it != pvec.end();) {
		Particle * p = *it;
		p->update();
		if (p->killed) {
			it = pvec.erase(it);
		}
		else {
			p->draw(win);
			it++;
		}
	}

	RectangleShape line(Vector2f(1000, 1));
	line.setFillColor(sf::Color::Green);
	line.setPosition(100, 600);
	//win.draw(line);
}

bool Game::willCollide(Entity * end, int cx, int cy)
{
	int cScreenWidth = 1280 / Entity::CELL_WIDTH;
	int cScreenHeight = 720/ Entity::CELL_WIDTH;

	if (cx < 0) return true;
	else if (cx >= cScreenWidth  ) return true;
	
	if (cy < 0) return true;
	else if (cy >= cScreenHeight ) return true;

	for (Vector2i & cell : platforms)
		if (cell.x == cx && cell.y == cy)
			return true;

	return false;
}

void Game::togglePlatform(int cx, int cy)
{
	for (auto it = platforms.begin(); it != platforms.end(); it++) {
		Vector2i & pl = *it;
		if (pl.x == cx && pl.y == cy) {
			platforms.erase(it);
			return;
		}
	}
	platforms.push_back(Vector2i(cx, cy));

			
}
