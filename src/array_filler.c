#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t,c,ns;
	
	printf("Enter the size of the array:\n");
	scanf("%d",&ns);
	
	int arrs[ns];
	
	c=0;
	//printf("%d\n",ns);
	printf("Enter the array items:\n");
	while(1)
	{
		if(c >= ns)
			break;
		
		//printf("At:%d need %d\n",c,ns);
		scanf("%d",&t);
		arrs[c]=t;
		c++;
	}
	
	
	unsigned int j;
	printf("Array Items:\n");
	for(j=0; j<ns; ++j)
	{
		printf("%d\n",arrs[j]);
	}
	
	return 0;
}