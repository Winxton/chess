#include "chessmove.h"
#include "castle.h"
#include "gamestate.h"
#include "piece.h"
#include <iostream>
#include <string>
using namespace std;

Castle::Castle(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest): ChessMove(xCordSrc,yCordSrc,xCordDest,yCordDest){
	special = "castle";
}

void Castle::apply (GameState &state, bool updateGraphics) {
	Piece *p = state.chessboard[xCordSrc][yCordSrc].getAndUnsetPiece(updateGraphics);

    //sets the piece to the new square on the board
    state.chessboard[xCordDest][yCordDest].setPiece(p, updateGraphics);

	p->setMoved();
	
	if (xCordDest > xCordSrc){
		Piece *p1 = state.chessboard[xCordSrc+3][yCordSrc].getAndUnsetPiece(updateGraphics);

		//sets the piece to the new square on the board
		state.chessboard[xCordDest-1][yCordDest].setPiece(p1, updateGraphics);

		p1->setMoved();
	}
	else{
		Piece *p2 = state.chessboard[xCordSrc-4][yCordSrc].getAndUnsetPiece(updateGraphics);

		//sets the piece to the new square on the board
		state.chessboard[xCordDest+1][yCordDest].setPiece(p2, updateGraphics);

		p2->setMoved();
	}
}

ostream& Castle::doPrint(std::ostream& out) const {
	return out << "(Castle) Move from (" << (char)('a'+this->xCordSrc) << "," << (this->yCordSrc+1) << ") to (" 
	<< (char)('a'+this->xCordDest) << "," << (this->yCordDest+1) << ")";
}

string Castle::getSpecial(){
	return special;
}

