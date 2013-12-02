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
	static const int VALUE = 100;
	
	int getValue() const;
	King (std::string color);
	std::vector<ChessMove*> getPossibleMoves(const GameState* state) const;
	King *clone() const;
};

#endif