#include "king.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

King::King(string color):Piece(color) {
	moved = false;
    cout << "cons" << endl;
}

vector<ChessMove*> King::getPossibleMoves(GameState* state) {
	vector<ChessMove*> list;
	for (int i = -1; i < 2; i++){
		for (int j = -1; j < 2; j++){
			if (state->isInsideBoard(this->xCord+i,this->yCord+j) &&
				(!state->hasPieceAt(this->xCord+i,this->yCord+j) ||
				state->hasPieceOfOppositeColor(this->xCord+i,this->yCord+j)))
			{
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			}
		}
	}
	return list;
}

bool King::hasMoved(){
	return moved;
}
