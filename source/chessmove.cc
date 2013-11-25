#include "chessmove.h"
#include "gamestate.h"
#include <iostream>
using namespace std;

ChessMove::ChessMove(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest): xCordSrc(xCordSrc), yCordSrc(yCordSrc), xCordDest(xCordDest), yCordDest(yCordDest) {}


void ChessMove::apply (GameState &state) {
	state.movePiece(xCordSrc, yCordSrc, xCordDest, yCordDest);
}

ChessMove::~ChessMove(){};

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
