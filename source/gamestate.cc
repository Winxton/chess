#include <vector>
#include "gamestate.h"
#include "square.h"
#include "piece.h"
#include "chessmove.h"
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
    Piece *p = chessboard[xCordSrc][yCordSrc].getAndUnsetPiece();
    //sets the piece to the new square on the board
    chessboard[xCordDest][yCordDest].setPiece(p);
}

bool GameState::isUnderCheck (Player *p) {
    return false;
}

void GameState::initializeDefault() {
    //initialize the original configuration of the board.
}

vector<ChessMove*> GameState::getPossibleMovesForPlayer (Player *p) {
    vector<ChessMove*> v;
    return v;
}

vector<ChessMove*> GameState::getLegalMovesForPlayer (Player *p) {
    vector<ChessMove*> possibleMoves = getPossibleMovesForPlayer(p);
    return possibleMoves;
}

bool GameState::isInsideBoard(int xCord, int yCord) {
    return (xCord >= 0 && xCord <= 7
            && yCord >= 0 && yCord <= 7);
}

bool GameState::hasPieceAt(int xCord, int yCord){
	if (this->getPieceAt(xCord,yCord) == 0)
		return false;
	return true;
}

bool GameState::hasPieceOfOppositeColor(string color,int xCord, int yCord){
	return (this->getPieceAt(xCord,yCord)->getColor() == color);
}

Piece *GameState::getPieceAt(int xCord, int yCord) {
    if (!isInsideBoard(xCord, yCord)) {
        return 0; // out of bounds
    } else {
        return chessboard[xCord][yCord].getPiece();
    }
}

string GameState::getPieceType(int xCord, int yCord){
	if (this->hasPieceAt(xCord,yCord)){
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
	}
}

void GameState::printBoard () {
    
}
