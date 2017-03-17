#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int payload;
	struct node* left;
	struct node* right;
}node;

void printTree(node* leaf);
int destroyTree(node* leaf);
int addNode(int payload,node**);
node* searchTree(int key,node* leaf);
void handleProgram(node* leaf);

int main(int argc, char* argv[])
{
	node* parent=0;
	
	handleProgram(parent);
	
	destroyTree(parent);
	
	return 0;
}

void printTree(node* leaf)
{
	if(leaf==NULL)
		return;
	printTree(leaf->left);
	printf("%d\n",leaf->payload);
	printTree(leaf->right);
}

int destroyTree(node* leaf)
{
	if(leaf!=NULL)
	{
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		free(leaf);
	}
}

int addNode(int payload, node** leaf)
{
	if(*leaf==0)
	{
		*leaf = (node*)malloc(sizeof(node));
		(*leaf)->payload=10;
		(*leaf)->left=NULL;
		(*leaf)->right=NULL;
		printf("Added %d\n",payload);
		return 0;
	}
	else if(payload < (*leaf)->payload)
	{
		addNode(payload,&(*leaf)->left);
	}
	else if(payload > (*leaf)->payload)
	{
		addNode(payload,&(*leaf)->right);
	}
}

node* searchTree(int key,node* leaf)
{
	if(leaf!=NULL)
	{
		if(key == leaf->payload)
			return leaf;
		else if(key < leaf->payload)
			return searchTree(key,leaf->left);
		else
			return searchTree(key,leaf->right);
	}
	else
	{
		printf("Didn't find %d \n",key);
		return NULL;
	}
}

void handleProgram(node* leaf)
{
	int dne=1;
	printf("\n\n@@@ B I N A R Y T R E E @@@\n");
	printf("\n@@@ C O M M A N D S @@@\n\n");
	printf("1.......Add To List\n");
	printf("2.......Search For Item\n");
	printf("3.......Print Tree\n");
	
	while(dne)
	{
		printf("\nEnter a command or press 4 to quit\n");
		char buff[8];
		int qom;
		scanf("%s",&buff);
		qom=atoi(buff);
		switch(qom)
		{
			case 1:
			{
				int pld;
				printf("Enter a number to add\n");
				scanf("%d",&pld);
				addNode(pld,&leaf);
				break;
			}
			case 2:
			{
				int pld;
				printf("Enter a number to search for\n");
				scanf("%d",&pld);
				searchTree(pld,leaf);
				break;
			}
			case 3:
				printTree(leaf);
				break;
			case 4:
				dne=0;
				break;
			default:
				printf("\n\n@@@ B I N A R Y T R E E @@@\n");
				printf("\n@@@ C O M M A N D S @@@\n\n");
				printf("1.......Add To List\n");
				printf("2.......Search For Item\n");
				printf("3.......Print Tree\n");
				break;
		}
	}
}