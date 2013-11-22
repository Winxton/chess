#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"

class Pawn : public Piece 
{
public:
    Pawn (int xCord,
	       int yCord);
    std::vector<ChessMove*> getPossibleMoves(GameState* state);
};

#endif
