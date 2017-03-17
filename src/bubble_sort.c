#include <stdlib.h>
#include <stdio.h>

int main()
{
	int arr[30]={5,15,1,45,6,8,23,32,17,8,20,13,65,8,4,25,43,0,3,2,4,7,9,12,14,55,1,4,9,16};
	int i,j;
	for(i=0;i<29;++i)
	{
		for(j=0;j<29-i-1;++j)
		{
			if(arr[j]>arr[j+1])
			{
				int swap;
				swap = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = swap;
			}
		}
	}
	for(i=0;i<29;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}