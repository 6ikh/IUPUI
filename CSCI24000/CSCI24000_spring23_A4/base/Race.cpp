#include <iostream>
#include <cstdlib>
#include "Race.h"
const int TRACK = 14; 

Race::Race() {
    raceKeepGoing = true;
}

void Race::number() {
    for (int i = 0; i < HORSES; i++) {
        for (int j = 0; j < horseRace.getPosition(i) & j <= TRACK; j++) {
		std::cout << ".";
        }
        if (horseRace.getPosition(i) <= TRACK) {
		std::cout << i;
        }
        for (int j = horseRace.getPosition(i); j < TRACK; j++) {
		std::cout << ".";
        }
	std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Race::checkWinner() {
    int winner = 0;
    for (int i = 0; i < HORSES ; i++) {
        if (horseRace.getPosition(i) > horseRace.getPosition(winner)) {
            winner = i;
        }
    }

    if (horseRace.getPosition(winner) > TRACK) {
	    std::cout << "Horse " << winner << " wins!" << std::endl;
	    raceKeepGoing = false;
    }
}


void Race::runRace() {
    int seed;
    std::cout << "Please enter a random seed: "; std::cin >> seed;
    srand(seed);

    while (raceKeepGoing) {
        horseRace.advance();
        number();
        checkWinner();
    }
}

