#include "pawn.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Pawn::Pawn(std::string color):Piece(color) {
	if (yCord == 2)
		canAdvance=true;
    cout << "cons" << endl;
}

std::vector<ChessMove*> Pawn::getPossibleMoves(GameState* state) {
	std::vector<ChessMove*> list;
	std::vector<ChessMove*>::iterator it;
	if (state->getPieceAt(this->xCord,this->yCord+1) == NULL){
		list.insert(it, new ChessMove(this->xCord,this->yCord+1);
		it = list.end();
	}
	if (state->getPieceAt(this->xCord,this->yCord+2) == NULL && canAdvance){
		list.insert(it, new ChessMove(this->xCord,this->yCord+2);
		it = list.end();
	}
	if (xCord != 8 && state->getPieceAt(this->xCord+1,this->yCord+1) != NULL &&
	state->getPieceAt(this->xCord+1,this->yCord+1)->color != this->color){
		list.insert(it, new ChessMove(this->xCord+1,this->yCord+1);
		it = list.end();
	}
	if (xCord != 1 && state->getPieceAt(this->xCord-1,this->yCord+1) != NULL &&
	state->getPieceAt(this->xCord+1,this->yCord+1)->color != this->color){
		list.insert(it, new ChessMove(this->xCord+1,this->yCord++1);
		it = list.end();
	}
	return list;
}

bool Pawn::ableToAdvance(){
	return canAdvance;
}
