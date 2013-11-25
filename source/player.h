#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "action.h"
#include <string>

class GameState;

class Player 
{
protected:
	std::string color;
public:
	Player(std::string color);
    virtual Action *getAction(const GameState& state) = 0;
    virtual ~Player();
};

#endif
