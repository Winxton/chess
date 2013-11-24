#include <iostream>
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <vector>
using namespace std;

int main() {
    GameState *state = new GameState();
    state->printBoard();

	ChessMove a (0,1,0,3);
	a.apply(state);

	cout << endl;
    state->printBoard();

    vector<ChessMove*> v = state->getPieceAt(1,1)->getPossibleMoves(state);
    for (unsigned int i =0; i<v.size(); i++) {
    	cout << *v[i] << endl;
    }

    cout << "---" << endl;

    vector<ChessMove*> v2 = state->getPieceAt(1,0)->getPossibleMoves(state);
    cout << state->getPieceType(1,0) << endl;
    for (unsigned int i =0; i<v2.size(); i++) {
    	cout << *v2[i] << endl;
    }

    //remember to delete the dynamically allocated elements
    for (unsigned int i =0; i<v.size(); i++) {
    	delete v[i];
    }
    for (unsigned int i =0; i<v2.size(); i++) {
    	delete v2[i];
    }


    delete state;
}
