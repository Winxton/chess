#include "chessmove.h"
#include "promotion.h"
#include "gamestate.h"
#include "piece.h"
#include "piecefactory.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

Promotion::Promotion(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest, string promoteTo): ChessMove(xCordSrc,yCordSrc,xCordDest,yCordDest){
	this->promoteTo = promoteTo;
	special = "promotion";
}

string toUpper(string s)
{
    transform(s.begin(), s.end(),s.begin(), ::toupper);
	return s;
}

string toLower(string s)
{
    transform(s.begin(), s.end(),s.begin(), ::tolower);
	return s;
}

void Promotion::apply (GameState &state, bool updateGraphics, bool saveState) const {
	if (saveState) saveCurrentStateAsPrevious(state);
	
	PieceFactory *factory = PieceFactory::getInstance();
	if (state.getPieceColor(xCordSrc,yCordSrc) == "black"){
		state.chessboard[xCordDest][yCordDest].setPiece(factory->createPiece(toLower(this->promoteTo)),updateGraphics);
	}
	else {
		state.chessboard[xCordDest][yCordDest].setPiece(factory->createPiece(toUpper(this->promoteTo)),updateGraphics);
	}
	
    //sets the piece to the new square on the board
	state.chessboard[xCordSrc][yCordSrc].removePiece(updateGraphics);
    
	
	//newPiece->setMoved();
}

ostream& Promotion::doPrint(std::ostream& out) const {
	return out << "(Promotion) Move from (" << (char)('a'+this->xCordSrc) << "," << (this->yCordSrc+1) << ") to (" 
	<< (char)('a'+this->xCordDest) << "," << (this->yCordDest+1) << ")";
}

