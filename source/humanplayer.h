#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__

#include <string>
#include "player.h"

class HumanPlayer : public Player 
{
public:
	HumanPlayer (std::string color);
	Action *getAction(const GameState &state) const;
};

#endif