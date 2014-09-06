#include <iostream>
#include <stdlib.h>
#include "players.h"


void Players::reduceHealth(int damage, int player)
{
	if (player == 0) { this->humanHealth -= damage; }
	else if (player == 1) { this->cpuHealth -= damage; }
	else { }
}

int Players::setHealth(int hp)
{
	this->humanHealth = hp;
	this->cpuHealth = hp;
}
int Players::getHealth(int player)
{
	if (player == 0) { return this->humanHealth; }
	else if (player == 1) { return this->cpuHealth; }
}