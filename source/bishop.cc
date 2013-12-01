#include "bishop.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Bishop::Bishop(string color):Piece(color) {
	if (color == "white")
		repr = 'B';
	else
		repr = 'b';
	moved = false;
}

vector<ChessMove*> Bishop::getPossibleMoves(const GameState* state) const {
	vector<ChessMove*> list;
	int i;
		// top right
	i = 1;
	while(state->isInsideBoard(this->xCord+i,this->yCord+i)) {
		if (state->hasPieceAt(this->xCord+i,this->yCord+i)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord+i,this->yCord+i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+i));
			break;
		}
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+i));
		i++;
	}
	// top left
	i = 1;
	while(state->isInsideBoard(this->xCord-i,this->yCord+i)) {
		if (state->hasPieceAt(this->xCord-i,this->yCord+i)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord-i,this->yCord+i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord+i));
			break;
		}
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord+i));
		i++;
	}
	//bottom right
	i = 1;
	while(state->isInsideBoard(this->xCord+i,this->yCord-i)) {
		if (state->hasPieceAt(this->xCord+i,this->yCord-i)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord+i,this->yCord-i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord-i));
			break;
		}
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord-i));
		i++;
	}
	// bottom left
	i = 1;
	while(state->isInsideBoard(this->xCord-i,this->yCord-i)) {
		if (state->hasPieceAt(this->xCord-i,this->yCord-i)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord-i,this->yCord-i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord-i));
			break;
		}
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord-i));
		i++;
	}
	return list;
}

Bishop *Bishop::clone() const {
	return new Bishop(*this);
}

int Bishop::getValue() const {
	return VALUE;
}