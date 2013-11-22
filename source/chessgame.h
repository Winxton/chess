
class ChessGame 
{
public:
	ChessGame (Gamestate* state,
	           Player* whitePlayer,
	           Player* blackPlayer);
	void doTurn ();
	void start ();
};

