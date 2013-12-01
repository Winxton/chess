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
	
	virtual void apply (GameState &state, bool updateGraphics=false, bool saveState=false) const;

	virtual ~ChessMove();

	// returns true if this moves captures another piece
	bool capturesPiece(const GameState &state) const;

	// returns true if this move puts the opponent in check
	bool checksOpponent(const GameState &state) const;

	//returns true if this move avoids capture 
	bool avoidsCaptureAfterMove(const GameState &state) const;

	bool hasSameDestination(int xCord, int yCord) const;

	int getXCordDest() const;

	int getYCordDest() const;

	//friend std::ostream& operator<<(std::ostream &out, const ChessMove &s);
	bool operator==(const ChessMove &other);

	virtual std::string getSpecial();
};

#endif