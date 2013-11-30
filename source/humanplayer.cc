#include "humanplayer.h"
#include "action.h"
#include "undo.h"
#include "chessmove.h"
#include "castle.h"
#include "enpassant.h"
#include "promotion.h"
#include "resign.h"
#include "gamestate.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

HumanPlayer::HumanPlayer(string color): Player(color) {}

Action *HumanPlayer::getAction(const GameState &state) const {
	
	vector<ChessMove*> possibleMoves = state.getPossibleMovesForPlayer(color);

	for (unsigned int i =0; i<possibleMoves.size(); i++) {
		cout << *possibleMoves[i] << endl;
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
					for (unsigned int i =0; i<possibleMoves.size(); i++) 
					{
						if (*possibleMoves[i] == *(static_cast<ChessMove*>(action))) 
						{
							if (possibleMoves[i]->getSpecial() == "castle") 
							{
								delete action;
								action = new Castle(srcX, srcY, destX, destY);
							}
							if (possibleMoves[i]->getSpecial() == "enpassant") 
							{
								delete action;
								action = new EnPassant(srcX, srcY, destX, destY);
							}
							if (possibleMoves[i]->getSpecial() == "promotion") 
							{
								string promoteTo = "";
								cin >> promoteTo;

								while (!(promoteTo == "Q" || promoteTo == "q" ||
										promoteTo == "R" || promoteTo == "r" ||
										promoteTo == "N" || promoteTo == "n" ||
										promoteTo == "B" || promoteTo == "b")) 
								{
										cerr << "Incorrect Promotion Piece. Please re-enter piece.";
										cin >> promoteTo;
								}
								action = new Promotion(srcX, srcY, destX, destY, promoteTo);
							}

							GameState temp(state);
							action->apply(temp);
							if (!temp.isUnderCheck(color)) validActionGiven = true;
							temp.setPreviousState(0);
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

	for (unsigned int i =0; i<possibleMoves.size(); i++) {
		delete possibleMoves[i];
	}

	return action;
}
