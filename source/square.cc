#include "square.h"
#include "piece.h"
using namespace std;

Square::Square(): p(0) {}

Square::Square(Piece *p): p(p) {}

void Square::setCoords(int xCord, int yCord) {
    this->xCord = xCord;
    this->yCord = yCord;
}

void Square::setPiece(Piece *p) {
	delete p;
    this->p = p;
}

Piece *Square::getAndUnsetPiece () {
	Piece *piece = p;
    p = 0;
    return piece;
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
