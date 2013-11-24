#include "knight.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Knight::Knight(std::string color):Piece(color) {
    cout << "cons" << endl;
}

std::vector<ChessMove*> Knight::getPossibleMoves(GameState* state) {
	std::vector<ChessMove*> list;
	int i;
	int j;
	i = -2;
	j = -1;
	if ((this->xCord+i > -1 && this->xCord+i < 8 && 
			this->yCord+j > -1 && this->yCord+j < 8 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
	}
	i = -2;
	j = 1;
	if ((this->xCord+i > -1 && this->xCord+i < 8 && 
			this->yCord+j > -1 && this->yCord+j < 8 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
	}
	i = 2;
	j = -1;
	if ((this->xCord+i > -1 && this->xCord+i < 8 && 
			this->yCord+j > -1 && this->yCord+j < 8 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
	}
	i = 2;
	j = 1;
	if ((this->xCord+i > -1 && this->xCord+i < 8 && 
			this->yCord+j > -1 && this->yCord+j < 8 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
	}
	i = -1;
	j = -2;
	if ((this->xCord+i > -1 && this->xCord+i < 8 && 
			this->yCord+j > -1 && this->yCord+j < 8 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
	}
	i = -1;
	j = 2;
	if ((this->xCord+i > -1 && this->xCord+i < 8 && 
			this->yCord+j > -1 && this->yCord+j < 8 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
	}	
	i = 1;
	j = -2;
	if ((this->xCord+i > -1 && this->xCord+i < 8 && 
			this->yCord+j > -1 && this->yCord+j < 8 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
	}	
	i = 1;
	j = 2;
	if ((this->xCord+i > -1 && this->xCord+i < 8 && 
			this->yCord+j > -1 && this->yCord+j < 8 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.push_back(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
	}
	return list;
}
