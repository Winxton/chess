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
    initializeDefault();
}

GameState::GameState(const GameState &state): whiteChecked(false), blackChecked(false) {
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
    Piece *p = chessboard[xCordSrc][yCordSrc].getAndUnsetPiece();
    //sets the piece to the new square on the board
    chessboard[xCordDest][yCordDest].setPiece(p);
}

bool GameState::isUnderCheck (string color) const {
    return false;
}

void GameState::initializeDefault() {
    //initialize the original configuration of the board.
	PieceFactory *p = PieceFactory::getInstance();
	for (int i = 0; i<8;i++){
		this->chessboard[i][1].setPiece(p->createPiece("white","pawn"));
		this->chessboard[i][6].setPiece(p->createPiece("black","pawn"));
	}
	this->chessboard[0][0].setPiece(p->createPiece("white","rook"));
	this->chessboard[7][0].setPiece(p->createPiece("white","rook"));
	this->chessboard[0][7].setPiece(p->createPiece("black","rook"));
	this->chessboard[7][7].setPiece(p->createPiece("black","rook"));
	this->chessboard[1][0].setPiece(p->createPiece("white","knight"));
	this->chessboard[6][0].setPiece(p->createPiece("white","knight"));
	this->chessboard[1][7].setPiece(p->createPiece("black","knight"));
	this->chessboard[6][7].setPiece(p->createPiece("black","knight"));
	this->chessboard[2][0].setPiece(p->createPiece("white","bishop"));
	this->chessboard[5][0].setPiece(p->createPiece("white","bishop"));
	this->chessboard[2][7].setPiece(p->createPiece("black","bishop"));
	this->chessboard[5][7].setPiece(p->createPiece("black","bishop"));
	this->chessboard[3][0].setPiece(p->createPiece("white","queen"));
	this->chessboard[4][0].setPiece(p->createPiece("white","king"));
	this->chessboard[3][7].setPiece(p->createPiece("black","queen"));
	this->chessboard[4][7].setPiece(p->createPiece("black","king"));
}

vector<ChessMove*> GameState::getPossibleMovesForPlayer (string color) const {
    vector<ChessMove *> v;
    for (int i =0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (getPieceColor(i,j) == color) {
                v = getPieceAt(i,j)->getPossibleMoves(this);
            }
        }
    }
    return v;
}

vector<ChessMove*> GameState::getLegalMovesForPlayer (string color) const {
    vector<ChessMove*> possibleMoves = getPossibleMovesForPlayer(color);
    return possibleMoves;
}

bool GameState::isInsideBoard(int xCord, int yCord) const {
    return (xCord >= 0 && xCord <= 7
            && yCord >= 0 && yCord <= 7);
}

const Piece *GameState::getPieceAt(int xCord, int yCord) const {
    if (!isInsideBoard(xCord, yCord)) {
        return 0; // out of bounds
    } else {
        return chessboard[xCord][yCord].getPiece();
    }
}

bool GameState::hasPieceAt(int xCord, int yCord) const {
	if (getPieceAt(xCord,yCord) == 0)
		return false;
	return true;
}

string GameState::getPieceColor(int xCord, int yCord) const {
    if (hasPieceAt(xCord, yCord))
        return getPieceAt(xCord,yCord)->getColor();
    return "";
}

bool GameState::hasPieceOfOppositeColor(string color,int xCord, int yCord) const {
    string oppositeColor = color == "white" ? "black" : "white"; 
	return (getPieceColor(xCord, yCord) == oppositeColor);
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
            cout << chessboard[col][row];
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
