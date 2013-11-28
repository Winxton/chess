#ifndef __UNDO_H__
#define __UNDO_H__

#include <string>
#include "action.h"
#include <iostream>

class Undo: public Action {
protected:
	virtual std::ostream& doPrint(std::ostream &out) const;
public:
	virtual void apply (GameState &state, bool updateGraphics=false, bool saveState=false);
};

#endif
