#ifndef __PIECEFACTORY_H__
#define __PIECEFACTORY_H__

#include <string>

class Piece;

class PieceFactory {
	static PieceFactory *instance;
	static void cleanup();
public:
	static PieceFactory *getInstance();
	
	//creates a piece given the piece type, NULL if undefined type
	Piece *createPiece(std::string pieceType);
};

#endif
