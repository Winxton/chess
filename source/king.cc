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
	std::vector<ChessMove*>::iterator it;
	for (int i = -1; i < 2; i++){
		for (int j = -1; j < 2; j++){
			if ((this->xCord+i > 0 && this->xCord+i < 9 && 
				this->yCord+j > 0 && this->yCord+j < 9 &&
				state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
				(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
				state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
			{
				list.insert(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
				it = list.end();
			}
		}
	}
	return list;
}

bool King::hasMoved(){
	return moved;
}
