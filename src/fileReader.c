//IMAGE READER PAUL ARELT
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	if(argc==1)
	{
		FILE* ff;
		char argg[30];
		printf("Enter the filename you wish to read\n");
		scanf("%29s",&argg);
		ff=fopen(argg,"r");
		if(ff==NULL)
		{
			printf("CANNOT OPEN\n");
			return -1;
		}
		
		printf("\nreading\n");
		int c;
		do
		{
			c=fgetc(ff);
			printf("%c",c);
		}while(c!=EOF);
		
		printf("\ndone\n");
		fclose(ff);
	}
	else
	{
		FILE* myf;
		myf=fopen(argv[1],"r");
		if(myf==NULL)
		{
			printf("CANNOT OPEN FILE\n");
			return -1;
		}
		
		printf("\nreading\n");
		int c;
		do
		{
			c=fgetc(myf);
			printf("%c",c);
		}while(c!=EOF);
		
		printf("\ndone\n");
		fclose(myf);
	}
	return 0;
}