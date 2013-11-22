#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <vector>
class Action;
class Player;
class ChessMove;

class GameState 
{
public:
	GameState ();
	GameState (GameState *state);
	bool isUnderCheck (Player *p);
	void initializeDefault ();
	std::vector<ChessMove*> getPossibleMovesForPlayer (Player *p);
	std::vector<ChessMove*> getLegalMovesForPlayer (Player *p);
	void printBoard ();
};

#endif