#include <stdlib.h>
#include <iostream>
#include "game_engine.h"


void initialize()
{
	GameEngine engine;
	bool fight = true;
	char goOn;
	while (fight)
	{
		engine.battle(100,100);
		std::cout << "continue? (y/n)" << std::endl;
		std::cin >> goOn;
		if (goOn == 'y') { }
		else { fight = false; }
	}
}

int main(void) { 
	initialize();
}