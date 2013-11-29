#include "playerfactory.h"
#include "player.h"
#include "humanplayer.h"
#include "computerplayer.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

PlayerFactory *PlayerFactory::instance = 0;

void PlayerFactory::cleanup() {
	delete instance;
}

PlayerFactory *PlayerFactory::getInstance() {
	if (instance == 0) {
		instance = new PlayerFactory;
		atexit(cleanup);
	}
	return instance;
}

Player *PlayerFactory::createPlayer(string type, int level, string color) {
	if (type == "human") {
		return new HumanPlayer(color);
	} else { //computer player
		return new ComputerPlayer(color, level);
	}
}
