#include "rook.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Rook::Rook(std::string color):Piece(color) {
    cout << "cons" << endl;
}

std::vector<ChessMove*> Rook::getPossibleMoves(GameState* state) {
	std::vector<ChessMove*> list;
	//vertical
	for (int i = 0; i<8;i++){
		if (state->getPieceAt(this->xCord,i) == NULL){
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord,i));
		}
		else {
			if (state->getPieceAt(this->xCord,i)->color != this->color){
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
			if (state->getPieceAt(i,this->yCord)->color != this->color){
				list.push_back(new ChessMove(this->xCord,this->yCord,i,this->yCord));
			}
		}
	}
	return list;
}

bool Rook::hasMoved(){
	return moved;
}
