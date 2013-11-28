#include "chessmove.h"
#include "enpassant.h"
#include "gamestate.h"
#include "piece.h"
#include <iostream>
#include <string>
using namespace std;

EnPassant::EnPassant(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest): ChessMove(xCordSrc,yCordSrc,xCordDest,yCordDest){
	special = "enpassant";
}

void EnPassant::apply (GameState &state, bool updateGraphics) {
	Piece *p = state.chessboard[xCordSrc][yCordSrc].getAndUnsetPiece(updateGraphics);

    //sets the piece to the new square on the board
    state.chessboard[xCordDest][yCordDest].setPiece(p, updateGraphics);

	p->setMoved();
	
	if (yCordDest > yCordSrc){
		state.chessboard[xCordDest][yCordDest-1].getAndUnsetPiece(updateGraphics);
	}
	else {
		state.chessboard[xCordDest][yCordDest+1].getAndUnsetPiece(updateGraphics);
	}
}

ostream& EnPassant::doPrint(std::ostream& out) const {
	return out << "(EnPassant) Move from (" << (char)('a'+this->xCordSrc) << "," << (this->yCordSrc+1) << ") to (" 
	<< (char)('a'+this->xCordDest) << "," << (this->yCordDest+1) << ")";
}

string EnPassant::getSpecial(){
	return special;
}

