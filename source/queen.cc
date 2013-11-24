#include "queen.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

Queen::Queen(std::string color):Piece(color) {
    cout << "cons" << endl;
}

std::vector<ChessMove*> Queen::getPossibleMoves(GameState* state) {
	std::vector<ChessMove*> list;
	//vertical
	for (int i = 1; i<9;i++){
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
	for (int i = 1; i<9;i++){
		if (state->getPieceAt(i,this->yCord) == NULL){
			list.push_back(new ChessMove(this->xCord,this->yCord,i,this->yCord));
		}
		else {
			if (state->getPieceAt(i,this->yCord)->color != this->color){
				list.push_back(new ChessMove(this->xCord,this->yCord,i,this->yCord));
			}
		}
	}
	// diagonals
	int rightlimit = 8-xCord;
	int toplimit = 8-yCord;
	int leftlimit = xCord;
	int bottomlimit = yCord
	//bottom left
	for (int i = 1; i<std::min(bottomlimit,leftlimit);i++){
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
	for (int i = 1; i<std::min(bottomlimit,rightlimit);i++){
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
	for (int i = 1; i<std::min(toplimit,leftlimit);i++){
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
	for (int i = 1; i<std::min(toplimit,rightlimit);i++){
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
