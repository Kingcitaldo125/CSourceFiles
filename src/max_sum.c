#include <stdio.h>
#include <stdlib.h>

// Find the largest sum of a sub-array
// from a predetermined array of ints.
// Worst Case: O(n)
// Best Case: O(n) also, because 
// the loop doesn't break early.
// there will always be 8 array entries.
int main()
{
	srand(time(NULL));
	int arr[8];// = {-4,20,10,-8,5,4,-3,0};
	int n;
	for(n=0;n<8;++n)
	{
		int j=rand()%100+1;
		int r = rand()%5;
		if(r==1)
		{j*=-1;}
		arr[n]=j;
		printf("%d ",arr[n]);
	}
	printf("\n");
	int i;
	int largest=arr[0];
	for(i=1;i<8;++i)
	{
		if(arr[i]>largest)
		{
			largest=arr[i];
			printf("Changed largest int.\n");
		}
	}
	printf("Largest: %d\n",largest);
	return 0;
}