#include "chessmove.h"
#include "gamestate.h"
#include <iostream>
using namespace std;

ChessMove::ChessMove(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest): xCordSrc(xCordSrc), yCordSrc(yCordSrc), xCordDest(xCordDest), yCordDest(yCordDest) {}


void ChessMove::apply (GameState *state) {
	state->movePiece(xCordSrc, yCordSrc, xCordDest, yCordDest);
}

ChessMove::~ChessMove(){};

std::ostream& operator<<(std::ostream &out, const ChessMove &s) {
	out << "Move from (" << (char)('a'+s.xCordSrc) << "," << (s.yCordSrc+1) << ") to (" 
	<< (char)('a'+s.xCordDest) << "," << (s.yCordDest+1) << ")";
	return out;
}