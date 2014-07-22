#include <stdlib.h>
#include <iostream>
#include "game_engine.h"
#include "players.h"

int main(void) { 
	srand(time(NULL)); // initializing the random seed

	GameEngine engine;
	Players p;

	for (int i = 0; i < 10; i++)
	{ 
		if (p.getHealth(0) > 0) {
			p.reduceHealth(engine.doDamage(80),0);
			std::cout << p.getHealth(0) << std::endl; // 0 = player, 1 = cpu
		} else { exit(0); }
	}
	return(0); 

}