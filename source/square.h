#ifndef __SQUARE_H__
#define __SQUARE_H__

class Piece;

class Square 
{
    int xCord, yCord;
    Piece *p;
public:
    Square();
    Square(Piece *p);

    void setCoords(int xCord, int yCord);

    // add a piece to the square and updates
    // the piece's location to the location of the square
    void addPiece(Piece *p);
    
    void removePiece();
    bool hasPiece();
    Piece *getPiece();
    ~Square();
};

#endif
