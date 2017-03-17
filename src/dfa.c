#include <stdio.h>
#include <stdlib.h>

char* dfa(const char arraylist[], const char alphabet[]);
void printResult(const char list[], const char alphabet[]);

int main()
{
	const char list[] = "aabbabab";
	const char listtwo[] = "bbb";
	const char alphabet[] = "abc";
	
	printf("All strings with at least 1 'a'\n");
	
	printResult(list, alphabet);
	printResult(listtwo, alphabet);
	
	return 0;
}

//All strings with at least 1 a
char* dfa(const char arraylist[], const char alphabet[])
{
	int i;
	for(i=0; arraylist[i]!='\0'; ++i)
	{
		int j;
		short valid = 0;
		for(j=0; alphabet[j]!='\0'; ++j)
		{
			if(arraylist[i]==alphabet[j])
				valid = 1;
		}
		
		if(!valid)
			return "Reject";
		if(arraylist[i]=='a')
			return "Accept";
	}
	return "Reject";
}

void printResult(const char list[], const char alphabet[])
{
	char* result;
	result = dfa(list, alphabet);
	printf("%s RESULT: %s\n", list, result);
}