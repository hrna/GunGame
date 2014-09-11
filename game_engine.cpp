#include <iostream>
#include <stdlib.h>
#include "game_engine.h"
#include "players.h"


int GameEngine::doDamage(int accuracy) {

    random_hit = rand()%100;
    if (random_hit <= accuracy) {
        if (random_hit <= 20) { return 15; } //leg hit
        if (random_hit > 20 && random_hit <= 40) { return 0; } //Missed shot
        if (random_hit > 40 && random_hit <= 60) { return 15; } //Arm hit
        if (random_hit > 60 && random_hit <= 95) { return 30; }  //Torso hit
        if (random_hit > 95 && random_hit <= 100) { return 100; } //Headshot
    } else {
        return 0;
    }
    return 0;
}

int GameEngine::battle(int playeraccu, int cpuaccu)
{
    srand(time(NULL)); // initializing the random seed
    Players p;

    p.setHealth(100);

    while (rollOn = true)
    {
        rTurn = rand()%2;
        if (p.getHealth(0) <= 0) { 
            rollOn = false; // Propably not needed?
            std::cout << "=============================" << std::endl;
            std::cout << "Player is dead" << std::endl; 
            std::cout << "=============================" << std::endl;
            break;
        }
        else if (p.getHealth(1) <= 0) {
            rollOn = false; // Propably not needed?
            std::cout << "=============================" << std::endl;
            std::cout << "Cpu is dead" << std::endl; 
            std::cout << "=============================" << std::endl;
            break;
        }

        if (rTurn == 0) // 0 = player, 1 = cpu
        {
            if (p.getHealth(0) > 1) {
                damage = this->doDamage(playeraccu);
                p.reduceHealth(damage,1);
                //std::cout << "Player did damage: "<< damage << std::endl; 
            } else { break; }
        }
        else
        {
            if (p.getHealth(1) > 1) {
                damage = this->doDamage(cpuaccu);
                p.reduceHealth(damage,0);
                //std::cout << "CPU did damage: "<< damage << std::endl;
            } else { break; }
        }
    }
    
    if (p.getHealth(0) > p.getHealth(1))
    {
        std::cout << "PLAYER WINS" << std::endl;
        std::cout << "Player health: " << p.getHealth(0) << std::endl;
        std::cout << "CPU health: " << p.getHealth(1) << std::endl;
        this->winner = 0;
    }
    else if (p.getHealth(1) > p.getHealth(0))
    {
        std::cout << "CPU WINS" << std::endl;
        std::cout << "Player health: " << p.getHealth(0) << std::endl;
        std::cout << "CPU health: " << p.getHealth(1) << std::endl;
        this->winner = 1;
    }
    else 
    {
        std::cout << "What just happened?" << std::endl;
        std::cout << "Player health: " << p.getHealth(0) << std::endl;
        std::cout << "CPU health: " << p.getHealth(1) << std::endl;
    }
}

int GameEngine::placeBets()
{
    std::cout << "who will win? (0/1): ";
    std::cin >> this->whoWin;
}

int GameEngine::checkBets()
{
    if (this->whoWin == this->winner)
    {
        std::cout << "------------------------" << std::endl;
        std::cout << "You have won the bet!!!!" << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    else
    {
        std::cout << "------------------------" << std::endl;
        std::cout << "You have lost the bet :(" << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}