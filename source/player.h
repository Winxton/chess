#ifndef __PLAYER_H__
#define __PLAYER_H__

class Action;

class Player 
{
std::istream *source;
public:
    Action *getAction () = 0;
};

#endif
