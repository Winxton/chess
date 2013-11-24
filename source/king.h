#ifndef __KING_H__
#define __KING_H__

#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <string>
#include <vector>

class King : public Piece 
{
public:
	King (std::string color);
	std::vector<ChessMove*> getPossibleMoves(GameState* state) const;
};

#endif