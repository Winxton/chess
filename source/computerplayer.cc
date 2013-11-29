#include "computerplayer.h"
#include "chessmove.h"
#include "gamestate.h"
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

ComputerPlayer::ComputerPlayer(std::string color, int level): Player(color), level(level) {}

// Level 1 - random moves
Action *ComputerPlayer::getLevel1Action(const GameState& state) const {
    vector<ChessMove*> legalMoves = state.getLegalMovesForPlayer(color);
    unsigned int random = rand() % (legalMoves.size() - 1);
    ChessMove *theMove = legalMoves[random];

    for (unsigned int i =0; i<legalMoves.size(); i++) {
        if (i != random)
            delete legalMoves[i];
    }

    return theMove;
}

// Level 2
Action *ComputerPlayer::getLevel2Action(const GameState& state) const {
    return getLevel1Action(state); //temporary
}

// Level 3
Action *ComputerPlayer::getLevel3Action(const GameState& state) const {
    return getLevel1Action(state); //temporary
}

// Level 4
Action *ComputerPlayer::getLevel4Action(const GameState& state) const {
    return getLevel1Action(state); //temporary
}

Action *ComputerPlayer::getAction(const GameState& state) const {
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
