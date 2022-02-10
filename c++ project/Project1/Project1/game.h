#pragma once
/*
#include "player.h"
#include "Enemy.h"

class Game
{
	typedef enum {STATUS_START, STATUS_PLAYING, STATUS_END} status_t; //tupos poy exw metabliti o opoios typos pairnei treis akeraies katastaseis
	
	Player * player = nullptr;
	bool player_initialized = false;
	//bool debug_mode = false;  //tha doume an tha xreiastei auto

	Enemy * enemy1 = nullptr;
	bool enemy1_initialized = false; 

	Enemy * enemy2 = nullptr;
	bool enemy2_initialized = false;

	Enemy * enemy3 = nullptr;
	bool enemy3_initialized = false;

	Enemy * enemy4 = nullptr;
	bool enemy4_initialized = false;

	void spawnEnemy();
	void checkEnemy();
	bool checkCollision();
	status_t status = STATUS_START; //arxiko status

	float numOfCollisions = 0;

	void updateStartScreen();
	void updatePlayingScreen();
	//void updateEndScreen();
	void updateWinScreen();
	void updateLoseScreen();
	void drawStartScreen();
	void drawPlayingScreen();
	void drawWinScreen();
	void drawLoseScreen();
	//void drawEndScreen();

public:
	//void setDebugMode(bool d) { debug_mode = d; }
	//bool getDebugMode() const { return debug_mode; }
	void update();
	void draw();
	void init(); //na tin kalw gia na jekiniso dedomena sthn klasi ektos ap ton constructor
	Game(); //default constructor
	~Game(); //destructor
};
*/

#include "player.h"
#include "Enemy.h"
#include "graphics.h"
#include <vector>

class Game {
	typedef enum { STATUS_START, STATUS_PLAYING, STATUS_LOSE, STATUS_WIN } status_t;

	Player* player = nullptr;
	bool player_initialized = false;

	Enemy* enemy = nullptr;
	bool enemy_initialized = false;



	//void makeEnemies();
	void spawnEnemy();
	void checkEnemies();
	bool checkCollision();

	status_t status = STATUS_START;

	unsigned int window_width = WINDOW_WIDTH,
		window_height = WINDOW_HEIGHT;

	float enemiesLost = 0;
	float numOfCollisions = 0;

	//void getStart();

	void updateStartScreen();
	void updatePlayingScreen();
	void updateLoseScreen();
	void updateWinScreen();
	void drawStartScreen();
	void drawPlayingScreen();
	void drawLoseScreen();
	void drawWinScreen();

public:
	void update();
	void draw();
	void init();
	unsigned int getWindowWdth() { return window_width; }
	unsigned int getWindowHeight() { return window_height; }
	float window2canvasX(float x);
	float window2canvasY(float y);
	void setWindowDimensions(unsigned int w, unsigned int h) { window_width = w; window_height = h; }
	Game(); //constructor
	~Game(); //destuctor
};