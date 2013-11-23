#ifndef __CHESSMOVE_H__
#define __CHESSMOVE_H__

#include "action.h"

class ChessMove: public Action {
protected:
	int xCordSrc, yCordSrc, xCordDest, yCordDest;
public:
	virtual void apply (GameState *state);
};

#endif