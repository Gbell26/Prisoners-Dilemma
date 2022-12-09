//Gregory Bell
// scenario 4
// Each captive will be given a fair six-sided die, which they may roll or hand back if the sum of the rolls is at least
// 8, then you will all be released without question, but if the total of the rolls is less than 8, you will
// all remain imprisoned in the castle tower for the rest of your days.

#include <iostream>
#include <stdlib.h> // srand, rand
#include <ctime> 
#include <iomanip>

using namespace std;

int rollDie(float, float);

int main()
{
	srand(time(0));

	float numSim = 0;
	float numReleased = 0;
	float probabilityRelease;

	//Find what threshold has the greatest probability
	float greatesProbability = 0;
	float bestThreshold = 0;


	float chanceOfPlaying;

	//create for loop to fill array with as many options
	float playThreshold[100];
	float fraction = 0.00;

	for (int iteration = 0; iteration < 100; iteration++) {
		playThreshold[iteration] = fraction;
		fraction += 0.01;
	}

	int die1;
	int die2;
	int die3;
	int die4;
	int totalDiceVal = 0;

	// run simulation for different thresholds
	for (int number = 0; number < 100; number++) {


		while (numSim < 1000) {

			// Each player either rolls the dice or not
			// chanceOfPlaying decided with rand number between 0-1
			// if the chanceOfPlaying is greater than the playThreshold the prisoner will roll

			chanceOfPlaying = (float)rand() / RAND_MAX;
			die1 = rollDie(chanceOfPlaying, playThreshold[number]);

			chanceOfPlaying = (float)rand() / RAND_MAX;
			die2 = rollDie(chanceOfPlaying, playThreshold[number]);

			chanceOfPlaying = (float)rand() / RAND_MAX;
			die3 = rollDie(chanceOfPlaying, playThreshold[number]);

			chanceOfPlaying = (float)rand() / RAND_MAX;
			die4 = rollDie(chanceOfPlaying, playThreshold[number]);

			totalDiceVal = die1 + die2 + die3 + die4;

			if (totalDiceVal >= 8) { numReleased += 1; }
			
			numSim++;

		}

		probabilityRelease = numReleased / numSim;
		/*
		cout << "With the chance of a prisoner playing being " << setprecision(2) << fixed << playThreshold[number] << ":" << endl;
		cout << "Number of times prisoners released in " << numSim << " simulations was " << numReleased << endl;
		cout << "Probablity of release is %" << probabilityRelease * 100 << endl;
		cout << endl;*/

		if (probabilityRelease > greatesProbability) {
			greatesProbability = probabilityRelease;
			bestThreshold = playThreshold[number];
		}
		// reset the number of released and the number of simulations for next threshold
		numReleased = 0;
		numSim = 0;
	}
	cout << endl;
	cout << setprecision(2) << fixed;
	cout << "The best threshold is " << bestThreshold << " with a probability of release being " << greatesProbability << endl;
}
int rollDie(float chanceOfPlaying, float threshold) {

	// chanceOfPlaying decided with rand number between 0-1
	// if the chanceOfPlaying is greater than the playThreshold the prisoner will roll
	int dieVal;
	if (chanceOfPlaying > threshold) {
		dieVal = rand() % 6 + 1;
	}
	else {
		dieVal = 0;
	}

	return dieVal;
	}

