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
	// player has no legal moves
    if (!currentState->hasLegalMoves(player.getColor())) 
	{
	    //player is under check
	    if ( currentState->isUnderCheck(player.getColor()) ) {
		if (player.getColor() == "white") {
			currentState->setGameEnded(GameState::BLACK_WINS_BY_CHECKMATE);
		} else {
			currentState->setGameEnded(GameState::WHITE_WINS_BY_CHECKMATE);
		}
	    }
	    // not under check -> stalemate
	    else {
		currentState->setGameEnded(GameState::STALEMATE);
	    }
	} else {

	    Action *action = player.getAction(*currentState);

	    cerr << "INFO: Apply action: " << *action << endl;

	    // apply the action to the current state
	    // AND update the graphics
	    action->apply(*currentState, true, true);

	    delete action;

	    currentState->swapTurns();
	    currentState->printBoard();
	}

	if (currentState->isGameEnded()) {
		if (currentState->getGameResult() == GameState::WHITE_WINS_BY_CHECKMATE) {
			Scoreboard::getInstance()->whiteWinsByCheckmate();
		} 
		else if (currentState->getGameResult() == GameState::BLACK_WINS_BY_CHECKMATE) {
			Scoreboard::getInstance()->blackWinsByCheckmate();
		}
		else if (currentState->getGameResult() == GameState::BLACK_RESIGNS) {
			Scoreboard::getInstance()->blackResigns();
		}
		else if (currentState->getGameResult() == GameState::WHITE_RESIGNS) {
			Scoreboard::getInstance()->whiteResigns();
		}
		else if (currentState->getGameResult() == GameState::STALEMATE) { //stalemate
			Scoreboard::getInstance()->stalemate();
		}
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
