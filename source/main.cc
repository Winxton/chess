#include <iostream>
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
using namespace std;

int main() {
    GameState state;
    const Piece *p = state.getPieceAt(0,0);
    delete p;
}
