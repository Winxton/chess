#include "bishop.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

Bishop::Bishop(std::string color):Piece(color) {
    cout << "cons" << endl;
}

std::vector<ChessMove*> Bishop::getPossibleMoves(GameState* state) {
	std::vector<ChessMove*> list;
	// diagonals
	int rightlimit = 7-xCord;
	int toplimit = 7-yCord;
	int leftlimit = xCord;
	int bottomlimit = yCord
	//bottom left
	for (int i = 1; i<std::min(bottomlimit,leftlimit)+1;i++){
		if (state->getPieceAt(this->xCord-i,this->yCord-i) == NULL){
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord-i));
		}
		else {
			if (state->getPieceAt(this->xCord-i,this->yCord-i)->color != this->color){
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord-i));
			}
		}
	}
	// bottom right
	for (int i = 1; i<std::min(bottomlimit,rightlimit)+1;i++){
		if (state->getPieceAt(this->xCord+i,this->yCord-i) == NULL){
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord-i));
		}
		else {
			if (state->getPieceAt(this->xCord+i,this->yCord-i)->color != this->color){
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord-i));
			}
		}
	}
	// top left
	for (int i = 1; i<std::min(toplimit,leftlimit)+1;i++){
		if (state->getPieceAt(this->xCord-i,this->yCord+i) == NULL){
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord+i));
		}
		else {
			if (state->getPieceAt(this->xCord-i,this->yCord+i)->color != this->color){
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord+i));
			}
		}
	}
	// top right
	for (int i = 1; i<std::min(toplimit,rightlimit)+1;i++){
		if (state->getPieceAt(this->xCord+i,this->yCord+i) == NULL){
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+i));
		}
		else {
			if (state->getPieceAt(this->xCord+i,this->yCord+i)->color != this->color){
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+i));
			}
		}
	}
	return list;
}