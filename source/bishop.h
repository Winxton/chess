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
	Bishop (std::string color);
	std::vector<ChessMove*> getPossibleMoves (GameState* state);
};

#endif