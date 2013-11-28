#include "humanplayer.h"
#include "action.h"
#include "undo.h"
#include "chessmove.h"
#include "castle.h"
#include "enpassant.h"
#include "resign.h"
#include "gamestate.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

HumanPlayer::HumanPlayer(string color): Player(color) {}

Action *HumanPlayer::getAction(const GameState &state) const {
	
	vector<ChessMove*> legalmoves = state.getLegalMovesForPlayer(color);

	for (unsigned int i =0; i<legalmoves.size(); i++) {
		cout << *legalmoves[i] << endl;
	}

	bool validActionGiven = false;

	Action *action = 0;
	string cmd;

	while (!(validActionGiven)) 
	{
		cin >> cmd;

		if (cmd == "move") 
		{
			string src, dest;
			cin >> src >> dest;
			
			//check validity of input
			if (src.length() == 2 && dest.length() == 2) 
			{
				int srcX = (src[0]-'a');
				int srcY = (src[1]-'1');
				int destX = (dest[0]-'a');
				int destY = (dest[1]-'1');
				if (state.isInsideBoard(srcX, srcY)
					&& state.isInsideBoard(destX, destY)) 
				{
					action = new ChessMove(srcX, srcY, destX, destY);
						
					//check if it's a valid action
					for (unsigned int i =0; i<legalmoves.size(); i++) {
						if (*legalmoves[i] == *(static_cast<ChessMove*>(action))) {
							validActionGiven = true;
							if (legalmoves[i]->getSpecial() == "castle")
								action = new Castle(srcX, srcY, destX, destY);
							if (legalmoves[i]->getSpecial() == "enpassant")
								action = new EnPassant(srcX, srcY, destX, destY);
						}
					}
				}
			}

			if (!validActionGiven) cerr << "Not a Legal Move." << endl;

		} 
		else if (cmd == "resign") 
		{
			action = new Resign(color);
			validActionGiven = true;

		}
		else if (cmd == "undo") 
		{
			if (! state.getPreviousState() == 0) {
				action = new Undo();
				validActionGiven = true;
			}
		}
		else 
		{
			cerr << "invalid command" << endl;
		}
	}

	for (unsigned int i =0; i<legalmoves.size(); i++) {
		delete legalmoves[i];
	}

	return action;
}
