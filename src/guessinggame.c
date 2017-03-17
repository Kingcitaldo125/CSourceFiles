#include <stdio.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	printf("I am thinking of a number...\n");
	printf("It is a number between 1 and 100.\n");
	printf("Try to guess my number:\n");
	printf("You have 6 chances to guess the right number or.. You're out!\n");
	int chances=5;
	int guess,answer;
	int tries=0;
	answer=rand()%100;
	answer+=1;
	while(1)
	{
		scanf("%d",&guess);
		if(tries==chances || guess==answer)
		{
			break;
		}
		if(guess<answer)
		{
			printf("Higher!\n");
		}
		else
		{
			printf("Lower!\n");
		}
		tries=tries+1;
	}
	if(tries==chances&&guess!=answer)
	{
		printf("Sorry... The right number was %d\n",answer);
	}
	else if(tries==chances&&guess==answer)
	{
		printf("Correct!!!\n");
		printf("The correct number was %d.\n",answer);
		printf("You got the answer in %d tries\n",tries);
	}
	else
	{
		printf("Correct!!!\n");
		printf("The correct number was %d.\n",answer);
		printf("You got the answer in %d tries\n",tries+1);
	}
	return 0;
}