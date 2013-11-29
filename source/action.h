#ifndef __ACTION_H__
#define __ACTION_H__

#include <iostream>
#include <string>
class GameState;

class Action {
	//polymorphic: return ouput stream
	virtual std::ostream& doPrint(std::ostream&) const = 0;
protected:
	virtual void saveCurrentStateAsPrevious(GameState &state) const;
public:
    virtual void apply(GameState &state, bool updateGraphics=false, bool saveState=false) const = 0;
    virtual ~Action();
    friend std::ostream& operator<<(std::ostream &out, const Action &a);
};

#endif