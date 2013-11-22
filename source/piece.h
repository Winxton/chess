#ifndef __PIECE_H__
#define __PIECE_H__

#include <vector>
class ChessMove;
class GameState;

class Piece{
public:
    virtual std::vector<ChessMove*> getPossibleMoves(GameState* state) = 0;
    virtual void setCoords (int xCord,
		    int yCord) = 0;
};

#endif
