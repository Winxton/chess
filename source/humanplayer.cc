#include "humanplayer.h"
#include "action.h"
#include "chessmove.h"
#include "resign.h"
#include "gamestate.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

HumanPlayer::HumanPlayer(string color): Player(color) {}

Action *HumanPlayer::getAction(const GameState &state) const {
	
	cout << "LEGAL MOVES" << endl;
	vector<ChessMove*> legalmoves = state.getLegalMovesForPlayer(color);
	cout << "SIZE: " << legalmoves.size() << endl;
	for (unsigned int i =0; i<legalmoves.size(); i++) {
		cout << *legalmoves[i] << endl;
	}
	cout << "-------------------" << endl;

	bool validActionGiven = false;

	Action *action = 0;
	string cmd;

	while (!(validActionGiven)) {
		cin >> cmd;

		if (cmd == "move") {
			string src, dest;
			cin >> src >> dest;
			
			if (src.length() == 2 && dest.length() == 2) {
				int srcX = (src[0]-'a');
				int srcY = (src[1]-'1');
				int destX = (dest[0]-'a');
				int destY = (dest[1]-'1');
				if (state.isInsideBoard(srcX, srcY)
					&& state.isInsideBoard(destX, destY)) {

					validActionGiven = true;
					action = new ChessMove(srcX, srcY, destX, destY);
				}
			}

		} else if (cmd == "resign") {
			action = new Resign(color);
			validActionGiven = true;
			
		} else {
			cout << "invalid command" << endl;
		}
	}

	for (unsigned int i =0; i<legalmoves.size(); i++) {
		delete legalmoves[i];
	}

	return action;
}
