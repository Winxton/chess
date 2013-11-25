#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <string>
#include <vector>

class Knight : public Piece 
{
public:
	Knight (std::string color);
	std::vector<ChessMove*> getPossibleMoves (const GameState* state) const;
	Knight *clone() const;
};

#endif
