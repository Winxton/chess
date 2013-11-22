#ifndef __CASTLE_H__
#define __CASTLE_H__

class Castle : public ChessMove 
{
public:
	void apply (Gamestate &state);
};

#endif