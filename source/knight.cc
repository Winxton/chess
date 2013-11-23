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
	std::vector<ChessMove*>::iterator it;
	int i;
	int j;
	i = -2;
	j = -1;
	if ((this->xCord+i > 0 && this->xCord+i < 9 && 
			this->yCord+j > 0 && this->yCord+j < 9 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.insert(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			it = list.end();
	}
	i = -2;
	j = 1;
	if ((this->xCord+i > 0 && this->xCord+i < 9 && 
			this->yCord+j > 0 && this->yCord+j < 89 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.insert(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			it = list.end();
	}
	i = 2;
	j = -1;
	if ((this->xCord+i > 0 && this->xCord+i < 9 && 
			this->yCord+j > 0 && this->yCord+j < 9 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.insert(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			it = list.end();
	}
	i = 2;
	j = 1;
	if ((this->xCord+i > 0 && this->xCord+i < 9 && 
			this->yCord+j > 0 && this->yCord+j < 9 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.insert(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			it = list.end();
	}
	i = -1;
	j = -2;
	if ((this->xCord+i > 0 && this->xCord+i < 9 && 
			this->yCord+j > 0 && this->yCord+j < 9 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.insert(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			it = list.end();
	}
	i = -1;
	j = 2;
	if ((this->xCord+i > 0 && this->xCord+i < 9 && 
			this->yCord+j > 0 && this->yCord+j < 9 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.insert(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			it = list.end();
	}	
	i = 1;
	j = -2;
	if ((this->xCord+i > 0 && this->xCord+i < 9 && 
			this->yCord+j > 0 && this->yCord+j < 9 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.insert(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			it = list.end();
	}	
	i = 1;
	j = 2;
	if ((this->xCord+i > 0 && this->xCord+i < 9 && 
			this->yCord+j > 0 && this->yCord+j < 9 &&
			state->getPieceAt(this->xCord+i,this->yCord+j) == NULL) ||
			(state->getPieceAt(this->xCord+i,this->yCord+j) != NULL &&
			state->getPieceAt(this->xCord+i,this->yCord+j)->color != this->color))
	{
			list.insert(new ChessMove(this->xCord,this->yCord,this->xCord+i,this->yCord+j));
			it = list.end();
	}
	return list;
}
