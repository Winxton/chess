#include "piece.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Piece::Piece(string color): color(color), xCord(-1), yCord(-1) {};

string Piece::getColor() const {
	return color;
}

char Piece::getCharRepr() const {
	return repr;
}

bool Piece::hasMoved() const{
	return moved;
}

void Piece::setMoved() {
	moved = true;
}

void Piece::setCoords (int xCord, int yCord) {
    this->xCord = xCord;
    this->yCord = yCord;
}

Piece::~Piece() {}
