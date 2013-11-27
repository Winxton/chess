#ifndef __RESIGN_H__
#define __RESIGN_H__

#include "action.h"
#include <string>
class GameState;

class Resign : public Action 
{
	std::string color; //who resigns
	virtual std::ostream& doPrint(std::ostream &out) const;
 public:
 	Resign(std::string color);
    void apply(GameState &state, bool updateGraphics=false);
};

#endif
