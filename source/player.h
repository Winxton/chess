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
	std::string getColor() const;
    virtual Action *getAction(const GameState& state) const = 0;
    virtual ~Player();
};

#endif
