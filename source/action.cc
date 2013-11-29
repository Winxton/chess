#include "action.h"
#include "gamestate.h"
#include <iostream>
using namespace std;

Action::~Action() {}

void Action::saveCurrentStateAsPrevious(GameState &state) const {
	// copy a new state
	GameState *temp = new GameState(state);
	// "previous state pointer" to the current state
	// this preserves all history since copying the state 
	// copies the pointer to its previous state
	state.setPreviousState(temp);
}

std::ostream& operator<<(std::ostream &out, const Action &s) {
	return s.doPrint(out);
}
