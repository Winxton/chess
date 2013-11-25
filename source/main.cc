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
	cout << a << endl;
	a.apply(state);
	cout << endl;
    state->printBoard();

	vector<ChessMove*> v8 = state->getPieceAt(0,3)->getPossibleMoves(state);
	cout << state->getPieceType(0,3) << endl;
    for (unsigned int i =0; i<v8.size(); i++) {
    	cout << *v8[i] << endl;
    }

    cout << "---" << endl;
	
    vector<ChessMove*> v = state->getPieceAt(1,1)->getPossibleMoves(state);
	cout << state->getPieceType(1,1) << endl;
    for (unsigned int i =0; i<v.size(); i++) {
    	cout << *v[i] << endl;
    }

    cout << "---" << endl;

    vector<ChessMove*> v2 = state->getPieceAt(1,0)->getPossibleMoves(state);
    cout << state->getPieceType(1,0) << endl;
    for (unsigned int i =0; i<v2.size(); i++) {
    	cout << *v2[i] << endl;
    }
	
	cout << "---" << endl;

    vector<ChessMove*> v3 = state->getPieceAt(2,0)->getPossibleMoves(state);
    cout << state->getPieceType(2,0) << endl;
    for (unsigned int i =0; i<v3.size(); i++) {
    	cout << *v3[i] << endl;
    }
	
	cout << "---" << endl;

    vector<ChessMove*> v4 = state->getPieceAt(3,0)->getPossibleMoves(state);
    cout << state->getPieceType(3,0) << endl;
    for (unsigned int i =0; i<v4.size(); i++) {
    	cout << *v4[i] << endl;
    }
	
	cout << "---" << endl;

    vector<ChessMove*> v5 = state->getPieceAt(4,0)->getPossibleMoves(state);
    cout << state->getPieceType(4,0) << endl;
    for (unsigned int i =0; i<v5.size(); i++) {
    	cout << *v5[i] << endl;
    }
	
	cout << "---" << endl;

    vector<ChessMove*> v6 = state->getPieceAt(0,0)->getPossibleMoves(state);
    cout << state->getPieceType(0,0) << endl;
    for (unsigned int i =0; i<v6.size(); i++) {
    	cout << *v6[i] << endl;
    }
	
	cout << "---" << endl;
	
	vector<ChessMove*> v7 = state->getPieceAt(0,6)->getPossibleMoves(state);
    cout << state->getPieceType(0,6) << endl;
    for (unsigned int i =0; i<v7.size(); i++) {
    	cout << *v7[i] << endl;
    }

    //remember to delete the dynamically allocated elements
    for (unsigned int i =0; i<v.size(); i++) {
    	delete v[i];
    }
    for (unsigned int i =0; i<v2.size(); i++) {
    	delete v2[i];
    }
	for (unsigned int i =0; i<v3.size(); i++) {
    	delete v3[i];
    }
	for (unsigned int i =0; i<v4.size(); i++) {
    	delete v4[i];
    }
	for (unsigned int i =0; i<v5.size(); i++) {
    	delete v5[i];
    }
	for (unsigned int i =0; i<v6.size(); i++) {
    	delete v6[i];
    }
	for (unsigned int i =0; i<v7.size(); i++) {
    	delete v7[i];
    }
	for (unsigned int i =0; i<v8.size(); i++) {
    	delete v8[i];
    }


    delete state;
}
