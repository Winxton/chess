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
    Queen (std::string color);
    std::vector<ChessMove*> getPossibleMoves(GameState* state);
};

#endif
