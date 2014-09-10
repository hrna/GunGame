#include <stdlib.h>
#include <iostream>
#include "game_engine.h"
#include "players.h"

int main(void) { 
	srand(time(NULL)); // initializing the random seed

	GameEngine engine;
	Players p;

	p.setHealth(100);

	while (p.getHealth(0) >= 1 or p.getHealth(1) >= 1)
	{
		int rTurn = rand()%2;
		if (rTurn == 0) // 0 = player, 1 = cpu
		{
			if (p.getHealth(0) >= 1) {
				p.reduceHealth(engine.doDamage(80),1);
				//std::cout << "Player health: "<< p.getHealth(0) << std::endl; 
			} else { break; }
		}
		else
		{
			if (p.getHealth(1) >= 1) {
				p.reduceHealth(engine.doDamage(80),0);
				//std::cout << "CPU health: "<< p.getHealth(1) << std::endl;
			} else { break; }
		}
	}

	if (p.getHealth(0) > p.getHealth(1))
	{
		std::cout << "PLAYER WINS" << std::endl;
		std::cout << "Player health: " << p.getHealth(0) << std::endl;
		std::cout << "CPU health: " << p.getHealth(1) << std::endl;
	}
	else if (p.getHealth(1) > p.getHealth(0))
	{
		std::cout << "CPU WINS" << std::endl;
		std::cout << "Player health: " << p.getHealth(0) << std::endl;
		std::cout << "CPU health: " << p.getHealth(1) << std::endl;
	}
	else 
	{
		std::cout << "What just happened?" << std::endl;
		std::cout << "Player health: " << p.getHealth(0) << std::endl;
		std::cout << "CPU health: " << p.getHealth(1) << std::endl;
	}
	return(0); 

}