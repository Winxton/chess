#ifndef __SQUARE_H__
#define __SQUARE_H__

class Piece;

class Square 
{
	Piece *p;
public:
    Square ();
    void addPiece (Piece* p);
    void removePiece ();
    bool hasPiece ();
    Piece* getPiece ();
};

#endif