#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
enum EntityState
{
	ES_IDLE,
	ES_FALLING,
	ES_MOVING,
};
class Entity {
public:
	

	Entity(sf::Shape * spr) {
		this->spr = spr;
	}

	EntityState State = ES_IDLE;
	int CX_W = 16;
	int CX_H = 16;

	int cx = 0;
	int cy = 0;

	float rx = 0.5f;
	float ry = 0.5f;

	float dx = 0.01f;
	float dy = 0.00f;

	float pixelX = 0.0;
	float pixelY = 0.0;

	//float gy = 0.03f;
	//bool isInAir = false;

	bool WillColide(Entity * end,int cx, int cy)
	{
		int ScreenWidht = 1280/16;
		int ScreenHeight = 720/16;
		if (cx < 1) { return true; }
		if (cx > ScreenWidht-1) { return true; }
		if (cy < 2) { return true; }
		if (cy > ScreenHeight-1) { return true; }
		int i = 0;
		return false;
	}
	sf::Shape * spr;
	void Setpos(float crx, float cry)
	{
		rx += crx;
		
		ry += cry;
	}
	void SetPosPixel(float pixelX, float pixelY)
	{
		cx = pixelX / 16;
		cy = pixelY / 16;
		rx = (pixelX - (int)(cx*CX_W)) / CX_W;
		ry = (pixelY - (int)(cy*CX_W)) / CX_W;

		SyncCoord();
	}
	void update(double dt) {

		rx += dx;
		ry += dy;
		if (dx > 0)
		{
			while (rx > 1)
			{
				if (!WillColide(this, cx + 2.5, cy) && !WillColide(this, cx + 15, cy))
				{
					rx--;
					cx++;
				}
				else
				{
					State = ES_IDLE;
					dx = 0;
					rx = 1;
					break;
				}
			}

		}
		else if (dx < 0)
		{
			while (rx < 0)
			{
				if (!WillColide(this, cx - 1, cy))
				{
					rx++;
					cx--;
				}
				else
				{
					State = ES_IDLE;
					dx = 0;
					rx = 0;
					break;
				}
			}
		}
		if (dy < 1)
		{
			while (ry < 0)
			{
				if (!WillColide(this, cx, cy - 1))
				{
					ry++;
					cy--;
				}
				else
				{
					//isInAir = false;
					State = ES_IDLE;
					dy = 0;
					ry = 0;
					break;
				}
			}
		}
		if (dy > 0)
		{
			while (ry > 1)
			{
				if (!WillColide(this, cx, cy+1))
				{
					ry--;
					cy++;
				}
				else
				{
					//isInAir = false;
					State = ES_IDLE;
					dy = 0;
					ry = 1;
					break;
				}
			}
		}
		dx *= 0.92;
		dy *= 0.92;
		if (abs(dx) < 0.05)
		{
			dx = 0;
		}
		/*if (isInAir) dy += gy;
		ry += dy;*/
		if (dy >= 1.0f)
		{
			dy = 1.0f;
		}
		SyncCoord();
	}
	void SyncCoord()
	{
		rx += dx;
		pixelX = cx * CX_W + rx * CX_W;
		pixelY = cy * CX_W + ry * CX_W;
		spr->setPosition(pixelX, pixelY);
	}
	void draw(sf::RenderWindow & win) {
		win.draw(*spr);
	}
	void changeState(EntityState nes)
	{
		EntityState oldState = State;

		switch (oldState)
		{
		default:
			break;
		}

		switch (nes)
		{
		default:
			break;
		}

		State = nes;
	}
};
