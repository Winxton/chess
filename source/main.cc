#include "chessgame.h"
#include "player.h"
#include "humanplayer.h"
#include "gamestate.h"
#include "action.h"
#include "chessmove.h"
#include "piece.h"
#include "playerfactory.h"
#include <vector>
#include <iostream>
#include "window.h"
using namespace std;

void setup(GameState &state, Xwindow &w) {
	string cmd;
	cin >> cmd;
	// add a piece
	if (cmd == "+") {
		string piece, location;
		cin >> piece;
		cin >> location;

	} else if (cmd == "-") {
		string location;
		cin >> location;

	} else if (cmd == "=") {
		string color;
		cin >> color;
		//if the current turn is a different color, swap the turns
		if ( (color == "white" && !state.isWhiteTurn())
			|| (color == "black" && state.isWhiteTurn()) ) {
			state.swapTurns();
		}
	}
}

int main() {
	
	string cmd;

	Player *whitePlayer = 0;
	Player *blackPlayer = 0;

	while (cin >> cmd) {
		if (cmd == "game") {

			string whitePlayerType;
			string blackPlayerType;
			cin >> whitePlayerType >> blackPlayerType;
		    Player *whitePlayer = PlayerFactory::getInstance()->createPlayer(whitePlayerType, "white");
		    Player *blackPlayer = PlayerFactory::getInstance()->createPlayer(blackPlayerType, "black");
			
			Xwindow *w = new Xwindow;
		    GameState *state = new GameState();

		    ChessGame game(state, whitePlayer, blackPlayer, w);
		   	game.start();

		   	delete w;

		} else if (cmd == "quit") { 
			break;

		} else {
			cout << "Not a valid input." << endl;
		}
	}

    delete whitePlayer;
    delete blackPlayer;
}
