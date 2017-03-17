#include <stdio.h>
#include <stdlib.h>

int main
{
	FILE* fp;
	fopen_s(&fp,".py","r");
	fseek(fp,0,SEEK_END);
	int len = ftell(fp);
	fseek(fp,0,SEEK_SET);
	char* b = new char[len+1];
	fread(b,1,len,fp);
	b[len]=0;
	fclose(fp);
	return 0;
}