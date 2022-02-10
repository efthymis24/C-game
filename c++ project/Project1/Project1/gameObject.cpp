#include "gameObject.h"
#include "game.h"

gameObject::gameObject(const Game & mygame)
	:game(mygame)       //to kanw auto epeidh einai reference to game
{ 
}

/*gameObject::gameObject(const Game & mygame)
	: game(mygame)       //to kanw auto epeidh einai reference to game
{
}*/
