#include "chessmove.h"
#include "gamestate.h"
using namespace std;

ChessMove::ChessMove(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest): xCordSrc(xCordSrc), yCordSrc(yCordSrc), xCordDest(xCordDest), yCordDest(yCordDest) {}


void ChessMove::apply (GameState *state) {
	state->movePiece(xCordSrc, yCordSrc, xCordDest, yCordDest);
}
