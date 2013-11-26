#include "square.h"
#include "piece.h"
using namespace std;

Square::Square(): p(0) {}

Square::Square(Piece *p): p(p) {}

Square::Square (const Square &other) {
    xCord = other.xCord;
    yCord = other.yCord;

    if (other.hasPiece()) {
        Piece *temp = other.p->clone();
        p = temp;
    } else {
        p = 0;
    }
}

Square& Square::operator=(const Square &other) {
    xCord = other.xCord;
    yCord = other.yCord;

    delete p;
    if (other.hasPiece()) {
        Piece *temp = other.p->clone();
        p = temp;
    } else {
        p = 0;
    }
    return *this;
}

void Square::setCoords(int xCord, int yCord) {
    this->xCord = xCord;
    this->yCord = yCord;
}

void Square::setPiece(Piece *p) {
	delete this->p;
    this->p = p;
    this->p->setCoords(xCord, yCord);
}

Piece *Square::getAndUnsetPiece () {
	Piece *piece = p;
    p = 0;
    return piece;
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