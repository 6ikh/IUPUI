#define RACE_H
#define RACE_H

#include <cstdlib>
#include <iostream>
#include "Horse.h"

class Race {
    private:
        HorseRace horseRace;
        bool raceKeepGoing;
        void number();
        void checkWinner();
    public:
        Race();
        void runRace();
};

