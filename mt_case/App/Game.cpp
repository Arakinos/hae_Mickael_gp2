#include "Game.hpp"
#include "Entity.hpp"
#include <SFML/Graphics.hpp>

Game * Game::me = nullptr;

Game::Game()
{

}
float Speed = 0.075f;
float MaxSpeed = 0.75f;
float LatSpeed = 0.35f;
float MaxLatSpeed = 0.75f;

void Game::Init()
{
	RectangleShape *sh = new RectangleShape(Vector2f(12, 24));
	sh->setFillColor(sf::Color::Magenta);
	sh->setOrigin(6, 24);

	Entity * ent = new Entity(sh);
	ent->SetPosPixel(100, 600);
	evec.push_back(ent);
	Player = ent;
	me = this;
	//memset
}
void Game::update(double dt)
{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && Player->State != ES_FALLING)
		{
			Player->dy -= LatSpeed;
			Player->isInAir = true;
			Player->State = ES_FALLING;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Player->dx += Speed;
			if (Player->dx > MaxSpeed) Player->dx = MaxSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Player->dx -= Speed;
			if (Player->dx < -MaxSpeed) Player->dx = -MaxSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			Player->SetPosPixel(100, 600);
			Player->dx = Player->dy = 0.0f;
			Player->isInAir = false;
			Player->State = ES_IDLE;
		}
		for (auto it = evec.begin(); it != evec.end();)
		{
			Entity *ent = *it;
			ent->update(dt);
			it++;
		}
}

void Game::draw(RenderWindow & win)
{
	for (auto it = evec.begin(); it != evec.end();)
		{
			Entity * ent = *it;
			ent->draw(win);
			it++;
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
	RectangleShape Line(Vector2f(1000, 1));
	Line.setPosition(100, 600);
	Line.setFillColor(sf::Color::Green);
	win.draw(Line);
}
