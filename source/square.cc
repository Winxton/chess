#include "square.h"
#include "piece.h"
#include "window.h"
#include <string>
using namespace std;

Square::Square(): p(0) {}

Square::Square(Piece *p): p(p) {}

Square::Square (const Square &other) {
    xCord = other.xCord;
    yCord = other.yCord;
    w = other.w; //shallow copy the window

    if (other.hasPiece()) {
        Piece *temp = other.p->clone(); //deep copy the piece
        p = temp;
    } else {
        p = 0;
    }
}

Square& Square::operator=(const Square &other) {
    xCord = other.xCord;
    yCord = other.yCord;
    w = other.w; //shallow copy the window

    delete p;
    if (other.hasPiece()) {
        Piece *temp = other.p->clone(); //deep copy the piece
        p = temp;
    } else {
        p = 0;
    }
    return *this;
}

void Square::setCoords(int xCord, int yCord, Xwindow *w) {
    this->xCord = xCord;
    this->yCord = yCord;
    this->w = w;
}

void Square::setPiece(Piece *p, bool updateGraphics) {
	delete this->p;
    this->p = p;
    
    if (!p==0) this->p->setCoords(xCord, yCord);
    if (updateGraphics) {
        w->removePiece(xCord, yCord);
        if (hasPiece()) w->putPiece(xCord, yCord, string(1, this->p->getCharRepr()) );
    }
}

Piece *Square::getAndUnsetPiece (bool updateGraphics) {
	Piece *piece = p;
    p = 0;
    if (updateGraphics) {
        w->removePiece(xCord, yCord);
    }
    return piece;
}

void Square::removePiece(bool updateGraphics) {
    delete p;
    p = 0;
    if (updateGraphics) {
        w->removePiece(xCord, yCord);
    }
}

bool Square::hasPiece() const {
    return (! p==0);
}

const Piece *Square::getPiece() const {
    return p;
}

Square::~Square() {
    delete p;
}


ostream& operator<<(ostream &out, const Square &s) {
    //use the representation if there is a piece, otherwise
    //print the blank board (either "_" or " " depending on coordinates)
    char r = s.hasPiece() ? s.getPiece()->getCharRepr()
        : ( (s.xCord%2 == 0 && s.yCord%2 == 0) 
            || (s.xCord%2 == 1 && s.yCord%2 == 1) ? '_' : ' ');

    out << r;
    return out;
}