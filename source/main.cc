#include <iostream>
#include "gamestate.h"
#include "chessmove.h"
#include "piece.h"
using namespace std;

int main() {
    GameState state;
    Piece *p = state.getPieceAt(0,0);
    cout << p << endl;
}
