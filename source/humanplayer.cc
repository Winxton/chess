#include "humanplayer.h"
#include "action.h"
#include <iostream>
#include <string>
using namespace std;

HumanPlayer::HumanPlayer() {}

Action *HumanPlayer::getAction() {
	string cmd = "";

	while (!(cmd == "move" || cmd == "resign")) {
		cin >> cmd;

		if (cmd == "move") {
			string src, dest;
			cin >> src >> dest;
		} else if (cmd == "resign") {

		} else {
			cout << "invalid command" << endl;
		}	
	}

	return 0;
}
