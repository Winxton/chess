#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <string>
#include <vector>

class Queen : public Piece 
{
public:
	static const int VALUE = 9;
	
	int getValue() const;
    Queen (std::string color);
    std::vector<ChessMove*> getPossibleMoves(const GameState* state) const;
    Queen *clone() const;
};

#endif
