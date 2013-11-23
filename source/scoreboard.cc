#include "scoreboard.h"
#include <iostream.h>
#include <string>

Scoreboard* Scoreboard::_instance=0;

Scoreboard* Scoreboard::Instance(){
	if (_instance == 0){
	_instance = new Scoreboard;
	_instance->white = 0;
	_instance->black = 0;
	}
	return _instance;
}

void Scoreboard::printScoreboard(){
	cout << "Final Score:" << endl;
	cout << "White: " << this->white << endl;
	cout << "Black: " << this->black << endl;
}

void Scoreboard::blackWins(){
	this->black++;
}

void Scoreboard::whiteWins(){
	this->white++;
}

void Scoreboard::tie(){
	this->white = white + 0.5;
	this->black = black + 0.5;
}
