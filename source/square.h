#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <iostream>
class Xwindow;

class Piece;

class Square 
{
    int xCord, yCord;
    Piece *p;
    Xwindow *w;

public:
    
    Square();
    Square(Piece *p);

    Square (const Square &other); //copy constructor

    Square& operator=(const Square &other); //assignment operator

    //set the coordinates for the square
    void setCoords(int xCord, int yCord, Xwindow *w);

    // sets a piece to the square and updates
    // the piece's location to the location of the square
    // if a piece already exists in this square, delete that piece
    void setPiece(Piece *p, bool updateGraphics = false);
    
    //retrieves the piece sets the pointer to null
    Piece *getAndUnsetPiece(bool updateGraphics = false);

    //removes a piece from the board
    void removePiece(bool updateGraphics = false);

    //whether or not a chess piece is on the square
    bool hasPiece() const;

    const Piece *getPiece() const;

    friend std::ostream& operator<<(std::ostream &out, const Square &s);

    ~Square();
};

#endif
