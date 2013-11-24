#include <vector>
#include "gamestate.h"
#include "square.h"
#include "piece.h"
#include "chessmove.h"
#include "piecefactory.h"
#include <iostream>
using namespace std;

GameState::GameState(): whiteChecked(false), blackChecked(false) {
    setSquareNumberings();
}

GameState::GameState(const GameState &state) {
    setSquareNumberings();
}

void GameState::setSquareNumberings() {
    for (int i =0; i< 8; i++) {
        for (int j=0; j< 8; j++) {
            chessboard[i][j].setCoords(i,j);
        }
    }
}

void GameState::movePiece(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest) {
    //get the piece pointer from the square
    Piece *p = chessboard[yCordSrc][xCordSrc].getAndUnsetPiece();
    //sets the piece to the new square on the board
    chessboard[yCordDest][xCordDest].setPiece(p);
}

bool GameState::isUnderCheck (string color) const {
    return false;
}

void GameState::initializeDefault() {
    //initialize the original configuration of the board.
	PieceFactory *p = PieceFactory::getInstance();
	for (int i = 0; i<8;i++){
		this->chessboard[1][i].setPiece(p->createPiece("white","pawn"));
		this->chessboard[6][i].setPiece(p->createPiece("black","pawn"));
	}
	this->chessboard[0][0].setPiece(p->createPiece("white","rook"));
	this->chessboard[0][7].setPiece(p->createPiece("white","rook"));
	this->chessboard[7][0].setPiece(p->createPiece("black","rook"));
	this->chessboard[7][7].setPiece(p->createPiece("black","rook"));
	this->chessboard[0][1].setPiece(p->createPiece("white","knight"));
	this->chessboard[0][6].setPiece(p->createPiece("white","knight"));
	this->chessboard[7][1].setPiece(p->createPiece("black","knight"));
	this->chessboard[7][6].setPiece(p->createPiece("black","knight"));
	this->chessboard[0][2].setPiece(p->createPiece("white","bishop"));
	this->chessboard[0][5].setPiece(p->createPiece("white","bishop"));
	this->chessboard[7][2].setPiece(p->createPiece("black","bishop"));
	this->chessboard[7][5].setPiece(p->createPiece("black","bishop"));
	this->chessboard[0][3].setPiece(p->createPiece("white","queen"));
	this->chessboard[0][4].setPiece(p->createPiece("white","king"));
	this->chessboard[7][3].setPiece(p->createPiece("black","queen"));
	this->chessboard[7][4].setPiece(p->createPiece("black","king"));
}

vector<ChessMove*> GameState::getPossibleMovesForPlayer (const Player *p) const {
    vector<ChessMove*> v;
    return v;
}

vector<ChessMove*> GameState::getLegalMovesForPlayer (const Player *p) const {
    vector<ChessMove*> possibleMoves = getPossibleMovesForPlayer(p);
    return possibleMoves;
}

bool GameState::isInsideBoard(int xCord, int yCord) const {
    return (xCord >= 0 && xCord <= 7
            && yCord >= 0 && yCord <= 7);
}

bool GameState::hasPieceAt(int xCord, int yCord) const {
	if (this->getPieceAt(xCord,yCord) == 0)
		return false;
	return true;
}

bool GameState::hasPieceOfOppositeColor(string color,int xCord, int yCord) const {
	return (this->getPieceAt(xCord,yCord)->getColor() == color);
}

const Piece *GameState::getPieceAt(int xCord, int yCord) const {
    if (!isInsideBoard(xCord, yCord)) {
        return 0; // out of bounds
    } else {
        return chessboard[yCord][xCord].getPiece();
    }
}

string GameState::getPieceType(int xCord, int yCord) const {
	if (this->hasPieceAt(xCord,yCord)) {
		char temp = this->getPieceAt(xCord,yCord)->getCharRepr();
		if (temp == 'p' || temp == 'P')
			return "pawn";
		else if (temp == 'r' || temp == 'R')
			return "rook";
		else if (temp == 'n' || temp == 'N')
			return "knight";
		else if (temp == 'b' || temp == 'B')
			return "bishop";
		else if (temp == 'q' || temp == 'Q')
			return "queen";
		else
			return "king";
	} else {
        return "";
    }
}

void GameState::printBoard() const {
    for (int row = 7; row >= 0; row--) {
        cout << row+1 << " ";
        for (int col = 0; col <=7; col ++) {
            cout << chessboard[row][col];
        }
        cout << endl;
    }
    cout << endl;
    cout << "  ";
    for (int i =0; i<8; i++) {
        cout << (char)('a'+i);
    }
    cout << endl;
}
