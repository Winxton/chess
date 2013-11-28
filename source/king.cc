#include "king.h"
#include "gamestate.h"
#include "chessmove.h"
#include "castle.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

King::King(string color):Piece(color) {
	if (color == "white")
		repr = 'K';
	else
		repr = 'k';
	moved = false;
    cout << "king cons" << endl;
}

vector<ChessMove*> King::getPossibleMoves(const GameState* state) const {
	vector<ChessMove*> list;
	// normal king moves
	for (int i = -1; i < 2; i++){
		for (int j = -1; j < 2; j++){
			if (state->isInsideBoard(this->xCord+i,this->yCord+j) &&
				(!state->hasPieceAt(this->xCord+i,this->yCord+j) ||
				state->hasPieceOfOppositeColor(this->color,this->xCord+i,this->yCord+j)))
			{
				list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			}
		}
	}
	// check if able to castle
	int i;
	i = 1;
	while (!this->moved &&
			state->isInsideBoard(this->xCord+i,this->yCord))
	{
		if (state->hasPieceAt(this->xCord+i,this->yCord)){
			if (state->getPieceType(this->xCord+i,this->yCord) == Piece::ROOK &&
				!state->getPieceAt(this->xCord+i,this->yCord)->hasMoved())
			{
				list.push_back(new Castle(this->xCord,this->yCord,this->xCord+2,this->yCord));
				//cout << new ChessMove(this->xCord,this->yCord,this->xCord-2,this->yCord) << endl;
				//list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+2,this->yCord));
			}
			break;
		}
		i++;
	}
	i = 1;
	while (!this->moved &&
			state->isInsideBoard(this->xCord-i,this->yCord))
	{
		if (state->hasPieceAt(this->xCord-i,this->yCord)){
			if (state->getPieceType(this->xCord-i,this->yCord) == Piece::ROOK  &&
				!state->getPieceAt(this->xCord-i,this->yCord)->hasMoved())
			{
				list.push_back(new Castle(this->xCord,this->yCord,this->xCord-2,this->yCord));
				//cout << new ChessMove(this->xCord,this->yCord,this->xCord-2,this->yCord) << endl;
				////list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord-2,this->yCord));
			}
			break;
		}
		i++;
	}
	return list;
}

King *King::clone() const {
	return new King(*this);
}