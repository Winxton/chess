#include "piecefactory.h"
#include "piece.h"
#include "pawn.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include <cstdlib>
#include <string>
using namespace std;

PieceFactory *PieceFactory::instance = NULL;

void PieceFactory::cleanup() {
	delete instance;
}

PieceFactory *PieceFactory::getInstance() {
	if (instance == 0) {
		instance = new PieceFactory;
		atexit(cleanup);
	}
	return instance;
}

Piece *PieceFactory::createPiece(string color, string pieceType) {
	if (pieceType == "pawn") {
		return new Pawn(color);

	} else if (pieceType == "knight") {
		return new Knight(color);

	} else if (pieceType == "queen") {
		return new Queen(color);

	} else if (pieceType == "king") {
		return new King(color);

	} else if (pieceType == "bishop") {
		return new Bishop(color);

	} else if (pieceType == "rook") {
		return new Rook(color);

	} else {
		return 0;
	}
}