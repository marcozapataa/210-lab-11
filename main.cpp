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

// Function definition for inputRacer
void inputRacer(Racer * rptr) {
    static int nrRac = 1;  // tracks the racer input number across function calls
    cout << "Input data for Racer #" << nrRac << ":\n";
    cout << "Race Number: ";
    cin >> rptr->raceNumber;

    cout << "Placement: ";
    cin >> rptr->placement;

    // Dynamically allocate the inner array for lap times in the struct
    rptr->lapTimes = new double[NR_LAPS];
    for (int i = 0; i < NR_LAPS; i++) {
        cout << "Lap #" << i + 1 << " Time: ";
        cin >> rptr->lapTimes[i];
    }
    cout << endl << endl;
    nrRac++;
}