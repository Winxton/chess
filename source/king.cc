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
	int i;
	i = 1;
	while (!this->moved && xCord == 4 && originalY == yCord &&
			state->isInsideBoard(this->xCord+i,this->yCord))
	{
		if (state->hasPieceAt(this->xCord+i,this->yCord)){
			if (state->getPieceType(this->xCord+i,this->yCord) == Piece::ROOK &&
				!state->getPieceAt(this->xCord+i,this->yCord)->hasMoved() &&
				this->xCord+i == 7)
			{
				list.push_back(new Castle(this->xCord,this->yCord,this->xCord+2,this->yCord));
			}
			break;
		}
		i++;
	}
	i = 1;
	while (!this->moved && xCord == 4 && originalY == yCord &&
			state->isInsideBoard(this->xCord-i,this->yCord))
	{
		if (state->hasPieceAt(this->xCord-i,this->yCord)){
			if (state->getPieceType(this->xCord-i,this->yCord) == Piece::ROOK  &&
				!state->getPieceAt(this->xCord-i,this->yCord)->hasMoved() &&
				this->xCord-i == 0)
			{
				list.push_back(new Castle(this->xCord,this->yCord,this->xCord-2,this->yCord));
			}
			break;
		}
		i++;
	}
	return list;
}

King *King::clone() const {
	return new King(*this);
}

int King::getValue() const {
	return VALUE;
}