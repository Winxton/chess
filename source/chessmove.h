#ifndef __CHESSMOVE_H__
#define __CHESSMOVE_H__

#include "action.h"
#include <iostream>

class ChessMove: public Action {
protected:
	int xCordSrc, yCordSrc, xCordDest, yCordDest;
public:
	ChessMove(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest);
	virtual void apply (GameState *state);
	friend std::ostream& operator<<(std::ostream &out, const ChessMove &s);
};

#endif