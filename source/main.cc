#include "chessgame.h"
#include "player.h"
#include "humanplayer.h"
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {

    Player *whitePlayer = new HumanPlayer();
    Player *blackPlayer = new HumanPlayer();

    GameState *state = new GameState();
    state->printBoard();

    //ChessGame game(state, whitePlayer, blackPlayer);
    //cout << state->getPreviousState() << endl;

    //copy cons
    GameState *temp = new GameState(*state);
    temp->setPreviousState(state);
    state = temp;

    state->printBoard();

    //copy cons again
    temp = new GameState(*state);
    temp->setPreviousState(state);
    state = temp;

    delete state;

    delete whitePlayer;
    delete blackPlayer;
}
