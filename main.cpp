#include <iostream>
using namespace std;

const int NR_RACERS = 3;
const int NR_LAPS = 3;

struct Racer {
    int raceNumber;
    int placement;
    double * lapTimes = nullptr;  // Inner dynamic array to track lap times

    // Destructor to auto clean memory
    ~Racer() {
        if (lapTimes)
            delete [] lapTimes;
        lapTimes = nullptr;
    }
};


int main() {


    return 0;
}