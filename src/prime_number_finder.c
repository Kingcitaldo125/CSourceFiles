#include <stdio.h>
#include <stdlib.h>

int main()
{
	int resultantctr=0;
	int resultant[15];
	int arr[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	int i;
	for(i=0;i<15;++i)
	{
		if(arr[i]<=3)
		{
			printf("%d is a prime?\n",arr[i]);
			resultant[resultantctr]=arr[i];
			resultantctr+=1;
		}
		else if(arr[i]%2!=0&&arr[i]%3!=0)
		{
			printf("%d is a prime?\n",arr[i]);
			resultant[resultantctr]=arr[i];
			resultantctr+=1;
		}
	}
	for(i=0;i<resultantctr;++i)
	{
		printf("%d ",resultant[i]);
	}
	return 0;
}