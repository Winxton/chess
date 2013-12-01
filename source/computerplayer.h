#ifndef __COMPUTERPLAYER_H__
#define __COMPUTERPLAYER_H__

#include "player.h"
#include <string>
#include <vector>
class Action;
class GameState;
class ChessMove;

class ComputerPlayer : public Player
{
    int level;
    Action *getLevel1Action(const GameState& state) const;
    Action *getLevel2Action(const GameState& state) const;
    Action *getLevel3Action(const GameState& state) const;
    Action *getLevel4Action(const GameState& state) const;
    
    int getValue(GameState *state, int depth, std::string color, ChessMove *&bestMove, int alpha, int beta) const;
public:
    ComputerPlayer(std::string color, int level);
    virtual Action *getAction(const GameState& state) const;
};

#endif
