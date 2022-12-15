# Prisoners-Dilemma

You are locked in a tower of a Medieval castle with three fellow captives (i.e., there are four captured persons in total), 
each in an isolated cell with no opportunity to communicate. The guards have decided to give you all a single chance for immediate release.
They invite you and your three fellow captives to partake in a game of chance.

This is the prisoners dilemma and for this project I wrote programs in C++ to find the probability the prisoners would be released in a number of 
different scenarios for games of chance.



Every solution that flips a coin does this by generating a random number between 1 and 2, tails is either 1 or 2.

Every solution that rolls a die does this by generating a random number between 1 and 6

Every solution finds the probability of release in a scenario by keeping track of the number of times prisoners were released in a simulation and dividing that by
how many simulations were run

Every solution is run x number of times by encasing the program in a while loop that will run x number of times. I used 1000.

Scenario 1
Each captive will be given a fair six-sided die, which they must roll. If the sum of the rolls is at least 8, then you will all be released without question,
but if the total of the rolls is less than 8, you will all remain imprisoned in the castle tower for the rest of your days. 

Scenario 2
Each captive will be given a fair coin, which they then must flip. If all flipped coins come up tails, you will all be released without question, but 
if any of the flipped coins show heads, you will all remain imprisoned in the castle tower for the rest of your days.

Scenario 3
Each captive will be given a fair coin, which they then must flip. If any flipped coin comes up heads, then the corresponding prisoner must roll
a fair six-sided die. If no prisoner rolls the die and exceeds a 1 then you will all be released without question, but if any of the prisoners rolls
a number larger than 1, you will all remain imprisoned in the castle tower for the rest of your days.

Scenario 4
Analyse scenario (1), but now each prisoner may choose to roll or simply hand the die back to the guard. If the total of the rolls exceeds 8, everyone 
is set free, otherwise you are doomed to the castle tower

Scenario 5
Analyse scenario (2), but each prisoner may choose to flip or simply return the coin. If all flipped coins result in tails then everyone goes free, but 
if anyone flips heads (or nobody flips at all) then everyone is doomed to the castle tower. 

Scenario 6
Analyse scenario (3), but the prisoners may choose to flip or simply return the coin. Everyone remains captive if nobody flips or if any roll exceeds 1.
Otherwise, everyone goes free. 

