#include <vector>
#include "gamestate.h"
#include "square.h"
#include "piece.h"
#include "chessmove.h"
#include "piecefactory.h"
#include <iostream>
#include "window.h"
using namespace std;

GameState::GameState(Xwindow *w, bool enterSetupMode): w(w), previousState(0), whiteTurn(true), gameEnded(false) {
    setSquareNumberings();
    if (enterSetupMode) {
        doSetupMode();
    }
    else 
    {
        initializeDefault();
    }
}

bool GameState::isValidSetupState() const {
    /* 
    conditions:
    - one white king, one black king
    - no pawns on first or last row of board
    - neither king is in check
    */
    
    //kings exist
    bool whiteKingExists = false;
	bool blackKingExists = false;
	for (int x = 0; x<8; x++)
    {
		for (int y = 0; y<8; y++){

			if (whiteKingExists == true &&
				chessboard[x][y].hasPiece() &&
				chessboard[x][y].getPiece()->getCharRepr() == 'K') {
				return false;
			}
			if (blackKingExists == true &&
				chessboard[x][y].hasPiece() &&
				chessboard[x][y].getPiece()->getCharRepr() == 'k') {
				return false;
			}
			if (chessboard[x][y].hasPiece() &&
				chessboard[x][y].getPiece()->getCharRepr() == 'K') {
				whiteKingExists = true;
			}
			if (chessboard[x][y].hasPiece() &&
				chessboard[x][y].getPiece()->getCharRepr() == 'k') {
				blackKingExists = true;
			}
            
            //pawns on first or last row
			if ((y == 0 || y == 7) &&
				chessboard[x][y].hasPiece() &&
				(chessboard[x][y].getPiece()->getCharRepr() == 'p' ||
				chessboard[x][y].getPiece()->getCharRepr() == 'P')) {
				return false;
			}
		}
	}
    
	if (! (blackKingExists && whiteKingExists))
		return false;
    
    //neither king is in check
    if (isUnderCheck("white") || isUnderCheck("black"))
        return false;

    return true;
}

void GameState::doSetupMode() {
    cerr << "INFO: entered setup mode" << endl;
    bool getCommands = true;

    while (getCommands) {

        string cmd;
        cin >> cmd;

        // add a piece
        if (cmd == "+") 
        {
            string piece, location;
            cin >> piece;
            cin >> location;
            if (location.length() != 2) continue;

            int x = location[0]-'a';
            int y = location[1]-'1';
            Piece *p = PieceFactory::getInstance()->createPiece(piece);

            if (isInsideBoard(x,y) && p != 0) {
                //set piece AND update graphics
                chessboard[x][y].setPiece(p, true);
            }
        }
        else if (cmd == "-") 
        {
            string location;
            cin >> location;
            if (location.length() != 2) continue;

            int x = location[0]-'a';
            int y = location[1]-'1';

            if (isInsideBoard(x,y)) {
                //remove piece AND update graphics
                chessboard[x][y].removePiece(true);
            }

        } else if (cmd == "=") 
        {
            string color;
            cin >> color;
            //if the current turn is a different color, swap the turns
            if ( (color == "white" && !isWhiteTurn())
                || (color == "black" && isWhiteTurn()) ) {
                cerr << "INFO: Turns swapped." << endl;
                swapTurns();
            }
        } 
        else if (cmd == "done") 
        {
            if (isValidSetupState()) {
                cerr << "INFO: GOOD SETUP." << endl;
                getCommands = false;
            } else {
                cerr << "INFO: BAD SETUP." << endl;
            }
        } 
        else 
        {
            cerr << "ERROR: Invalid Command!" << endl;
        }
    }
}

void GameState::setSquareNumberings() {
    for (int i =0; i< 8; i++) {
        for (int j=0; j< 8; j++) {
            chessboard[i][j].setCoords(i,j,w);
        }
    }
}

void GameState::initializeDefault() {
    //initialize the original configuration of the board.
	PieceFactory *p = PieceFactory::getInstance();
	for (int i = 0; i<8;i++){
		this->chessboard[i][1].setPiece(p->createPiece("P"));
		this->chessboard[i][6].setPiece(p->createPiece("p"));
	}
	this->chessboard[0][0].setPiece(p->createPiece("R"));
	this->chessboard[7][0].setPiece(p->createPiece("R"));
	this->chessboard[0][7].setPiece(p->createPiece("r"));
	this->chessboard[7][7].setPiece(p->createPiece("r"));
	this->chessboard[1][0].setPiece(p->createPiece("N"));
	this->chessboard[6][0].setPiece(p->createPiece("N"));
	this->chessboard[1][7].setPiece(p->createPiece("n"));
	this->chessboard[6][7].setPiece(p->createPiece("n"));
	this->chessboard[2][0].setPiece(p->createPiece("B"));
	this->chessboard[5][0].setPiece(p->createPiece("B"));
	this->chessboard[2][7].setPiece(p->createPiece("b"));
	this->chessboard[5][7].setPiece(p->createPiece("b"));
	this->chessboard[3][0].setPiece(p->createPiece("Q"));
	this->chessboard[4][0].setPiece(p->createPiece("K"));
	this->chessboard[3][7].setPiece(p->createPiece("q"));
	this->chessboard[4][7].setPiece(p->createPiece("k"));
}

void GameState::swapTurns() {
    whiteTurn = !whiteTurn;
}

bool GameState::isGameEnded() const {
    return gameEnded;
}

bool GameState::isWhiteTurn() const {
    return whiteTurn;
}

void GameState::setGameEnded(int result) {
    gameResult = result;
    gameEnded = true;
}

int GameState::getGameResult() const {
    return gameResult;
}

