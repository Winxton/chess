#include "bishop.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Bishop::Bishop(string color):Piece(color) {
    cout << "cons" << endl;
}

vector<ChessMove*> Bishop::getPossibleMoves(GameState* state) {
	vector<ChessMove*> list;
	int i;
	// top right
	i = 1;
	while(state->isInsideBoard(this->xCord+i,this->yCord+i)) {
		if (state->hasPieceAt(this->xCord+i,this->yCord+i)){
			if (state->hasPieceOfOppositeColor(this->xCord+i,this->yCord+i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+i));
			break;
		}
		i++;
	}
	// top left
	i = 1;
	while(state->isInsideBoard(this->xCord-i,this->yCord+i)) {
		if (state->hasPieceAt(this->xCord-i,this->yCord+i)){
			if (state->hasPieceOfOppositeColor(this->xCord-i,this->yCord+i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord+i));
			break;
		}
		i++;
	}
	//bottom right
	i = 1;
	while(state->isInsideBoard(this->xCord+i,this->yCord-i)) {
		if (state->hasPieceAt(this->xCord+i,this->yCord-i)){
			if (state->hasPieceOfOppositeColor(this->xCord+i,this->yCord-i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord-i));
			break;
		}
		i++;
	}
	// bottom left
	i = 1;
	while(state->isInsideBoard(this->xCord-i,this->yCord-i)) {
		if (state->hasPieceAt(this->xCord-i,this->yCord-i)){
			if (state->hasPieceOfOppositeColor(this->xCord-i,this->yCord-i))
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-i,this->yCord-i));
			break;
		}
		i++;
	}
	return list;
}
