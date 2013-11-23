#include <vector>
#include "gamestate.h"
//#include "square.h"
#include "piece.h"
#include "chessmove.h"
using namespace std;

GameState::GameState(): whiteChecked(false), blackChecked(false) {
}

GameState::GameState(const GameState &state) {}

bool GameState::isUnderCheck (Player *p) {
    return false;
}

void GameState::initializeDefault() {
    
}

vector<ChessMove*> GameState::getPossibleMovesForPlayer (Player *p) {
    vector<ChessMove*> v;
    return v;
}

vector<ChessMove*> GameState::getLegalMovesForPlayer (Player *p) {
    vector<ChessMove*> possibleMoves = getPossibleMovesForPlayer(p);
    return possibleMoves;
}

Piece *GameState::getPieceAt(int xCord, int yCord) {
    if (xCord < 0 || xCord > 7
        || yCord < 0 || yCord > 7) {
        return 0; // out of bounds
    } else {
        return chessboard[xCord][yCord].getPiece();
    }
}

void GameState::printBoard () {
    
}
