#ifndef __CASTLE_H__
#define __CASTLE_H__
#include "chessmove.h"
#include "gamestate.h"
#include <iostream>
#include <string>

class Castle : public ChessMove 
{
	std::ostream& doPrint(std::ostream &out) const;
public:
	Castle(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest);
	void apply (GameState &state, bool updateGraphics=false, bool saveState=false);
	std::string getSpecial();
};

#endif