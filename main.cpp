#include <stdlib.h>
#include <iostream>
#include "game_engine.h"


int initialize(int playerAccuracy, int cpuAccuracy)
{
	GameEngine engine;
	bool fight = true;
	char goOn;
	while (fight)
	{
		engine.placeBets();
		engine.battle(playerAccuracy,cpuAccuracy); // player accuracy, cpu accuracy
		engine.checkBets();
		std::cout << "continue? (y/n): ";
		std::cin >> goOn;
		if (goOn != 'y') { break; }
	}
}

int main(int argc, char *argv[]) { 


	if (argc < 3 || argc > 3)
	{
		std::cout << "GOIN ON DEFAULTS" << std::endl;
		initialize(50,50);
	}
	else
	{ 
		int arg1 = atoi(argv[1]);
		int arg2 = atoi(argv[2]);
		initialize(arg1,arg2); 		
	}

}