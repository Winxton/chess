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

Piece *PieceFactory::createPiece(string pieceType) {
	if (pieceType == "P") {
		return new Pawn("white");

	} else if (pieceType == "p") {
		return new Pawn("black");

	} else if (pieceType == "N") {
		return new Knight("white");

	} else if (pieceType == "n") {
		return new Knight("black");

	} else if (pieceType == "Q") {
		return new Queen("white");

	} else if (pieceType == "q") {
		return new Queen("black");

	} else if (pieceType == "K") {
		return new King("white");

	} else if (pieceType == "k") {
		return new King("black");

	} else if (pieceType == "B") {
		return new Bishop("white");

	} else if (pieceType == "b") {
		return new Bishop("black");

	} else if (pieceType == "R") {
		return new Rook("white");

	} else if (pieceType == "r") {
		return new Rook("black");

	} else {
		return 0;
	}
}