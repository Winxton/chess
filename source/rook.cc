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
	std::vector<ChessMove*>::iterator it;
	//vertical
	for (int i = 1; i<9;i++){
		if (state->getPieceAt(this->xCord,i) == NULL){
			list.insert(new ChessMove(this->xCord,this->yCord,this->xCord,i));
		}
		else {
			if (state->getPieceAt(this->xCord,i)->color != this->color){
				list.insert(new ChessMove(this->xCord,this->yCord,this->xCord,i));
			}
		}
		it = list.end();
	}
	//horizontal
	for (int i = 1; i<9;i++){
		if (state->getPieceAt(i,this->yCord) == NULL){
			list.insert(new ChessMove(this->xCord,this->yCord,i,this->yCord));
		}
		else {
			if (state->getPieceAt(i,this->yCord)->color != this->color){
				list.insert(new ChessMove(this->xCord,this->yCord,i,this->yCord));
			}
		}
		it = list.end();
	}
	return list;
}

bool Rook::hasMoved(){
	return moved;
}
