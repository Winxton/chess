#include <string>
#include "resign.h"
#include "gamestate.h"
using namespace std;

Resign::Resign(string color): color(color) {}

ostream& Resign::doPrint(std::ostream& out) const {
	return out << color << " Resigns." << endl;
}

void Resign::apply(GameState &state, bool updateGraphics, bool saveState) const {
	state.gameEnded = true;
}