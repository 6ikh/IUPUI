#include <iostream>
#define HORSES 5
class HorseRace {
    private:
        int horses[HORSES];
    public:
        HorseRace();
        void advance();
        int getPosition(int horseNumber);
};

