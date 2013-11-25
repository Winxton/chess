#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__

#include "player.h"

class HumanPlayer : public Player 
{
public:
	HumanPlayer ();
	Action *getAction ();
};

#endif