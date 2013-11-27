#include "chessgame.h"
#include "player.h"
#include "humanplayer.h"
#include "gamestate.h"
#include "action.h"
#include "chessmove.h"
#include "piece.h"
#include <vector>
#include <iostream>
#include "window.h"
using namespace std;

int main() {
    Xwindow *w = new Xwindow();

    Player *whitePlayer = new HumanPlayer("white");
    Player *blackPlayer = new HumanPlayer("black");

    GameState *state = new GameState();

    ChessGame game(state, whitePlayer, blackPlayer, w);
    game.start();
    
    delete whitePlayer;
    delete blackPlayer;
}
