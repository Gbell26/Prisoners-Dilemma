// Gregory Bell
// scenario 6
// Each captive will be given a fair coin. If any flipped coin comes up heads,
// then the corresponding prisoner must roll a fair six - sided die.If no prisoner rolls the die and exceeds
// a 1 then you will all be released without question, but if any of the prisoners rolls a number larger
// than 1, you will all remain imprisoned in the castle tower for the rest of your days.
// Prisoners can choose to hand coin back and not play


#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>

using namespace std;


class prisoner {
public:

    int coin;
    int die;

};


int main()
{

    srand(time(0));

    bool released = true;

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

    // an array of 4 prisoner objects
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
            //if nobody plays you arent released and it skips to the next simulation
            if (prisonersWhoPlay == 0) {
                continue;
            }


            // flip coins for number who play and check # of tails
            //iterates through the prisoner array only the number of players who decide to play
            else {
                for (int i = 0; i < prisonersWhoPlay; i++) {
                    // each prisoner rolls the flips a coin 
                    prisonerArray[i].coin = rand() % 2 + 1;
                    // if the coin is tails roll a die
                    if (prisonerArray[i].coin == 2) {
                        prisonerArray[i].die = rand() % 6 + 1;
                        // if the die is greater than 1 you arent released and it continues to the next loop
                        if (prisonerArray[i].die > 1) {
                            released = false;
                            break;
                        }
                    }
                }
                // if nobody who plays rolls a 6 then the number of released increases
                if (released == true) {
                    numReleased += 1;
                }
            }
            numSim++;
            released = true;
        }//end of while loop

        probabilityReleased = numReleased / numSim;
       /* cout << setprecision(2) << fixed;
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
    cout << "The best threshold is " << bestThreshold << " with a probability of release being %" << greatesProbability * 100 << endl;
}
