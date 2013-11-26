#ifndef __CHESSGAME_H__
#define __CHESSGAME_H__

class Player;
class GameState;

class ChessGame
{
	GameState *currentState;
	Player *whitePlayer;
	Player *blackPlayer;
public:
	ChessGame(GameState* state,
	           Player* whitePlayer,
	           Player* blackPlayer);
	void doTurn(const Player &player);
	void start();
	~ChessGame();
};

#endif