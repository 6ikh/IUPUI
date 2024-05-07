#include <iostream> 
#include <cstdlib>
using namespace std;
int horses[]= {0,0,0,0,0};
bool raceKeepGoing = true; 

const int TRACK =15;
const int HORSES =5; 


void number() {
    for (int i = 0; i < HORSES; i++) {
        for (int j = 0; j < horses[i]; j++) {
            std::cout << ".";
        }
        std::cout << i; 
        for (int j = horses[i]; j < TRACK; j++) {
            std::cout << ".";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void advance() {
    for (int i = 0; i < HORSES; i++) {
        int coinflip = rand() % 2; 
        if (coinflip == 1) {
            horses[i]++;
        }
    }
}

void checkwinner() {
    int winner = 0;
    for (int i = 0; i < HORSES ; i++) {
        if (horses[i] > 15) {
            winner = i;
	    std::cout << "Horse " << winner << " wins!" << std::endl; raceKeepGoing = false;
	}
    }
}
int main() {
    int (seed);
    std::printf("Please enter a random seed: "); std::cin >> seed;
    srand(seed);

    while (raceKeepGoing) {
        advance();
        number();
        checkwinner();
    }

    return 0;
}
