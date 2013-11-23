#ifndef __SQUARE_H__
#define __SQUARE_H__

class Piece;

class Square 
{
    Piece *p;
public:
    Square();
    Square(Piece *p);
    void addPiece(Piece *p);
    void removePiece();
    bool hasPiece();
    Piece *getPiece();
    ~Square();
};

#endif
