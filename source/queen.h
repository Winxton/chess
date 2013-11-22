#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "piece.h"

class Queen : public Piece 
{
public:
    Queen (int xCord,
	       int yCord);
    std::vector<ChessMove*> getPossibleMoves(GameState* state);
};

#endif
