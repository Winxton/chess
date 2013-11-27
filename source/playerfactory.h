#ifndef __PLAYERFACTORY_H__
#define __PLAYERFACTORY_H__

#include <string>
class Player;

class PlayerFactory {
	static PlayerFactory *instance;
	static void cleanup();
public:
	static PlayerFactory *getInstance();
	Player *createPlayer(std::string type, std::string color);
};

#endif