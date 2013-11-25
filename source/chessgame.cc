#include "chessgame.h"
#include "gamestate.h"
#include "player.h"
#include "action.h"
using namespace std;

ChessGame::ChessGame (
		   GameState* state,
           Player* whitePlayer,
           Player* blackPlayer): 
           currentState(state), 
           whitePlayer(whitePlayer), 
           blackPlayer(blackPlayer) {}

void ChessGame::doTurn() {

}

void ChessGame::start() {
	while (!currentState->isGameEnded()) {

		Action *action;
		if (currentState->isWhiteTurn()) {
			action = whitePlayer->getAction();
		} else {
			action = blackPlayer->getAction();
		}
		
		// copy a new state and set its "previous state pointer"
		// to the current state
		GameState *temp = new GameState(*currentState);
		temp->setPreviousState(currentState);
		// update the current state pointer
		currentState = temp;

		// apply the action to the current state
		action->apply(currentState);

		delete action;
		currentState->swapTurns();
	}
}

ChessGame::~ChessGame() {
	//deletes all the stored states
	delete currentState;
}