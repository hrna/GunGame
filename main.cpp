#include <stdlib.h>
#include <iostream>
#include "game_engine.h"
#include "players.h"

int battle()
{
	srand(time(NULL)); // initializing the random seed
	GameEngine engine;
	Players p;

	p.setHealth(100);
	int damage;
	while (p.getHealth(0) >= 1 || p.getHealth(1) >= 1)
	{
		int rTurn = rand()%2;
		if (rTurn == 0) // 0 = player, 1 = cpu
		{
			if (p.getHealth(0) > 1) {
				damage = engine.doDamage(100);
				p.reduceHealth(damage,1);
				std::cout << "Player did damage: "<< damage << std::endl; 
			} else { break; }
		}
		else
		{
			if (p.getHealth(1) > 1) {
				damage = engine.doDamage(100);
				p.reduceHealth(damage,0);
				std::cout << "CPU did damage: "<< damage << std::endl;
			} else { break; }
		}
	}
	std::cout << "=============================" << std::endl;
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
}

int main(void) { 
	battle();
	char goOn;
	std::cout << "continue? (y/n)" << std::endl;
	std::cin >> goOn;
	if (goOn == 'y') { battle(); }
	else { return(0); }
}