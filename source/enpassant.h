#ifndef __ENPASSANT_H__
#define __ENPASSANT_H__
#include "chessmove.h"
#include "gamestate.h"
#include <iostream>
#include <string>

class EnPassant : public ChessMove
{
	std::ostream& doPrint(std::ostream &out) const;
public:
	EnPassant(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest);
	void apply (GameState &state,bool updateGraphics=false, bool saveState=false) const ;
};

#endif
