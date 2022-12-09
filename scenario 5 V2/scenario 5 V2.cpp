// Gregory Bell
// scenario 5
// Each captive will be given a fair coin. If all flipped coins come up tails,
//you will all be released without question, but if any of the flipped coins show heads, you will all
//remain imprisoned in the castle tower for the rest of your days.
//Prisoners can choose not to flip their coin. If nobody flips a coin then they do not get set free

//This is nearly the same as scenario 5. However I thought it would be an interesting opportunity to create a prisoner object
//with a coin flip value and use that instead. 

#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>

using namespace std;


class prisoner {
public:

    int coin;

};


int main()
{
    
    srand(time(0));

    int numberOfTails = 0;

    float numSim = 0;
    float probabilityReleased;
    float numReleased = 0;

    //Find what threshold has the greatest probability
    float greatesProbability = 0;
    float bestThreshold = 0;
    float chanceOfPlaying;

    //create for loop to fill array with as many options
    float playThreshold[100];
    float fraction = 0.00;

    prisoner prisonerArray[4];

    for (int iteration = 0; iteration < 100; iteration++) {
        playThreshold[iteration] = fraction;
        fraction += 0.01;
    }

    for (int number = 0; number < 100; number++) {
        while (numSim < 1000) {

            //First find out how many prisoners will play
            int prisonersWhoPlay = 0;
            for (int iteration = 0; iteration < 4; iteration++) {

                chanceOfPlaying = (float)rand() / RAND_MAX;
                if (chanceOfPlaying > playThreshold[number]) {
                    prisonersWhoPlay += 1;
                }
            }
            //if nobody plays you arent released
            if (prisonersWhoPlay == 0) {
                continue;
            }
            // flip coins for number who play and check # of tails
            else {
                for (int i = 0; i < prisonersWhoPlay; i++) {
                    prisonerArray[i].coin = rand() % 2 + 1;
                    if (prisonerArray[i].coin == 2) { numberOfTails += 1; }      
                }
                if (numberOfTails == prisonersWhoPlay) { numReleased += 1; }
            }
            numSim++;
            numberOfTails = 0;

        }//end of while loop

        probabilityReleased = numReleased / numSim;
        /*cout << setprecision(2) << fixed;
        cout << "For a threshold of " << playThreshold[number] << ":" << endl;
        cout << "Number of times prisoners released in " << numSim << " simulations was " << numReleased << endl;
        cout << "Probablity of release is %" << probabilityReleased * 100 << endl;*/

        //find the greatest probability and at what threshold
        if (probabilityReleased > greatesProbability) {
            greatesProbability = probabilityReleased;
            bestThreshold = playThreshold[number];
        }

        numSim = 0;
        numReleased = 0;
    }

    //print greatest probability and at what threshold
    cout << setprecision(2) << fixed;
    cout << "The best threshold is " << bestThreshold << " with a probability of release being %" << greatesProbability * 100<< endl;
}

