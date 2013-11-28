#include "knight.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Knight::Knight(string color):Piece(color) {
	if (color == "white")
		repr = 'N';
	else
		repr = 'n';
	moved = false;
}

vector<ChessMove*> Knight::getPossibleMoves(const GameState* state) const {
	vector<ChessMove*> list;
	int a[] = {-2,2};
	int b[] = {-1,1};
	// L-shaped traversal
	for(int i = 0; i<2;i++){
		for(int j = 0; j<2;j++){
			if (state->isInsideBoard(this->xCord+a[i],this->yCord+b[j]) &&
				(!state->hasPieceAt(this->xCord+a[i],this->yCord+b[j]) ||
					state->hasPieceOfOppositeColor(this->color,this->xCord+a[i],this->yCord+b[j])))
			{
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+a[i],this->yCord+b[j]));
			}
			if (state->isInsideBoard(this->xCord+b[i],this->yCord+a[j]) &&
				(!state->hasPieceAt(this->xCord+b[i],this->yCord+a[j]) ||
				state->hasPieceOfOppositeColor(this->color,this->xCord+b[i],this->yCord+a[j])))
			{
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+b[i],this->yCord+a[j]));
			}
		}
	}
	return list;
}

Knight *Knight::clone() const {
	return new Knight(*this);
}