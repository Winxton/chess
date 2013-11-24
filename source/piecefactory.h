#ifndef __PIECEFACTORY_H__
#define __PIECEFACTORY_H__

#include <string>

class Piece;

class PieceFactory {
	static PieceFactory *instance;
	static void cleanup();
public:
	static PieceFactory *getInstance();
	Piece *createPiece(std::string color, std::string pieceType);
};

#endif
