#include "chessgame.h"
#include "player.h"
#include "humanplayer.h"
#include "gamestate.h"
#include "action.h"
#include "chessmove.h"
#include "piece.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {

    Player *whitePlayer = new HumanPlayer("white");
    Player *blackPlayer = new HumanPlayer("black");
	
    GameState *state = new GameState();

    ChessGame game(state, whitePlayer, blackPlayer);
   	game.start();

    delete whitePlayer;
    delete blackPlayer;
}
