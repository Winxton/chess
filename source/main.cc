#include <vector>
#include <iostream>
#include <cstdlib>
#include "chessgame.h"
#include "player.h"
#include "gamestate.h"
#include "piece.h"
#include "playerfactory.h"
#include "window.h"
using namespace std;

void doExit() {
	cout << "exiting ..." << endl;
}

int main() {
	atexit(doExit);

	string cmd;

	Player *whitePlayer = 0;
	Player *blackPlayer = 0;

	
	GameState *initialState = 0;
	Xwindow w;

	while (cin >> cmd) 
	{
		if (cmd == "game") 
		{
			string whitePlayerType;
			string blackPlayerType;
			cin >> whitePlayerType >> blackPlayerType;
		    Player *whitePlayer = PlayerFactory::getInstance()->createPlayer(whitePlayerType, "white");
		    Player *blackPlayer = PlayerFactory::getInstance()->createPlayer(blackPlayerType, "black");
			
			if (initialState == 0) {
		    	initialState = new GameState(&w);
			}

		    ChessGame game(initialState, whitePlayer, blackPlayer);
		   	game.start(); //will deallocate the state

		   	//game has finished, reset original parameters
		   	w.setBoardBackground();
		   	initialState = 0;
		}
		else if (cmd == "setup")
		{

			//construct a state with setup mode
			if (initialState == 0) {
				initialState = new GameState(&w, true);
			}
			else {
				initialState->doSetupMode();
			}
		} 
		else if (cmd == "quit") { 
			break;

		} else {
			cerr << "Not a valid input." << endl;
		}
	}

	//case that setupmode is entered into, but game does not start before quitting
	delete initialState; 

    delete whitePlayer;
    delete blackPlayer;
}
