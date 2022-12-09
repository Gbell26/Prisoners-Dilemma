// Gregory Bell
// scenario 3
// Each captive will be given a fair coin, which they then must flip. If any flipped coin comes up heads,
// then the corresponding prisoner must roll a fair six - sided die.If no prisoner rolls the die and exceeds
// a 1 then you will all be released without question, but if any of the prisoners rolls a number larger
// than 1, you will all remain imprisoned in the castle tower for the rest of your days.

#include <iostream>
#include <iomanip> // set precision
#include <ctime> // time function for srand
#include <stdlib.h> // rand/srand functions

using namespace std;

int main()
{
    srand(time(0));

    int coin;
    int die;
    int loop = 0;

    bool released = true;

    float numReleased = 0;
    float probabilityReleased;
    float numSim = 0;

    //run sim 1000 times
    while (numSim < 1000) {
        
        //loop through 4 prisoners
        while (loop < 4) {

            //flip a coin           
            coin = rand() % 2 + 1;
            
            //if the coin is heads prisoner must roll dice
            if (coin == 1) {

                //roll the dice
                die = rand() % 6 + 1;
                
                //if the roll equals 1 the prisoner might be released
                if (die == 1) {
                    
                    released = true;
                
                }
                //if the roll equals > 1 they are not released
                else {
                   
                    released = false;
                
                } // end of dice roll             
            }
            else {

                //if coin flip is tails they may be released
                released = true;

            }//end of coin flip
                        
            //if someone rolled die > 1 released is false, the rest of the prisoners outcome
            //is irrelevant so skip to 4
            if (released == false) {
                
                loop = 4;
            
            }

            //if they did not roll dice or rolled a 1 loop cycles to next prisoner
            else {
            
                loop++;
            
            }
        }//end of while loop for 4 prisoners

        //reset loop to 0 so the prisoners can loop through again on the next simulation
        loop = 0;

        //after all prisoners are looped through if released still equals true numReleased increments
        if (released == true) {
            
            numReleased+=1;
        
        }

        // increments to the next simulation until 1000
        numSim++;
    }

    probabilityReleased = (numReleased / numSim) * 100;
    cout << "Number of times prisoners released in " << numSim << " simulations was " << numReleased << endl;
    cout << "Probablity of release is %" << setprecision(2) << probabilityReleased << endl;
}

