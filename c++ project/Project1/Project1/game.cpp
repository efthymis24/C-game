/*
#include "game.h"
#include "graphics.h"
#include "config.h"
//#include "player.h"


void Game::spawnEnemy()
{
	if (!enemy1_initialized && graphics::getGlobalTime() > 500)
	{
		if (!enemy1) 
		{
			enemy1 = new Enemy(*this);
		}
	}
	if (!enemy2_initialized && graphics::getGlobalTime() > 5000)
	{
		if (!enemy2)
		{
			enemy2 = new Enemy(*this);
		}
	}
	if (!enemy3_initialized && graphics::getGlobalTime() > 10000)
	{
		if (!enemy3)
		{
			enemy3 = new Enemy(*this);
		}
	}
	if (!enemy4_initialized && graphics::getGlobalTime() > 14000)
	{
		if (!enemy4)
		{
			enemy4 = new Enemy(*this);
		}
	}
}

void Game::checkEnemy()
{
	if (enemy1 && !enemy1->isActive())
	{
		delete enemy1;
		enemy1 = nullptr;
	}
	if (enemy2 && !enemy2->isActive())
	{
		delete enemy2;
		enemy2 = nullptr;
	}
	if (enemy3 && !enemy3->isActive())
	{
		delete enemy3;
		enemy3 = nullptr;
	}
	if (enemy4 && !enemy4->isActive())
	{
		delete enemy4;
		enemy4 = nullptr;
	}
}

bool Game::checkCollision()
{
	if (!player || !enemy1) 
	{
		return false;
	}

	//logika prepei na exw ola ta enemies mazemena gia na kanw thn apostash dx
	Circle cir1 = player->getCollisionHull();
	Circle cir2 = enemy1->getCollisionHull();
	//Circle cir3 = enemy2->getCollisionHull(); 
	//Circle cir4 = enemy3->getCollisionHull();
	//Circle cir5 = enemy4->getCollisionHull();

	float dx = cir1.cx - cir2.cx; //player - enemy
	float dy = cir1.cy - cir2.cy;

	if (sqrt(dx * dx + dy * dy) < cir1.radius + cir2.radius) //tsekarw sigkrousi
	{
		//prepei na megalwsv/mikrinw thn aktina sygkroysis toy paixth i edw i sthn update
		//player->drainLife(0.1f); //tha doume
		return true;
		cir1.radius += cir2.radius / 3;
		
	}
	else
	{
		return false;
	}
}



void Game::updateStartScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN)) //to enter
	{
		status = STATUS_PLAYING; //an patithei to enter paizoyme
	}
}

void Game::updatePlayingScreen()
{
	if (!player_initialized && graphics::getGlobalTime() > 0300)
	{
		player = new Player(*this);
		player_initialized = true;
	}

	if (player)
		player->update();

	checkEnemy();
	spawnEnemy();

	if (enemy1)
		enemy1->update();

	if (enemy2)
		enemy2->update();

	if (enemy3)
		enemy3->update();

	if (enemy4)
		enemy4->update();

	//afou ta exoume ola sth thesi tous
	if (checkCollision())
	{
		//tha doume edw ti paizei analoga an tha baloume ola ta enemies kapou
		if (player->getSize() > enemy1->getEnemySize())
		{
			player->getBigger();
			delete enemy1;
			enemy1 = nullptr; //xreiazetai giati i diagrafi monh tis de ftanei
			numOfCollisions++;
		}
		//edw epishw bazw efe krousis to opoio tha einai gameObject
		//bazei delete meteorite edw opote egw thelw th sigkrisi sta
		//megethi poy tha to kanw mesa sthn checkCollision i edw mesa
		else
		{
			status = STATUS_END;
		}
	}
}

void Game::updateWinScreen()
{
}

void Game::updateLoseScreen()
{
}

void Game::updateEndScreen()
{
	//na typwnei kati fasi kerdises
	//na deixnei kai posous exthrous efages kai se poso xrono
	//pataw koumpi kai paw stin arxikh
	//ama pataw kapoio koympi na kleinei i efarmogi
}

void Game::drawStartScreen()
{
	//edw tha balw oti thelw gia thn arxikh othoni
	//fasi press any button sto kentro ths othonhs
	graphics::Brush br;
	char info[50];
	sprintf_s(info, "press ENTER to start");
	graphics::drawText(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, 30, info, br);
}

void Game::drawPlayingScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "background.png";
	br.outline_opacity = 0.0f;

	float offset = sinf(graphics::getGlobalTime());

	//draw background
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	//draw player
	if (player)
		player->draw();

	//draw enemies
	if (enemy1)
		enemy1->draw();

	if (enemy2)
		enemy2->draw();

	if (enemy3)
		enemy3->draw();

	if (enemy4)
		enemy4->draw();

	//edw sto telos tha mpei ena skor h thesi kapou kati sto telos tou draw afou ginoun ola 15o lepto 2ou video

	//tha doume an tha xreiastoun auta
	//duo rect ena na uparxei kai ena na gemizei stadiaka
	float player_life = player ? player->getRemainingLife() : 0.0f; //an uparxei i oxi  o paixths

	br.outline_opacity = 1.0f;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.2f;
	br.fill_color[2] = 0.2f;
	br.texture = "";
	br.fill_secondary_color[0] = 1.0f * (1.0f - player_life) + player_life * 0.2f;
	br.fill_secondary_color[1] = 0.2f;
	br.fill_secondary_color[2] = 0.2 * (1.0f - player_life) + player_life * 1.0f;
	//thelw gradient orizontio..apo ti fush tou einai katheto
	br.gradient = true;
	br.gradient_dir_u = 1.0f;
	br.gradient_dir_v = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100 - ((1.0f - player_life) * 120 / 2), 30, player_life * 120, 20, br);

	br.outline_opacity = 1.0f;
	br.gradient = false;
	br.fill_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100, 30, 120, 20, br);
}

void Game::drawWinScreen()
{
}

void Game::drawLoseScreen()
{
}

void Game::update()
{
	if (status == STATUS_START)
	{
		updateStartScreen();
	}
	else if (status == STATUS_PLAYING)
	{
		updatePlayingScreen();
	}
	else
	{
		if (numOfCollisions == 15)
			updateWinScreen();
		else
			updateLoseScreen();   
	}

}

void Game::draw()
{
	if (status == STATUS_START)
	{
		drawStartScreen();
	}
	else if (status == STATUS_PLAYING)
	{
		drawPlayingScreen();
	}
	else
	{
		if (numOfCollisions == 15)
			drawWinScreen();
		else
			drawLoseScreen();
		//drawEndScreen();
	}
}

void Game::init()
{
	//edw tha balw kapoio font video 2o 18'
	//edw tha baloume kai thn mousikh toy game 34', na apothikeusw ena tragoudi
}

Game::Game()
{
}

Game::~Game()
{
	if (player)
	{
		delete player;
	}
}
*/
#include "Game.h"
#include "graphics.h"
#include "config.h"
#include "Enemy.h"
#include "util.h"


