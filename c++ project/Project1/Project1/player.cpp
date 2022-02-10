/*
#include "player.h"
#include "graphics.h"
#include "game.h"

Player::Player(const Game & mygame)
	: gameObject(mygame)
{
}

void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_A))
	{
		pos_x -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_D))
	{
		pos_x += speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_W))
	{
		pos_y -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		pos_y += speed * graphics::getDeltaTime() / 10.0f;
	}
	
	if (pos_x < 0) pos_x = 0;
	if (pos_x > CANVAS_WIDTH) pos_x = CANVAS_WIDTH;
	if (pos_y < 0) pos_y = 0;
	if (pos_y > CANVAS_HEIGHT) pos_y = CANVAS_HEIGHT;
}

void Player::draw()
{
	//float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime());   //anavosbinei to fwtaki

	graphics::Brush br;

	//emfanizw virus sth thesi toy paixth
	br.texture = std::string(ASSET_PATH) + "virus.png";
	br.outline_opacity = 0.0f;

	graphics::drawRect(pos_x, pos_y, player_size, player_size, br);
	br.outline_opacity = 0.0f;

	/* br.texture = "";
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.5f;
	br.fill_color[2] = 0.0f;
	br.fill_secondary_color[0] = 0.3f;
	br.fill_secondary_color[1] = 0.1f;         //FLOGA
	br.fill_secondary_color[2] = 0.0f;
	br.fill_opacity = 1.0f;
	br.fill_secondary_opacity = 0.0f;
	br.gradient = true; */
	
	//graphics::setScale(height, height);
	//graphics::drawDisk(pos_x - 50 * height, pos_y, 20, br);
	//graphics::resetPose();


	//graphics::drawDisk(pos_x, pos_y + 30, 60, br);  //sxediasmos flogas

/*
	if (game.getDebugMode())  //prepei na einai const kai ta dyo
	{
		//gia na blepw pliroforia thesis
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f;
		br.gradient = false;
		Circle hull = getCollisionHull();
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);
	}
}

void Player::init()
{
}

void Player::getBigger()
{
	player_size += 10;
}


Circle Player::getCollisionHull() const
{
	Circle c1;
	c1.cx = pos_x;
	c1.cy = pos_y;
	c1.radius = 25.0f; //pws fainetai isws to allajoyme
	return c1;
}
*/
#include "player.h"
#include "graphics.h"
#include "config.h"

Player::Player(const Game& mygame)
	: gameObject(mygame)
{
}

void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_A))
	{
		pos_x -= speed * graphics::getDeltaTime() / 5.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_D))
	{
		pos_x += speed * graphics::getDeltaTime() / 5.0f;

	}
	if (graphics::getKeyState(graphics::SCANCODE_W))
	{
		pos_y -= speed * graphics::getDeltaTime() / 5.0f;

	}
	if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		pos_y += speed * graphics::getDeltaTime() / 5.0f;

	}

	if (pos_x < 0) pos_x = 0;
	if (pos_x > CANVAS_WIDTH) pos_x = CANVAS_WIDTH;
	if (pos_y < 0) pos_y = 0;
	if (pos_y > CANVAS_HEIGHT) pos_y = CANVAS_HEIGHT;
}

void Player::draw()
{

	graphics::Brush br;

	br.texture = std::string(ASSET_PATH) + "virus.png";
	br.outline_opacity = 0.0f;

	graphics::drawRect(pos_x, pos_y, player_size, player_size, br);
	br.outline_opacity = 0.0f;

	//graphics::resetPose();

}


void Player::init()
{

}


void Player::getBigger()
{
	player_size += 2.0f;
}

void Player::reset()
{
	player_size = startSize;
	pos_x = CANVAS_WIDTH / 2;
	pos_y = CANVAS_HEIGHT / 2;
	getCollisionHull() = getStartHull();
}

Disk Player::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = 25.0f;
	return disk;
}

Disk Player::getStartHull() const
{
	Disk disk1;
	disk1.cx = pos_x;
	disk1.cy = pos_y;
	disk1.radius = 25.0f;
	return disk1;
}
