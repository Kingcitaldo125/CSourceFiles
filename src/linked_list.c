#include <stdio.h>
#include <stdlib.h>

struct node
{
	int payload;
	struct node* next;
};

int main()
{
	struct node* traverser;
	struct node* root;
	
	root = malloc(sizeof(struct node));
	root->payload = 12;
	root->next = NULL;
	
	traverser = root;
	
	if (traverser!=NULL)
	{
		while(traverser->next!=NULL)
		{
			traverser = traverser->next;
		}
	}
	
	traverser->next = malloc(sizeof(struct node));
	traverser = traverser->next;
	
	if(traverser==NULL)
	{
		printf("Out of mem space");
		return -1;
	}
	
	traverser->payload = 42;
	traverser->next = NULL;
	
	/*Print out the list*/
	traverser=root;
	int jj=1;
	if(traverser!=NULL)
	{
		while(traverser->next!=NULL)
		{
			printf("Node Number:%d %d\n",jj,traverser->payload);
			traverser=traverser->next;
			jj=jj+1;
		}
		printf("Node Number:%d %d\n",jj,traverser->payload);
	}
		
	
	return 0;
}