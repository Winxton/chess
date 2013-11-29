#include "computerplayer.h"
#include "chessmove.h"
#include "gamestate.h"
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

ComputerPlayer::ComputerPlayer(std::string color, int level): Player(color), level(level) {}

// Level 1 - random moves
Action *ComputerPlayer::getLevel1Action(const GameState& state) const {
    vector<ChessMove*> legalMoves = state.getLegalMovesForPlayer(color);

    unsigned int moveIdx =  rand() % legalMoves.size();

    // stores the result of the move
    ChessMove *theMove = legalMoves[moveIdx];
    // delete the other generated moves
    for (unsigned int i =0; i<legalMoves.size(); i++) {
        cout << *legalMoves[i] << endl;
        if (i != moveIdx)
            delete legalMoves[i];
    }

    return theMove;
}

// Level 2
// Prefer capturing moves and checks!
Action *ComputerPlayer::getLevel2Action(const GameState& state) const {
    vector<ChessMove*> legalMoves = state.getLegalMovesForPlayer(color);
    
    int moveIdx = -1;

    // Gets the FIRST attacking move
    for (int i =0; i<legalMoves.size(); i++) {
        if (legalMoves[i]->capturesPiece(state)) {
            moveIdx = i;
            break;
        }
    }
    
    if (moveIdx == -1) {
        //has not found an attacking move, choose a random move.
        moveIdx =  rand() % legalMoves.size();
    }

    // stores the result of the move
    ChessMove *theMove = legalMoves[moveIdx];
    // delete the other generated moves
    for (int i =0; i<legalMoves.size(); i++) {
        if (i != moveIdx)
            delete legalMoves[i];
    }

    return theMove;
}

// Level 3
// Prefer Attacking moves, and avoiding capture, and checks!
Action *ComputerPlayer::getLevel3Action(const GameState& state) const {
    vector<ChessMove*> legalMoves = state.getLegalMovesForPlayer(color);
    
    cout << "MOVES: " << legalMoves.size() << endl;

    int moveIdx = -1;

    // Gets the FIRST attacking move
    for (int i =0; i<legalMoves.size(); i++) {
        if (legalMoves[i]->avoidsCaptureAfterMove(state)
            || legalMoves[i]->capturesPiece(state)
            || legalMoves[i]->checksOpponent(state)) {
            moveIdx = i;
            break;
        }
    }
    
    if (moveIdx == -1) {
        //has not found an attacking move, choose a random move.
        moveIdx =  rand() % legalMoves.size();
    }

    // stores the result of the move
    ChessMove *theMove = legalMoves[moveIdx];
    // delete the other generated moves
    for (int i =0; i<legalMoves.size(); i++) {
        cout << *legalMoves[i] << endl;
        if (i != moveIdx)
            delete legalMoves[i];
    }

    return theMove;
}

// Level 4
Action *ComputerPlayer::getLevel4Action(const GameState& state) const {
    return getLevel3Action(state); //temporary
}

Action *ComputerPlayer::getAction(const GameState& state) const {
    srand( time(0) );
    if (level == 1) {
	   return getLevel1Action(state);
    } else if (level == 2) {
	   return getLevel2Action(state);
    } else if (level == 3) {
	   return getLevel3Action(state);
    } else { // if (level == LEVEL4) {
	   return getLevel4Action(state);
    }
}
