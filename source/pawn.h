#ifndef __PAWN_H__
#define __PAWN_H__

#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <string>
#include <vector>

class Pawn : public Piece 
{
public:
    Pawn (std::string color);
    std::vector<ChessMove*> getPossibleMoves(const GameState* state) const;
    Pawn *clone() const;
};

#endif
