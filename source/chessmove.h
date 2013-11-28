#ifndef __CHESSMOVE_H__
#define __CHESSMOVE_H__

#include <string>
#include "action.h"
#include <iostream>

class ChessMove: public Action {
protected:
	std::string special;
	int xCordSrc, yCordSrc, xCordDest, yCordDest;
	virtual std::ostream& doPrint(std::ostream &out) const;
public:
	ChessMove(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest);
	virtual void apply (GameState &state, bool updateGraphics=false, bool saveState=false);
	virtual ~ChessMove();
	bool hasSameDestination(int xCord, int yCord) const;
	//friend std::ostream& operator<<(std::ostream &out, const ChessMove &s);
	bool operator==(const ChessMove &other);
	virtual std::string getSpecial();
};

#endif