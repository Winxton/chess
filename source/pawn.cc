#include "pawn.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Pawn::Pawn(std::string color):Piece(color) {
	canAdvance=true;
    cout << "cons" << endl;
}

std::vector<ChessMove*> Pawn::getPossibleMoves(GameState* state) {
	int one = 1;
	int two = 2;
	if (this->color == "black"){
		one = -1;
		two = -2;
	}
	std::vector<ChessMove*> list;
	if (state->getPieceAt(this->xCord,this->yCord+one) == NULL){
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+one));
	}
	if (state->getPieceAt(this->xCord,this->yCord+two) == NULL && canAdvance){
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+two));
	}
	if (xCord != 7 && state->getPieceAt(this->xCord+1,this->yCord+one) != NULL &&
	state->getPieceAt(this->xCord+1,this->yCord+one)->color != this->color){
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+1,this->yCord+one));
	}
	if (xCord != 0 && state->getPieceAt(this->xCord-1,this->yCord+one) != NULL &&
	state->getPieceAt(this->xCord+1,this->yCord+one)->color != this->color){
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+1,this->yCord+one));
	}
	return list;
}

bool Pawn::ableToAdvance(){
	return canAdvance;
}
