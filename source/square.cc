#include "square.h"
#include "piece.h"
using namespace std;

Square::Square(): p(0) {}

Square::Square(Piece *p): p(p) {}

Square::Square (const Square &other) {
    if (other.hasPiece()) {
        Piece *temp = &(*other.p);
        p = temp;
    } else {
        p = 0;
    }
}

Square& Square::operator=(const Square &other) {
    delete p;
    if (other.hasPiece()) {
        Piece *temp = &(*other.p);
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
