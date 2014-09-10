#include <iostream>
#include <stdlib.h>
#include "game_engine.h"


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
}