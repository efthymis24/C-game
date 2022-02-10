#pragma once
/*
#include "gameObject.h"
#include "config.h"


class Player : public gameObject, public Collidable
{
	float speed = 5.0f;    //monades kanva ana deuterolepto
	float pos_x = CANVAS_WIDTH / 2;
	float pos_y = CANVAS_HEIGHT / 2;
	//float life = 1.0f; //gia na argopethenei tha doume an tha to baloume
	float player_size = 60;

public:

	Player(const class Game & mygame); 
	void update() override;
	void draw() override;
	void init() override;
	void getBigger();
	float getPosY() { return pos_y; }
	float getPosX() { return pos_x; }
	float getSize() {return player_size; }
	Circle getCollisionHull() const override;
	//float getBigger() { }
	//float getRemainingLife() const { return life; } //tha doume kai gia auto
	//float drainLife(float amount) { life = std::max<float>(0.0f, life - amount); }
};
*/

#include "gameobject.h"
#include "config.h"
#include "util.h"


class Player : public gameObject, public Collidable
{
	float speed = 2.0f;
	float pos_x = CANVAS_WIDTH / 2;
	float pos_y = CANVAS_HEIGHT / 2;
	float player_size = 43.0f;
	float startSize = 43.0f;

public:
	Player(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
	void getBigger();
	void reset();
	float getSize() { return player_size; }
	float getPosY() { return pos_y; }
	float getPosX() { return pos_x; }
	Disk getCollisionHull() const override;
	Disk getStartHull() const override;
};