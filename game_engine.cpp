#include <iostream>
#include <stdlib.h>
#include "game_engine.h"


int GameEngine::doDamage(int accuracy) {
    int random_hit;

    random_hit = rand()%100;
    if (random_hit <= accuracy) {
        if (random_hit <= 20) { return 15; }
        if (random_hit > 20 && random_hit <= 40) { return 20; }
        if (random_hit > 40 && random_hit <= 60) { return 15; }
        if (random_hit > 60 && random_hit <= 80) { return 30; }
        if (random_hit > 80 && random_hit <= 100) { return 45; }
    } else {
        return 0;
    }
}