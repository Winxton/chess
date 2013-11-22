#ifndef __KING_H__
#define __KING_H__

#include "piece.h"

class King : public Piece 
{
public:
	King (int xCord,
	      int yCord);
	std::vector<ChessMove*> getPossibleMoves (GameState* state);
	bool hasMoved ();
};

#endif