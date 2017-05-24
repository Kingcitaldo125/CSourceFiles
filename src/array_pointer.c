#include <stdio.h>
#include <stdlib.h>

int* reversal(int* arrayS, int sze);

int main()
{
	int arrs[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	
	printf("Original Array:\n");
	for (i=0; i<10; ++i)
	{
		printf("%d\n", arrs[i]);
	}
	
	int* tst;
	
	tst = reversal(arrs, 10);
	
	printf("Reversed Array:\n");
	for (i=0; i<10; ++i)
	{
		printf("%d\n", tst[i]);
	}
	
	return 0;
}

int* reversal(int* arrayS, int sze)
{
	int i,j;
	int* arrayX = malloc(sizeof *arrayX);
	
	j=0;
	
	for(i=sze-1; i>=0; --i)
	{
		arrayX[j] = arrayS[i];
		j++;
	}
	
	return arrayX;
	
}