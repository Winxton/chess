#include "king.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

King::King(std::string color):Piece(color) {
	moved = false;
    cout << "cons" << endl;
}

std::vector<ChessMove*> King::getPossibleMoves(GameState* state) {
	std::vector<ChessMove*> list;
	for (int i = -1; i < 2; i++){
		for (int j = -1; j < 2; j++){
			if ((this->xCord+i > -1 && this->xCord+i < 8 && 
				this->yCord+j > -1 && this->yCord+j < 8 &&
				state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
				(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
				state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
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
