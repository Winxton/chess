#include "player.h"
#include <string>
using namespace std;

Player::Player(string color): color(color) {}

string Player::getColor() const {
	return color;
}

Player::~Player() {}

bool Player::cannotMove(const GameState &state) const {
	return false;
}
