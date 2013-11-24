#include <iostream>
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
using namespace std;

int main() {
    GameState *state = new GameState();
	state->initializeDefault();
    state->printBoard();
	ChessMove a (0,1,0,3);
	a.apply(state);
    state->printBoard();
    //const Piece *p = state.getPieceAt(0,0);
    //delete p;
}
