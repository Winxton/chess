#include "piece.h"
#include <vector>
using namespace std;

Piece::Piece(string color): color(color), xCord(-1), yCord(-1) {};

Piece::setCoords (int xCord, int yCord) {
    this->xCord = xCord;
    this->yCord = yCord;
}

Piece::~Piece() {}
