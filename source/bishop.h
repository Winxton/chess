#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "piece.h"

class Bishop : public Piece 
{
public:
	Bishop (int xCord,
	        int yCord);
	std::vector<ChessMove*> getPossibleMoves (GameState* state);
};

#endif