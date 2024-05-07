#include <iostream>
#include <cstdlib>
#include "Horse.h"

HorseRace::HorseRace() {
    for (int i = 0; i < HORSES; i++) {
        horses[i] = 0;
    }
}

void HorseRace::advance() {
    for (int i = 0; i < HORSES; i++) {
        int coinflip = rand() % 2;
        if (coinflip == 0) {
            horses[i]++;
        }
    }
}

int HorseRace::getPosition(int horseNumber) {
    return horses[horseNumber];
}

void HorseRaceMain() {
    HorseRace race;
}











