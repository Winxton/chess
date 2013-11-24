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
    Piece(std::string color);
    virtual std::string getColor() const;
    virtual std::vector<ChessMove*> getPossibleMoves(GameState* state) const = 0;
	char getCharRepr() const;
	virtual bool hasMoved() const;
	virtual void setMoved();
    virtual void setCoords (int xCord,
                            int yCord);
    virtual ~Piece();
};

#endif
