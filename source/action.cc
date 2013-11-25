#include "action.h"
#include <iostream>
using namespace std;

Action::~Action() {}

std::ostream& operator<<(std::ostream &out, const Action &s) {
	return s.doPrint(out);
}
