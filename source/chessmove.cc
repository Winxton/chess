#include "chessmove.h"
#include "gamestate.h"
#include "piece.h"
#include <string>
#include <iostream>
using namespace std;

ChessMove::ChessMove(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest): xCordSrc(xCordSrc), yCordSrc(yCordSrc), xCordDest(xCordDest), yCordDest(yCordDest) {
	special = "";
}

bool ChessMove::capturesPiece(const GameState &state) const {
	return state.hasPieceAt(xCordDest, yCordDest);
}

bool ChessMove::checksOpponent(const GameState &state) const {
	//color of the moving piece
	string myColor = state.getPieceColor(xCordSrc, yCordSrc); 
	//create a temporary state and apply the action to it
	GameState temp = state;
	apply(temp);
	//returns true if the opponent is under check
	bool underCheck =  (temp.isUnderCheck(
		myColor == "white" ? "black" : "white"
		));
	temp.setPreviousState(0);
	return underCheck;
}

bool ChessMove::avoidsCaptureAfterMove(const GameState &state) const {
	//color of the moving piece
	string myColor = state.getPieceColor(xCordSrc, yCordSrc); 
	//create a temporary state and apply the action to it
	GameState temp = state;
	apply(temp);
	
	bool underAttack = false;
	underAttack = temp.playerUnderAttack(myColor); 

	temp.setPreviousState(0);
	return !underAttack;
}

void ChessMove::apply (GameState &state, bool updateGraphics, bool saveState) const {
	if (saveState) saveCurrentStateAsPrevious(state);
	//get the piece pointer from the square
    Piece *p = state.chessboard[xCordSrc][yCordSrc].getAndUnsetPiece(updateGraphics);

    //sets the piece to the new square on the board
    state.chessboard[xCordDest][yCordDest].setPiece(p, updateGraphics);

	p->setMoved();
}

ChessMove::~ChessMove(){};

bool ChessMove::hasSameDestination(int xCord, int yCord) const {
	return xCord==xCordDest && yCord==yCordDest;
}

ostream& ChessMove::doPrint(std::ostream& out) const {
	return out << "Move from (" << (char)('a'+this->xCordSrc) << "," << (this->yCordSrc+1) << ") to (" 
	<< (char)('a'+this->xCordDest) << "," << (this->yCordDest+1) << ")";
}
/*
std::ostream& operator<<(std::ostream &out, const ChessMove &s) {
	return s.doPrint(out);
}
*/
bool ChessMove::operator==(const ChessMove &other) {
	return (xCordSrc==other.xCordSrc
		&& yCordSrc==other.yCordSrc
		&& xCordDest==other.xCordDest
		&& yCordDest==other.yCordDest);
}

int ChessMove::getXCordDest() const {
	return xCordDest;
}

int ChessMove::getYCordDest() const {
	return yCordDest;
}

string ChessMove::getSpecial(){
	return special;
}
