#include "king.h"
#include "gamestate.h"
#include "chessmove.h"
#include "castle.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

King::King(string color):Piece(color) {
	if (color == "white")
		repr = 'K';
	else
		repr = 'k';
	moved = false;
}

vector<ChessMove*> King::getPossibleMoves(const GameState* state) const {
	int originalY = 0;
	if (this->color == "black"){
		originalY = 7;
	}


	vector<ChessMove*> list;
	// normal king moves
	for (int i = -1; i < 2; i++){
		for (int j = -1; j < 2; j++){
			if (state->isInsideBoard(this->xCord+i,this->yCord+j) &&
				(!state->hasPieceAt(this->xCord+i,this->yCord+j) ||
				state->hasPieceOfOppositeColor(this->color,this->xCord+i,this->yCord+j)))
			{
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			}
		}
	}
	// check if able to castle
	// right
	if (!this->moved && xCord == 4 && originalY == yCord &&
			state->isInsideBoard(this->xCord+3,this->yCord) &&
			state->hasPieceAt(this->xCord+3,this->yCord) &&
			state->getPieceType(this->xCord+3,this->yCord) == Piece::ROOK &&
			!state->getPieceAt(this->xCord+3,this->yCord)->hasMoved()) {
		list.push_back(new Castle(this->xCord,this->yCord,this->xCord+2,this->yCord));
	}
	// left
	if (!this->moved && xCord == 4 && originalY == yCord &&
			state->isInsideBoard(this->xCord-4,this->yCord) &&
			state->hasPieceAt(this->xCord-4,this->yCord) &&
			state->getPieceType(this->xCord-4,this->yCord) == Piece::ROOK &&
			!state->getPieceAt(this->xCord-4,this->yCord)->hasMoved()) {
		list.push_back(new Castle(this->xCord,this->yCord,this->xCord-2,this->yCord));
	}
	return list;
}

King *King::clone() const {
	return new King(*this);
}

int King::getValue() const {
	return 0;
}