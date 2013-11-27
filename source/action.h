#ifndef __ACTION_H__
#define __ACTION_H__

#include <iostream>
class GameState;

class Action {
	//polymorphic: return ouput stream
	virtual std::ostream& doPrint(std::ostream&) const = 0;
public:
    virtual void apply(GameState &state, bool updateGraphics=false) = 0;
    virtual ~Action();
    friend std::ostream& operator<<(std::ostream &out, const Action &a);
};

#endif