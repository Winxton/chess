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

    // sets a piece to the square and updates
    // the piece's location to the location of the square
    void setPiece(Piece *p);
    
    //retrieves the piece sets the pointer to null
    Piece *getAndUnsetPiece();

    bool hasPiece();
    Piece *getPiece();
    ~Square();
};

#endif
