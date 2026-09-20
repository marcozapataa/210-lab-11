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

// Function prototypes
void inputRacer(Racer *);
void displayRacer(Racer *);


int main() {
    // Dynamically allocating the outer array of structs
    Racer *roster = new Racer[NR_RACERS];

    // Input loop
    for (int i = 0; i < NR_RACERS; i++)
        inputRacer(&roster[i]);

    // Display loop
    for (int i = 0; i < NR_RACERS; i++)
        displayRacer(&roster[i]);

    // Clean up outer dynamic array
    delete [] roster;


    return 0;
}