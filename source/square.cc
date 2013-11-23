#include "square.h"
#include "piece.h"
using namespace std;

Square::Square(): p(0) {}

Square::Square(Piece *p): p(p) {}

void Square::addPiece(Piece *p) {
    this->p = p;
}

void Square::removePiece () {
    delete p;
    p = 0;
}

bool Square::hasPiece() {
    return (! p==0);
}

Piece *Square::getPiece() {
    return p;
}

Square::~Square() {
    delete p;
}
