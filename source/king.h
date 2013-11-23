#ifndef __KING_H__
#define __KING_H__

#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <string>
#include <vector>

class King : public Piece 
{
bool moved;
public:
	King (string color);
	std::vector<ChessMove*> getPossibleMoves (GameState* state);
	bool hasMoved ();
};

#endif