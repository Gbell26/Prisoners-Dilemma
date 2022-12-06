// Gregory Bell
// scenario 2
// Each captive will be given a fair coin, which they then must flip. If all flipped coins come up tails,
//you will all be released without question, but if any of the flipped coins show heads, you will all
//remain imprisoned in the castle tower for the rest of your days.

#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(0));

    int coin1;
    int coin2;
    int coin3;
    int coin4;

    float numSim = 0;
    float probabilityReleased;
    float numReleased = 0;

    while (numSim < 1000) {


        // randomly flip coins 1 2 3 4
        coin1 = rand() % 2 + 1;
        coin2 = rand() % 2 + 1;
        coin3 = rand() % 2 + 1;
        coin4 = rand() % 2 + 1;


        //if all coins are equal to 1 (tails) number of times prisoners are released is incremented
        if (coin1 == 2 && coin2 == 2 && coin3 == 2 && coin4 == 2) { numReleased += 1; }
        
        //increment the number of simulations to break loop at 1000
        numSim++;

   }//end of while loop

    probabilityReleased = numReleased / numSim;
    cout << "Number of times prisoners released in " << numSim << " simulations was " << numReleased << endl;
    cout << "Probablity of release is %" << setprecision(2) << probabilityReleased * 100 << endl;

}
