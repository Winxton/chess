#include "chessgame.h"
#include "gamestate.h"
#include "player.h"
#include "action.h"
#include "scoreboard.h"
using namespace std;

ChessGame::ChessGame (
		   GameState* state,
           Player* whitePlayer,
           Player* blackPlayer): 
           currentState(state),
           whitePlayer(whitePlayer), 
           blackPlayer(blackPlayer) {}

void ChessGame::doTurn(const Player &player) {

	Action *action = 0;

	// check for stalemate
	if ( !currentState->isUnderCheck(player.getColor())
		&& !currentState->hasLegalMoves(player.getColor()) ) {
		// handle stalemate!
		cout << "stalemate" << endl;
		currentState->setGameEnded();
	}
	// player cannot move -> lost
	else if (!currentState->hasLegalMoves(player.getColor())) 
	{
		currentState->setGameEnded();
		
		if (player.getColor() == "white") {
			Scoreboard::getInstance()->blackWins();
		} else {
			Scoreboard::getInstance()->whiteWins();
		}
	}
	else 
	{
		action = player.getAction(*currentState);
	}

	if (!currentState->isGameEnded()) {

		cout << "Apply action: " << *action << endl;

		// copy a new state and set its
		// "previous state pointer" to the current state
		GameState *temp = new GameState(*currentState);
		temp->setPreviousState(currentState);
		// update the current state pointer
		currentState = temp;
		// apply the action to the current state
		// AND update the graphics
		action->apply(*currentState, true);
		
		delete action;

		currentState->swapTurns();
	}
}

void ChessGame::start() {
	currentState->drawState();
	while (!currentState->isGameEnded()) {
		if (currentState->isWhiteTurn()) {
			cout << "White Player's Turn" << endl;
			doTurn(*whitePlayer);
		} else {
			cout << "Black Player's Turn" << endl;
			doTurn(*blackPlayer);
		}
	}
}

ChessGame::~ChessGame() {
	//deletes all the stored states
	delete currentState;
}