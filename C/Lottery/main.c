#include <stdio.h>
#include <stdlib.h>
//create a lottery system

int sentinelLinearSearch(int *, int, int);

int randomNumber(int, int);

int main()
{
	const int numberOfBalls = 7, smallestBallNumber = 1, biggestBallNumber = 45;
	int lottery[7] = { 0 }, i;
	srand(time(NULL));
	for (i = 0; i < numberOfBalls ; i++)
	{
		//generate a ball with randomNumber and verify it doesn't already exist with sentinelLinearSearch
		/*
		if (sentinelLinearSearch(lottery, i, randomNumber(smallestBallNumber, biggestBallNumber)) == 0)
		{
			//we go back one step in the loop which will get us back to this step again if the number is not unique
			i--;
		}
		*/
		//this does try to generate and verify a number until it is unique
		while (sentinelLinearSearch(lottery, i, randomNumber(smallestBallNumber, biggestBallNumber)) == 0);
	}
	//print the lottery numbers
	for (i = 0; i < numberOfBalls ; i++)
	{
		printf("%d ", lottery[i]);
	}
	return 0;
}

int sentinelLinearSearch(int *lottery, int actualBall, int generatedBall)
{
	//sentinel linear search
	lottery[actualBall] = generatedBall;
	int i;
	//this is a for whitout a body because we only want to check if the generatedBall is already in the lottery array
	for (i = 0; generatedBall != lottery[i]; i++);
	//try to use a while instead of the for
	/*
	while (generatedBall != lottery[i])
	{
		i++;
	}
	*/
	//it's actually slower
	//this code here is a more optimized version which return 0 or 1 with the result of the comparison
	return (i == actualBall);
}

int randomNumber(int minRandom, int maxRandom)
{
	//simple random number generator with a min and a max
	/*
	int generatedNumber = rand() % (maxRandom - minRandom + 1) + minRandom;
	return generatedNumber;
	*/
	//directly return the value whitout using a var
	return (rand() % (maxRandom - minRandom + 1) + minRandom);
}