void Game::spawnEnemy()
{
	if (!enemy_initialized && graphics::getGlobalTime() > 15000)
	{
		if (!enemy)
		{
			enemy = new Enemy(*this);
		}
	}
}

void Game::checkEnemies()
{
	if (enemy && !enemy->isActive())
	{
		delete enemy;
		enemy = nullptr;
		enemiesLost++;
	}
}




bool Game::checkCollision()
{
	if (!player || !enemy) {
		return false;
	}

	Disk d1 = player->getCollisionHull();

	Disk d2 = enemy->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;
	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius) {

		player->getBigger();
		return true;
		d1.radius += 1.0f;
		//d1.radius += d2.radius / 2;
	}
	else return false;
}



/*void Game::getStart()
{
	player->returnToStartSize();
	player->startPosition();
	enemiesLost = 0;
	numOfCollisions = 0;

}*/

/*void Game::getStart()
{
	player->getSize() == 40.0f;
	player->getPosX() == CANVAS_WIDTH / 2;
	player->getPosY() == CANVAS_HEIGHT / 2;
}*/

void Game::updateStartScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		status = STATUS_PLAYING;
		
		
	}

	graphics::MouseState ms;
	graphics::getMouseState(ms);
	if (ms.button_left_pressed)
	{
		status == STATUS_PLAYING;

	}
}

void Game::updatePlayingScreen()
{

	if (!player_initialized && graphics::getGlobalTime() > 0300)
	{
		player = new Player(*this);
		player_initialized = true;
	}

	if (player)
		player->update();

	checkEnemies();
	spawnEnemy();

	if (enemy)
		enemy->update();

	if (checkCollision()) {

		if (player->getSize() > enemy->getEenemySize()) {

			graphics::playSound(std::string(ASSET_PATH) + "Bigger.wav", 0.5f, false);
			player->getBigger();
			delete enemy;
			enemy = nullptr;
			numOfCollisions++;
		}

		else {
			status = STATUS_LOSE;

		}
	}
	if (enemiesLost < 40) 
	{
		if (numOfCollisions >= 15)
		{
			status = STATUS_WIN;
		}
	}
	else
	{
		status = STATUS_LOSE;
	}
}

