#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	int j;
	int tns = 0;
	
	srand(time(NULL));
	
	i = (rand() % 100) + 1;
	
	//printf("%d\n", i);
	
	int flag = 0;
	
	while (tns < 5)
	{
		printf("Guess the number between 1 and 100.\n");
		scanf("%d", &j);
		
		if (i == j)
		{
			printf("You Guessed Right!\n");
			flag = 1;
			break;
		}
		else if (i > j)
		{
			printf("Higher!\n");
			tns++;
		}
		else
		{
			printf("Lower!\n");
			tns++;
		}
	}
	
	flag == 0 ? printf("You Lose.\n") : printf("You Win!\n");
	
	return 0;
}