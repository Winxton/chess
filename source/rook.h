#ifndef __ROOK_H__
#define __ROOK_H__

#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <string>
#include <vector>

class Rook : public Piece 
{
public:
    Rook(std::string color);
    std::vector<ChessMove*> getPossibleMoves (const GameState* state) const;
};

#endif
