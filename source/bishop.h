#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <string>
#include <vector>

class Bishop : public Piece 
{
public:
	static const int VALUE = 3;

	int getValue() const;
	Bishop (std::string color);
	std::vector<ChessMove*> getPossibleMoves(const GameState* state) const;
	Bishop *clone() const;
};

#endif