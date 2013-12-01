#include "queen.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Queen::Queen(string color):Piece(color) {
	if (color == "white")
		repr = 'Q';
	else
		repr = 'q';
	moved = false;
}

vector<ChessMove*> Queen::getPossibleMoves(const GameState* state) const {
	vector<ChessMove*> list;
	int i;
	// up
	i = 1;
	while(state->isInsideBoard(this->xCord,this->yCord+i)) {
		if (state->hasPieceAt(this->xCord,this->yCord+i)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord,this->yCord+i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+i));
			break;
		}
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+i));
		i++;
	}
	// down
	i = 1;
	while(state->isInsideBoard(this->xCord,this->yCord-i)) {
		if (state->hasPieceAt(this->xCord,this->yCord-i)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord,this->yCord-i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord-i));
			break;
		}
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord-i));
		i++;
	}
	// right
	i = 1;
	while(state->isInsideBoard(this->xCord+i,this->yCord)) {
		if (state->hasPieceAt(this->xCord+i,this->yCord)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord+i,this->yCord))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord));
			break;
		}
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord));
		i++;
	}
	// left
	i = 1;
	while(state->isInsideBoard(this->xCord-i,this->yCord)) {
		if (state->hasPieceAt(this->xCord-i,this->yCord)){
			if (state->hasPieceOfOppositeColor(this->color,this->xCord-i,this->yCord))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord));
			break;
		}
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord));
		i++;
	}
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

Queen *Queen::clone() const {
	return new Queen(*this);
}

int Queen::getValue() const {
	return VALUE;
}