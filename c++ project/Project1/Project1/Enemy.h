#pragma once
/*
#include "gameObject.h"
#include "graphics.h"
#include "config.h"

class Enemy : public gameObject, public Collidable
{
	float pos_x;
	float pos_y;
	float speed;
	float size;
	float rotation;
	bool active = true; //an einai entos oriwn
	graphics::Brush brush;

public:

	void update() override;
	void draw() override;
	void init() override;
	bool isActive() { return active; }
	float getEnemySize() { return size; }
	Enemy(const class Game & mygame);
	~Enemy();
	Circle getCollisionHull() const override;
};
*/

#include "gameobject.h"
#include "config.h"
#include "graphics.h"

class Enemy : public gameObject, public Collidable
{
	float speed;
	float pos_x, pos_y;
	float size;
	float rotation;
	graphics::Brush brush;
	bool active = true;

public:
	void update() override;
	void draw() override;
	void init() override;
	bool isActive()
	{
		return active;
	}
	float getEenemySize() { return size; }
	Enemy(const class Game& mygame);
	~Enemy();
	Disk getCollisionHull() const override;
	Disk getStartHull() const override;
};