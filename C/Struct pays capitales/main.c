#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create and typedefine the structure which contain a capital and a country
struct coupleCapitalCountry
{
	char capital[20];
	char country[20];
};

int main()
{
	//create a variable list
	struct coupleCapitalCountry list[10] = { {"Paris", "France"}, {"London", "England"}, {"Rome", "Italy"}, {"Berlin", "Germany"}, {"Madrid", "Spain"}, {"Moscow", "Russia"}, {"Prague", "Czech Republic"}, {"Athens", "Greece"}, {"Budapest", "Hungary"}, {"Vienna", "Austria"} };
	//create a variable to store the user answer
	char answer[20];
	//create a variable to store the user score
	int score = 0;
	//create a variable to store the number of answered questions
	int numberOfAnsweredQuestions = 0;
	//create a variable to store the number of couples
	int numberOfCouples = 10;
	//start the loop
	for (int i = 0; i < numberOfCouples; i++)
	{
		//ask the user the capital of the country
		printf("What Country is %s the capital of ?\n", list[i].capital);
		//get the user answer
		gets(answer);
		//check if the user answer is correct
		if (strcmp(answer, list[i].capital) == 0)
		{
			//if the user answer is correct, add 1 to the score
			score++;
		}
		//add 1 to the number of answered questions
		numberOfAnsweredQuestions++;
	}
	//display the score
	printf("Your score is %d/%d\n", score, numberOfAnsweredQuestions);
	return 0;
}
