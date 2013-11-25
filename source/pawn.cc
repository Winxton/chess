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
	// normal move
	if (state->isInsideBoard(this->xCord,this->yCord+forwardOne) &&
		!state->hasPieceAt(this->xCord,this->yCord+forwardOne)){
		if (this->yCord+forwardOne != 7)
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+forwardOne));
		else{
			// promotion
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+forwardOne));
			//list.push_back(new Promotion(this->xCord,this->yCord,this->xCord,this->yCord+forwardOne));
		}
	}
	// pawn advancement
	if (state->isInsideBoard(this->xCord,this->yCord+forwardOne) &&
		state->isInsideBoard(this->xCord,this->yCord+forwardTwo) &&
		!state->hasPieceAt(this->xCord,this->yCord+forwardTwo) && 
		!state->hasPieceAt(this->xCord,this->yCord+forwardOne) &&
		!this->moved)
	{
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+forwardTwo));
	}
	// pawn capture right
	if (state->isInsideBoard(this->xCord+1,this->yCord+forwardOne) &&
		state->hasPieceOfOppositeColor(this->color,this->xCord+1,this->yCord+forwardOne))
	{
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+1,this->yCord+forwardOne));
	}
	// pawn capture left
	if (state->isInsideBoard(this->xCord-1,this->yCord+forwardOne) &&
		state->hasPieceOfOppositeColor(this->color,this->xCord+1,this->yCord+forwardOne))
	{
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+1,this->yCord+forwardOne));
	}
	// Enpassant left
	if (state->isInsideBoard(this->xCord-1,this->yCord) &&
		state->hasPieceAt(this->xCord-1,this->yCord) &&
		state->hasPieceOfOppositeColor(this->color,this->xCord-1,this->yCord) &&
		state->getPieceType(this->xCord-1,this->yCord) == "pawn" &&
		state->getPreviousState()->isInsideBoard(this->xCord-1,this->yCord+forwardTwo) &&
		state->getPreviousState()->hasPieceAt(this->xCord-1,this->yCord+forwardTwo) &&
		state->getPreviousState()->hasPieceOfOppositeColor(this->color,this->xCord-1,this->yCord+forwardTwo) &&
		state->getPreviousState()->getPieceType(this->xCord-1,this->yCord+forwardTwo) == "pawn")
	{
		//list.push_back(new EnPassant(this->xCord,this->yCord,this->xCord-1,this->yCord+forwardOne));
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-1,this->yCord+forwardOne));
	}
	// Enpassant right
	if (state->isInsideBoard(this->xCord+1,this->yCord) &&
		state->hasPieceAt(this->xCord+1,this->yCord) &&
		state->hasPieceOfOppositeColor(this->color,this->xCord+1,this->yCord) &&
		state->getPieceType(this->xCord+1,this->yCord) == "pawn" &&
		state->getPreviousState()->isInsideBoard(this->xCord+1,this->yCord+forwardTwo) &&
		state->getPreviousState()->hasPieceAt(this->xCord+1,this->yCord+forwardTwo) &&
		state->getPreviousState()->hasPieceOfOppositeColor(this->color,this->xCord+1,this->yCord+forwardTwo) &&
		state->getPreviousState()->getPieceType(this->xCord+1,this->yCord+forwardTwo) == "pawn")
	{
		if (state->getPreviousState()->isInsideBoard(this->xCord,this->yCord))
			cout << "hi" << endl;
		//list.push_back(new EnPassant(this->xCord,this->yCord,this->xCord+1,this->yCord+forwardOne));
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+1,this->yCord+forwardOne));
	}
	return list;
}

Pawn *Pawn::clone() const {
	return new Pawn(*this);
}