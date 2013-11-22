#ifndef __ACTION_H__
#define __ACTION_H__

class GameState;

class Action {
public:
    virtual void apply(GameState *state) = 0;
};

#endif