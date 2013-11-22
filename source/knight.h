#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "piece.h"

class Knight : public Piece 
{
public:
	Knight (int xCord,
	        int yCord);
	std::vector<ChessMove*> getPossibleMoves (GameState* state);
};

#endif
