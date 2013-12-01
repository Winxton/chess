#ifndef __PROMOTION_H__
#define __PROMOTION_H__
#include "chessmove.h"
#include "gamestate.h"
#include <iostream>
#include <string>

class Promotion : public ChessMove 
{
	std::string promoteTo;
	std::ostream& doPrint(std::ostream &out) const;
public:
	Promotion(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest, std::string promoteTo = "Q");
	void apply (GameState &state, bool updateGraphics=false, bool saveState=false) const;
};

#endif