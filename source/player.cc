#include "player.h"
#include <string>
using namespace std;

Player::Player(string color): color(color) {}

string Player::getColor() const {
	return color;
}

Player::~Player() {}
