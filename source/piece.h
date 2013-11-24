#ifndef __PIECE_H__
#define __PIECE_H__

#include <vector>
#include <string>
class ChessMove;
class GameState;

class Piece{
protected:
    std::string color;
    int xCord, yCord;
public:
    Piece(std::string color);
    virtual std::string getColor();
    virtual std::vector<ChessMove*> getPossibleMoves(GameState* state) = 0;
    virtual void setCoords (int xCord,
                            int yCord);
    virtual ~Piece();
};

#endif
