#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <iostream>

class Piece;

class Square 
{
    int xCord, yCord;
    Piece *p;
public:
    Square();
    Square(Piece *p);

    Square (const Square &other); //copy constructor

    Square& operator=(const Square &other); //assignment operator

    //set the coordinates for the square
    void setCoords(int xCord, int yCord);

    // sets a piece to the square and updates
    // the piece's location to the location of the square
    void setPiece(Piece *p);
    
    //retrieves the piece sets the pointer to null
    Piece *getAndUnsetPiece();

    //whether or not a chess piece is on the square
    bool hasPiece() const;

    const Piece *getPiece() const;

    friend std::ostream& operator<<(std::ostream &out, const Square &s);

    ~Square();
};

#endif
