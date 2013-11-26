#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

class Scoreboard 
{
static Scoreboard* _instance;
double white;
double black;

public:
	static Scoreboard* getInstance();
	void printScoreboard ();
	void blackWins ();
	void whiteWins ();
	void tie ();
};

#endif