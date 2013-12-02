#include "computerplayer.h"
#include "chessmove.h"
#include "gamestate.h"
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

ComputerPlayer::ComputerPlayer(std::string color, int level): Player(color), level(level) {}

// Level 1 - random moves
Action *ComputerPlayer::getLevel1Action(const GameState& state) const {
    srand( time(0) );
    vector<ChessMove*> legalMoves = state.getLegalMovesForPlayer(color);
    
    for (unsigned int i =0; i<legalMoves.size(); i++) {
        cout << *legalMoves[i] << endl;
    }

    unsigned int moveIdx = rand() % legalMoves.size();

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
    srand( time(0) );
    vector<ChessMove*> legalMoves = state.getLegalMovesForPlayer(color);
    
    unsigned int moveIdx = rand() % legalMoves.size();

    // Gets the FIRST attacking move
    for (unsigned int i =0; i<legalMoves.size(); i++) {
        if (legalMoves[i]->capturesPiece(state)) {
            moveIdx = i;
            break;
        }
    }

    // stores the result of the move
    ChessMove *theMove = legalMoves[moveIdx];
    // delete the other generated moves
    for (unsigned int i =0; i<legalMoves.size(); i++) {
        if (i != moveIdx)
            delete legalMoves[i];
    }

    return theMove;
}

// Level 3
// Prefer Attacking moves, and avoiding capture, and checks!
Action *ComputerPlayer::getLevel3Action(const GameState& state) const {
    srand( time(0) );
    vector<ChessMove*> legalMoves = state.getLegalMovesForPlayer(color);
    
    cout << "MOVES: " << legalMoves.size() << endl;

    unsigned int moveIdx = rand() % legalMoves.size();

    // Gets the FIRST attacking move if there is one
    for (unsigned int i =0; i<legalMoves.size(); i++) {
        if (legalMoves[i]->avoidsCaptureAfterMove(state)
            || legalMoves[i]->capturesPiece(state)
            || legalMoves[i]->checksOpponent(state)) {
            moveIdx = i;
            break;
        }
    }

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

// Level 4
int MAX_DEPTH = 3;
int leaves = 0;

int ComputerPlayer::getValue(GameState *state, int depth, string color, ChessMove *&bestMove, int alpha, int beta) const {
    if (depth == 0) {
        leaves ++;
        return state->getValueForPlayer(color);
    }
    else 
    {
        vector<ChessMove*> legalMoves = state->getLegalMovesForPlayer(color);

        // CHEKMATE!
        if (legalMoves.size() == 0) {
            if (state->isUnderCheck(color)) return -100000;
        }

        for (unsigned int i =0; i<legalMoves.size(); i++) 
        {
            
            GameState *newState = new GameState(*state);
            //apply move to state
            
            legalMoves[i]->apply(*newState);
            newState->setPreviousState(state); //used for pawn movements
            string oppositeColor = color == "white" ? "black" : "white";
            int result = -getValue(newState, depth-1, oppositeColor, bestMove, -beta, -alpha);

            if (result >= beta)
            {
                // Beta cut-off
                //return beta;
                
                for (unsigned int i =0; i<legalMoves.size(); i++) {
                    delete legalMoves[i];
                }

                newState->setPreviousState(0);
                delete newState;

                return beta;
            }
            
            if (result > alpha)
            {
                alpha = result;

                if (depth == MAX_DEPTH) 
                {
                    delete bestMove;
                    bestMove = legalMoves[i]; 
                    //cerr << *bestMove << endl;
                    legalMoves[i] = 0;
                }

            }

            newState->setPreviousState(0);
            delete newState;
        }

        for (unsigned int i =0; i<legalMoves.size(); i++) {
            delete legalMoves[i];
        }
        //return maxValue;
        return alpha;
    }
}

Action *ComputerPlayer::getLevel4Action(const GameState& state) const {
    cerr << "INFO: Thinking.." << endl;
    //vector<ChessMove*> legalMoves = state.getLegalMovesForPlayer(color);
    GameState *temp = new GameState(state);

    leaves = 0;
    
    ChessMove *bestMove = new ChessMove(0,0,0,0); //dummy

    getValue(temp, MAX_DEPTH, color, bestMove, -1000000, 1000000);

    temp->setPreviousState(0);
    delete temp;

    return bestMove;
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
