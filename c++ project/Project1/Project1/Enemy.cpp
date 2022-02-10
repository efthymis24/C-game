/*
#include "Enemy.h"
#include "graphics.h"
#include "config.h"
#include <random> //genitria tuxaiwn arithmon
#include "util.h"



void Enemy::update()
{
	pos_x -= speed * graphics::getDeltaTime();           // kinisi
														//an balw rotation thelei update
	if (pos_x < -size)
	{
		active = false;
	}
}

void Enemy::draw()
{
	brush.texture = std::string(ASSET_PATH) + "enemy.png";
	brush.fill_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y, size, size, brush);
	graphics::resetPose();

	//Edw o alex ta exei allou prosoxi
	if (game.getDebugMode())
	{
		graphics::Brush br;
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f;
		br.gradient = false;
		Circle hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);
	}
}

void Enemy::init()
{
	speed = 0.3f;                       //balame statheri taytita isws to allaksoyme
	pos_x = CANVAS_WIDTH;
	pos_y = CANVAS_HEIGHT * rand0to1(); //epistrefei arithmo apo 0 mexri max rand akeraies  times
										// canvas height epi (0 ews 1)
	size = 40 + 100 * rand0to1();
										//an thelw bazw kai rotation edw 67' video 2o
	brush.outline_opacity = 0.0f;

}

Enemy::Enemy(const Game& mygame)
	: gameObject(mygame)
{
	init();
}


Enemy::~Enemy()
{
}

Circle Enemy::getCollisionHull() const
{
	Circle c1;
	c1.cx = pos_x;
	c1.cy = pos_y;
	c1.radius = size*0.45f; //pws fainetai isws to allajoyme
	
	return c1;
}
*/
#include "Enemy.h"
#include "graphics.h"
#include "config.h"
#include <random>
#include "util.h"


void Enemy::update()
{
	pos_x -= speed * graphics::getDeltaTime();
	
	if (pos_x < -size)
	{
		active = false;
	}

}	

void Enemy::draw()
{
	brush.texture = std::string(ASSET_PATH) + "enemy.png";
	graphics::drawRect(pos_x, pos_y, size, size, brush);
	brush.outline_opacity = 0.0f;

	graphics::resetPose();


}

void Enemy::init()
{
	speed = 0.3f + 0.8* rand0to1();
	pos_x = CANVAS_WIDTH;
	pos_y = CANVAS_HEIGHT * rand0to1();
	size = 30 + 70 * rand0to1();
	brush.outline_opacity = 0.0f;
}

Enemy::Enemy(const Game& mygame)
	: gameObject(mygame)
{
	init();
}

Enemy::~Enemy()
{
}

Disk Enemy::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = size * 0.45f;
	return disk;
}

Disk Enemy::getStartHull() const
{
	return Disk();
}

