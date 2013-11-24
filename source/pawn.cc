#include "pawn.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Pawn::Pawn(string color):Piece(color) {
	if (color == "white")
		repr = 'P';
	else
		repr = 'p';
	moved = false;
    cout << "pawn cons" << endl;
}

vector<ChessMove*> Pawn::getPossibleMoves(const GameState* state) const {
	int forwardOne = 1;
	int forwardTwo = 2;

	if (this->color == "black"){
		forwardOne = -1;
		forwardTwo = -2;
	}
	vector<ChessMove*> list;
	if (!state->hasPieceAt(this->xCord,this->yCord+forwardOne)){
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+forwardOne));
	}
	if (!state->hasPieceAt(this->xCord,this->yCord+forwardTwo) && 
		!state->hasPieceAt(this->xCord,this->yCord+forwardOne) &&
		!this->moved)
	{
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+forwardTwo));
	}
	if (state->isInsideBoard(this->xCord+1,this->yCord+forwardOne) &&
		state->hasPieceOfOppositeColor(this->color,this->xCord+1,this->yCord+forwardOne))
	{
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+1,this->yCord+forwardOne));
	}
	if (state->isInsideBoard(this->xCord-1,this->yCord+forwardOne) &&
		state->hasPieceOfOppositeColor(this->color,this->xCord+1,this->yCord+forwardOne))
	{
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+1,this->yCord+forwardOne));
	}
	return list;
}
