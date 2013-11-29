#include <iostream>
#include <string>
#include "gamestate.h"
#include "piece.h"
#include "undo.h"
using namespace std;

std::ostream& Undo::doPrint(std::ostream &out) const {
	return out << "Undo move" ;
}

void Undo::apply (GameState &state, bool updateGraphics, bool saveState) const {
	GameState *previousState = state.previousState;

	if (previousState == 0) {
		cerr << "No previous state." << endl;
	}
	else
	{
		// steal pieces from previous configuration
		// replace with previous state's
		for (int i =0; i<8; i++) 
		{
			for (int j=0; j<8; j++) 
			{
				state.chessboard[i][j].setPiece(
					previousState->chessboard[i][j].getAndUnsetPiece(),
					true);
			}
		}
		
		state.previousState = previousState->previousState;
		
		state.whiteTurn = previousState->whiteTurn;
		previousState->setPreviousState(0);
		delete previousState;
	}
	
}