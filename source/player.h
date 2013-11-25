#ifndef __PLAYER_H__
#define __PLAYER_H__

class Action;

class Player 
{
public:
    virtual Action *getAction () = 0;
    virtual ~Player();
};

#endif
