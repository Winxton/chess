#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include <vector>
#include <string>
#include "square.h"
#include "window.h"

class ChessMove;
class Piece;

class GameState 
{
    // All Actions are friends of GameState
    // since modifying the state should not be available
    // to the public
    friend class ChessMove;
    friend class Castle;
    friend class EnPassent;
    friend class Promotion;
    friend class Resign;

    GameState *previousState;
    Square chessboard[8][8];

    bool whiteTurn;
    bool gameEnded;
    void setSquareNumberings();
    
    //moves a piece from a source to a destination
    void movePiece(int xCordSrc, int yCordSrc, int xCordDest, int yCordDest);
public:
    
    GameState();
    
    // initializes a default board
    void initializeDefault ();
    
    //swaps the turns
    void swapTurns();

    bool isGameEnded() const;

    bool isWhiteTurn() const;

    void setGameEnded();

    // returns list of possible moves without checking if the king is in check after making the move
    std::vector<ChessMove*> getPossibleMovesForPlayer (std::string color) const;
    
    // returns vector of legal moves
    std::vector<ChessMove*> getLegalMovesForPlayer (std::string color) const;

    bool hasLegalMoves(std::string color) const;

    // checks whether a player's king is in check
    bool isUnderCheck (std::string color) const;

    //whether a coordinate is within the bounds of the chess board
    bool isInsideBoard(int xCord, int yCord) const;
	
	bool hasPieceAt(int xCord, int yCord) const;

    std::string getPieceColor(int xCord, int yCord) const;

    bool hasPieceOfOppositeColor(std::string color,int xCord, int yCord) const;

    const Piece *getPieceAt(int xCord, int yCord) const;
	
	std::string getPieceType(int xCord, int yCord) const;
    
    void setPreviousState(GameState *state);

    GameState *getPreviousState() const;
	
    // print the chess board
    void printBoard () const;
	
	void printGraphics(Xwindow* w) const;

    ~GameState();
};

#endif
