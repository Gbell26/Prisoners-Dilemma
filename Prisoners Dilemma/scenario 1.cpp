//Gregory Bell
// Prisoners Dilemma
// scenario 1
// Each captive will be given a fair six-sided die, which they must roll. If the sum of the rolls is at least
// 8, then you will all be released without question, but if the total of the rolls is less than 8, you will
// all remain imprisoned in the castle tower for the rest of your days.


#include <iostream>
#include <stdlib.h> // srand, rand
#include <ctime> 
#include <iomanip>

using namespace std;


int main()
{
	srand(time(0));

	float numSim = 0;
	float numReleased = 0;
	float probabilityRelease;

	int die1;
	int die2;
	int die3;
	int die4;
	int totalDiceVal = 0;


	while (numSim < 1000) {

		die1 = rand() % 6 + 1;
		die2 = rand() % 6 + 1;
		die3 = rand() % 6 + 1;
		die4 = rand() % 6 + 1;
		

		totalDiceVal = die1 + die2 + die3 + die4;

		if (totalDiceVal >= 8) { numReleased += 1; }

		numSim++;

	}

	probabilityRelease = numReleased / numSim;
	cout << "Number of times prisoners released in " << numSim << " simulations was " << numReleased << endl;
	cout << "Probablity of release is %" << setprecision (2) << probabilityRelease * 100 << endl;

}
