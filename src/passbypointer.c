#include <stdio.h>
#include <stdlib.h>

void add(char*buff[8],int*bs,char*name);
void print(char*buff[8],int*bs);

typedef struct person
{
	unsigned int age;
	char* name;
}Person;

int main()
{
	Person paul;
	paul.name="Paul";
	paul.age=21;
	
	int buffSize=0;
	int* b=&buffSize;
	char* buff[8];
	
	add(buff,b,"Paul");
	add(buff,b,"Ken");
	add(buff,b,"John");
	add(buff,b,"Terry");
	add(buff,b,"Sid");
	add(buff,b,"Daniel");
	add(buff,b,"Gerry");
	add(buff,b,"Tom");
	add(buff,b,"Bill");
	print(buff,b);
	
	return 0;
}

void add(char*buff[8],int*bs,char*name)
{
	
	if(*bs<8)
	{
		buff[*bs]=(char*)name;
		*bs=*bs+1;
		printf("Array Size %d\n",*bs);
	}
	else
	{
		printf("ERROR ADDING: size limit reached\n");
	}
}

void print(char*buff[8],int*bs)
{
	int i;
	printf("People: \n");
	for(i=0;i<*bs;++i)
	{
		printf("%s\n",buff[i]);
	}
}