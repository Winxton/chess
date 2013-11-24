#include "pawn.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Pawn::Pawn(string color):Piece(color) {
	canAdvance = true;
    cout << "cons" << endl;
}

vector<ChessMove*> Pawn::getPossibleMoves(GameState* state) {
	int one = 1;
	int two = 2;
	if (this->color == "black"){
		one = -1;
		two = -2;
	}
	vector<ChessMove*> list;
	if (!state->getPieceAt(this->xCord,this->yCord+one)){
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+one));
	}
	if (!state->getPieceAt(this->xCord,this->yCord+two) && 
		!state->getPieceAt(this->xCord,this->yCord+one) && canAdvance){
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,this->yCord+two));
	}
	if (state->isInsideBoard(this->xCord+1,this->yCord+one) &&
	state->hasPieceOfOppositeColor(this->xCord+1,this->yCord+one)){
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+1,this->yCord+one));
	}
	if (state->isInsideBoard(this->xCord-1,this->yCord+one) &&
	state->hasPieceOfOppositeColor(this->xCord+1,this->yCord+one)){
		list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+1,this->yCord+one));
	}
	return list;
}

bool Pawn::ableToAdvance(){
	return canAdvance;
}
