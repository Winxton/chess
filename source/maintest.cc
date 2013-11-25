#include <iostream>
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <vector>
using namespace std;

int main() {
    GameState *state = new GameState();
	state->setPreviousState(state);
    state->printBoard();
	vector<ChessMove*> v2 = state->getPieceAt(0,1)->getPossibleMoves(state);
	cout << state->getPieceType(0,1) << endl;
    for (unsigned int i =0; i<v2.size(); i++) {
    	cout << *v2[i] << endl;
    }
	cout << "---" << endl;
	ChessMove a (0,1,0,3);
	a.apply(state);
	cout << endl;
    state->printBoard();
	ChessMove b (0,3,0,4);
	b.apply(state);
	state->printBoard();
	ChessMove c (1,6,1,4);
	c.apply(state);
	state->printBoard();
	vector<ChessMove*> v = state->getPieceAt(0,4)->getPossibleMoves(state);
	cout << state->getPieceType(0,4) << endl;
    for (unsigned int i =0; i<v.size(); i++) {
    	cout << *v[i] << endl;
    }
	cout << "---" << endl;
    //remember to delete the dynamically allocated elements
    for (unsigned int i =0; i<v.size(); i++) {
    	delete v[i];
    }
	for (unsigned int i =0; i<v.size(); i++) {
    	delete v2[i];
    }

    delete state;
}
