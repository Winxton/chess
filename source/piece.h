#ifndef __PIECE_H__
#define __PIECE_H__

#include <vector>
#include <string>
class ChessMove;
class GameState;

class Piece{
protected:
    std::string color;
	char repr;
	bool moved;
    int xCord, yCord;
public:
    const static int PAWN = 0;
    const static int KNIGHT = 1;
    const static int ROOK = 2;
    const static int BISHOP = 3;
    const static int KING = 4;
    const static int QUEEN = 5;

    Piece(std::string color);
    virtual std::string getColor() const;
    virtual std::vector<ChessMove*> getPossibleMoves(const GameState* state) const = 0;
	char getCharRepr() const;
	virtual bool hasMoved() const;
	virtual void setMoved();
    virtual void setCoords(int xCord, int yCord);
    virtual Piece *clone() const = 0;
    virtual ~Piece();
};

#endif
