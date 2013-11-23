#include "chessmove.h"
#include "gamestate.h"
using namespace std;

void ChessMove::apply (GameState *state) {
	state->movePiece(xCordSrc, yCordSrc, xCordDest, yCordDest);
}
