#ifndef __ROOK_H__
#define __ROOK_H__

#include "piece.h"

class Rook : public Piece 
{
public:
    Rook (int xCord,
	      int yCord);
    std::vector<ChessMove*> getPossibleMoves (GameState* state);
    bool hasMoved ();
};

#endif