vector<ChessMove*> GameState::getPossibleMovesForPlayer (string color) const {
    vector<ChessMove *> allMoves;
    for (int i =0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (getPieceColor(i,j) == color) {
                vector<ChessMove *> pieceMoves = getPieceAt(i,j)->getPossibleMoves(this);
                //append to allMoves
                for (unsigned int k =0; k<pieceMoves.size(); k++) {
                    allMoves.push_back(pieceMoves[k]);
                }
            }
        }
    }
    return allMoves;
}

vector<ChessMove*> GameState::getLegalMovesForPlayer (string color) const {

    vector<ChessMove*> possibleMoves = getPossibleMovesForPlayer(color);

    vector<ChessMove*> legalMoves;

    for (unsigned int i=0; i<possibleMoves.size(); i++) {
        //create a TEMPORARY state and apply the move to it
        GameState temp = *this;
        possibleMoves[i]->apply(temp);
        //filter moves that do not put the king under check
        if (!temp.isUnderCheck(color)) {
            legalMoves.push_back(new ChessMove(*possibleMoves[i]));
        }
        temp.setPreviousState(0); //important! otherwise will delete all the previous state

    }
    //delete possible moves
    for (unsigned int idx=0; idx<possibleMoves.size(); idx++) {
        delete possibleMoves[idx];
    }

    return legalMoves;
}


bool GameState::hasLegalMoves(string color) const {
    vector<ChessMove*> legalMoves = getLegalMovesForPlayer(color);
    unsigned int numMoves = legalMoves.size();
    for (unsigned int i =0; i< numMoves; i++) {
        delete legalMoves[i];
    }

    return (numMoves > 0);
}

bool GameState::isUnderCheck (string color) const {
    // check if the opposite colour can attack the king

    // find location of king
    // TODO create function for function the location of a piece
    int kingx = -1;
    int kingy = -1;
    for (int x =0; x<8; x++) {
        for (int y=0; y<8; y++) {
            if (getPieceColor(x,y)==color
                && getPieceType(x,y)==Piece::KING) {
                kingx = x;
                kingy = y;
            }
        }
    }
    
    string oppositeColor = color == "white" ? "black" : "white";
    vector<ChessMove*> possibleMoves = getPossibleMovesForPlayer(oppositeColor);
    bool kingUnderCheck = false;

    //check if king is being attacked
    for (unsigned int idx=0; idx<possibleMoves.size(); idx++) {
        if (possibleMoves[idx]->hasSameDestination(kingx, kingy))
            kingUnderCheck = true;
        delete possibleMoves[idx];
    }
    
    return kingUnderCheck;
}

bool GameState::isInsideBoard(int xCord, int yCord) const {
    return (xCord >= 0 && xCord <= 7
            && yCord >= 0 && yCord <= 7);
}

const Piece *GameState::getPieceAt(int xCord, int yCord) const {
    if (!isInsideBoard(xCord, yCord)) {
        return 0; // out of bounds
    } else {
        return chessboard[xCord][yCord].getPiece();
    }
}

bool GameState::hasPieceAt(int xCord, int yCord) const {
	if (getPieceAt(xCord,yCord) == 0)
		return false;
	return true;
}

string GameState::getPieceColor(int xCord, int yCord) const {
    if (hasPieceAt(xCord, yCord))
        return getPieceAt(xCord,yCord)->getColor();
    return "";
}

bool GameState::hasPieceOfOppositeColor(string color,int xCord, int yCord) const {
    string oppositeColor = color == "white" ? "black" : "white"; 
	return (getPieceColor(xCord, yCord) == oppositeColor);
}



int GameState::getPieceType(int xCord, int yCord) const {
	if (this->hasPieceAt(xCord,yCord)) {
		char temp = this->getPieceAt(xCord,yCord)->getCharRepr();
		if (temp == 'p' || temp == 'P')
			return Piece::PAWN;
		else if (temp == 'r' || temp == 'R')
			return Piece::ROOK;
		else if (temp == 'n' || temp == 'N')
			return Piece::KNIGHT;
		else if (temp == 'b' || temp == 'B')
			return Piece::BISHOP;
		else if (temp == 'q' || temp == 'Q')
			return Piece::QUEEN;
		else
			return Piece::KING;
	} else {
        return -1; //invalid
    }
}

void GameState::setPreviousState(GameState *state) {
    previousState = state;
}

GameState *GameState::getPreviousState() const{
    return previousState;
}

void GameState::printBoard() const {
    for (int row = 7; row >= 0; row--) {
        cout << row+1 << " ";
        for (int col = 0; col <=7; col ++) {
            cout << chessboard[col][row];
        }
        cout << endl;
    }
    cout << endl;
    cout << "  ";
    for (int i =0; i<8; i++) {
        cout << (char)('a'+i);
    }
    cout << endl;
    if (isUnderCheck("white")) {
        cout << "White is in check." << endl;
    }
    if (isUnderCheck("black")) {
        cout << "Black is in check." << endl;
    }
}

void GameState::drawState() const {
    //temp
    w->clearBoardBackground();
    w->setBoardBackground();
    
    string temp;
    /*
    for (int row = 7; row >= 0; row--) {
        for (int col = 0; col <=7; col ++) {
            if (chessboard[col][row].hasPiece()){
                temp = string(1,chessboard[col][row].getPiece()->getCharRepr());
                w->putPiece(col,row,temp);
            }
        }
    }
    */
    for (int row = 0; row <= 7; row++) {
        for (int col = 0; col <=7; col ++) {
            if (chessboard[row][col].hasPiece()){
                temp = string(1,chessboard[row][col].getPiece()->getCharRepr());
                w->putPiece(row,col,temp);
            }
        }
    }
}

GameState::~GameState() {
    delete previousState;
}