void Game::updateLoseScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		status = STATUS_START;
		player->reset();
		enemiesLost = 0;
		numOfCollisions = 0;
		//player->getCollisionHull() = player->getStartHull();
	}
}
void Game::updateWinScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{	
		status = STATUS_START;
		player->reset();
		enemiesLost = 0;
		numOfCollisions = 0;
		//player->getCollisionHull() = player->getStartHull();
	}
}
void Game::drawStartScreen()
{
	graphics::Brush br3;
	br3.texture = std::string(ASSET_PATH) + "start.png";
	br3.outline_opacity = 0.0f;

	//draw backround
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br3);

	graphics::Brush br;
	char info[50];
	sprintf_s(info, "Press ENTER to start");
	graphics::drawText(370, 200, 30, info, br);

	sprintf_s(info, "Rules are simple: ");
	graphics::drawText(250, 300, 30, info, br);

	sprintf_s(info, "1) if you eat 15 enemies you win ");
	graphics::drawText(250, 350, 30, info, br);

	sprintf_s(info, "2) if you crush with bigger enemy you lose ");
	graphics::drawText(250, 400, 30, info, br);

	sprintf_s(info, "3) if you let 40 enemies pass you lose.Good luck!");
	graphics::drawText(250, 450, 30, info, br);

}

void Game::drawPlayingScreen()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "background.png";
	br.outline_opacity = 0.0f;

	//draw backround
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	graphics::Brush br1;
	char info1[50];
	sprintf_s(info1, "Enemies passed %1.0f", enemiesLost);
	graphics::drawText(30, 30, 30, info1, br1);

	graphics::Brush br2;
	char info2[50];
	sprintf_s(info2, "Winned fights %1.0f", numOfCollisions);
	graphics::drawText(700, 30, 30, info2, br2);


	//draw player
	if (player)
		player->draw();

	//draw enemies

	if (enemy)
		enemy->draw();
}

void Game::drawLoseScreen()
{
	graphics::Brush br1;
	br1.texture = std::string(ASSET_PATH) + "defeat.png";
	br1.outline_opacity = 0.0f;

	//draw backround
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br1);

	graphics::Brush br;
	char info[50];
	sprintf_s(info, "GAME OVER");
	graphics::drawText(430, CANVAS_HEIGHT / 2, 30, info, br);
	sprintf_s(info, "PRESS ENTER TO GET VENGEANCE");
	graphics::drawText(300, 100, 30, info, br);
}

void Game::drawWinScreen()
{
	graphics::Brush br2;
	br2.texture = std::string(ASSET_PATH) + "victory.png";
	br2.outline_opacity = 0.0f;

	//draw backround
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br2);

	graphics::Brush br;
	char info[50];
	sprintf_s(info, "YOU WON");
	graphics::drawText(430, CANVAS_HEIGHT / 2, 30, info, br);
	sprintf_s(info, "PRESS ENTER TO PLAY AGAIN");
	graphics::drawText(300, 100, 30, info, br);
	//ISWS KAI SYNOLIKO XRONO
}

void Game::update()
{

	if (status == STATUS_START) {
		updateStartScreen();
	}
	if (status == STATUS_PLAYING)
	{
		updatePlayingScreen();
	}
	if (status == STATUS_WIN)
	{
		updateWinScreen();
	}
	if (status == STATUS_LOSE)
	{
		updateLoseScreen();
	}
		//if (numOfCollisions == 15) {
			//status = STATUS_END;
			//updateWinScreen();
		//}
		//else {
		//	updateLoseScreen();
		//}
	//}
	/*else if(status == STATUS_END)
	{
		updateLoseScreen();

	}
	else {
		updateWinScreen();
	}*/

}

void Game::draw()
{
	if (status == STATUS_START) {
		drawStartScreen();
	}
	if (status == STATUS_PLAYING)
	{
		drawPlayingScreen();
	}
	if (status == STATUS_WIN)
	{
		drawWinScreen();
		//status = STATUS_START;
		//graphics::resetPose();
	}
	if (status == STATUS_LOSE)
	{
		drawLoseScreen();
		//status = STATUS_START;
		//graphics::resetPose();
	}
		//if (numOfCollisions == 15) {
		//	drawWinScreen();
		//}
		//else {
		//	drawLoseScreen();
		//}
	
	/*else if(status == STATUS_END)
	{
		drawLoseScreen();

	}
	else {
		drawWinScreen();
	}*/
}

void Game::init()
{
	graphics::playMusic(std::string(ASSET_PATH) + "Fatboy Slim - Right Here, Right Now.mp3", 0.5f, true, 5000);

	graphics::setFont(std::string(ASSET_PATH) + "Bombaya.otf");
}

float Game::window2canvasX(float x)
{
	return x * CANVAS_WIDTH / (float)window_width;
}

float Game::window2canvasY(float y)
{
	return y * CANVAS_HEIGHT / (float)window_height;
}

Game::Game()
{

}

Game::~Game()
{
	if (player)
	{
		delete player;
	}
}
