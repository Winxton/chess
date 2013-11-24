#include "rook.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Rook::Rook(string color):Piece(color) {
    cout << "cons" << endl;
}

vector<ChessMove*> Rook::getPossibleMoves(GameState* state) const {
	vector<ChessMove*> list;
	//vertical
	for (int i = 0; i<8;i++){
		if (state->getPieceAt(this->xCord,i) == NULL){
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,i));
		}
		else {
			if (state->getPieceAt(this->xCord,i)->getColor() != this->color){
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,i));
			}
		}
	}
	//horizontal
	for (int i = 0; i<8;i++){
		if (state->getPieceAt(i,this->yCord) == NULL){
			list.push_back(new ChessMove(this->xCord,this->yCord,i,this->yCord));
		}
		else {
			if (state->getPieceAt(i,this->yCord)->getColor() != this->color){
				list.push_back(new ChessMove(this->xCord,this->yCord,i,this->yCord));
			}
		}
	}
	return list;
}

bool Rook::hasMoved() {
	return moved;
}
