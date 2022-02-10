#pragma once
/*
#include "util.h"

class Collidable
{
public:
	virtual Circle getCollisionHull() const = 0;
};



class gameObject
{
protected:
	const class Game & game; 
public:
	gameObject(const class Game & mygame); 
	//gameObject(const class Game & mygame);
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;

};
*/

#include "util.h"

class Collidable {
public:
	virtual Disk getCollisionHull() const = 0;
	virtual Disk getStartHull() const = 0;
};

class gameObject {
protected:
	const class Game& game;
public:
	gameObject(const class Game& mygame);
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
};