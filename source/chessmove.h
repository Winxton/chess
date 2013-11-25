#ifndef __CHESSMOVE_H__
#define __CHESSMOVE_H__

#include "action.h"
#include <iostream>

class ChessMove: public Action {
protected:
	int xCordSrc, yCordSrc, xCordDest, yCordDest;
	virtual std::ostream& doPrint(std::ostream &out) const;
public:
	ChessMove(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest);
	virtual void apply (GameState &state);
	virtual ~ChessMove();
	//friend std::ostream& operator<<(std::ostream &out, const ChessMove &s);
	bool operator==(const ChessMove &other);
};

#endif