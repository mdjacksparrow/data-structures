#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head,*temp;

int info,count=0;

//GETTING DATA 
void get()
{
	printf("\nEnter DATA\t:\t");
	scanf("%d",&info);
	fflush(stdin);
}

//DISPLAY THE CONTENT
void display()
{
	if(head == NULL)
		printf("\nThe list is EMPTY !!\n");
	else
	{
		temp = head;
		printf("\n-----------------------\n");
		while(temp -> next != NULL)
		{
			printf("\n%d\n",temp -> data);
			temp = temp -> next;
		}
		printf("\n%d\n",temp -> data);
		printf("\n-----------------------\n");
	}
}

void beg_ins()
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    get();
    newNode->data = info;
    newNode->next = head;
    head = newNode;
    count++;
}

void pos_ins(position)
{
	if(position > count)
		printf("\nThe position is NOT AVAILABLE in the list!!\n");
	else
	{
		struct node *newNode;
		newNode = malloc(sizeof(struct node));
		get();
		newNode -> data = info;
		struct node *temp = head;

		for(int i=2; i < position; i++) 
		{
			if(temp->next != NULL) 
			{
		    		temp = temp->next;
			}
		}
		newNode->next = temp->next;
		temp->next = newNode;
		count++;
	}
}

void last_ins()
{
	if(head == NULL)
		printf("\nThe list is EMPTY!!");
	else
	{
		struct node *newNode;
		newNode = malloc(sizeof(struct node));
		get();
		newNode->data = info;
		newNode->next = NULL;
		struct node *temp = head;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		count++;
	}
}


//DELETE
void beg_del()
{
	if(head == NULL)
		printf("\nThe list is EMPTY!!");
	else
	{
		printf("\nThe first DATA %d is DELETED !!\n",head -> data);
		head = head->next;
		count--;
	}
}

void pos_del(int position)
{
	if(head == NULL)
		printf("\nThe list is EMPTY!!");
	else
	{
		for(int i=2; i< position; i++)
		 {
			if(temp->next!=NULL) 
			{
			    temp = temp->next;
			}
		 }
		temp->next = temp->next->next;
		printf("\nThe DATA is DELETED !!");
		count--;
	}
}

void last_del()
{
	if(head  == NULL)
		printf("\nThe list is EMPTY!!");
	else
	{
		struct node* temp = head;
		while(temp->next->next!=NULL)
		{
		temp = temp->next;
		}
		temp->next = NULL;
		count--;
		printf("\nThe last DATA is DELETED!!");
	}
}

//MAIN PROGRAM
void main()
{
	int out_choice,in_choice,condition = 1,pos;

	do
	{
		printf("\nThe no.of Item in list\t:\t%d\n",count);
		printf("\n1.\tINSERT\n2.\tDELETE\n3.\tDISPLAY\n4.\tEXIT\n");
		printf("\nEnter your CHOICE\t:\t");
		scanf("%d",&out_choice);
		
		switch(out_choice)
		{
			case 1:
				do
				{	
					printf("\n1.\tBEGGING INSERT\n2.\tPOSITION TO INSERT\n3.\tLAST INSERT\n4.\tBACK MENU\n");
					printf("\nEnter your CHOICE\t:\t");
					scanf("%d",&in_choice);
					
					switch(in_choice)
					{
						case 1:	beg_ins();	 break;
						case 2:	
							printf("\nEnter the position\t:\t");
							scanf("%d",&pos);
							pos_ins(pos);	 
							break;
						case 3:	last_ins();	 break;
						case 4:	condition = 0;break;
					}
				}while(condition);
				//FOR OTHER REPEATED FUNCTIONS
				condition = 1;
				break;
			case 2:
				do
				{
					printf("\n1.\tBEGGING DELETE\n2.\tPOSITION TO DELETE\n3.\tLAST DELETE\n4.\tBACK MENU\n");
					printf("\nEnter your CHOICE\t:\t");
					scanf("%d",&in_choice);
					
					switch(in_choice)
					{
						case 1:	beg_del();	 break;
						case 2:	
							printf("\nEnter the position\t:\t");
							scanf("%d",&pos);
							if(count == 1)
								beg_del();
							else
								pos_del(pos);	 
							break;
						case 3:	
							if(count == 1)
								beg_del();
							else
								last_del();	 
							break;
						case 4:	condition = 0;break;
					}
				}while(condition);
				//FOR OTHER REPEATED FUNCTIONS
				condition = 1;
	

				break;
			case 3:	display();	break;
			case 4:
				exit(0);
			default:
				printf("\nINVALID OPTION ! TRY AGAIN !!\n");
		}
	}while(1);
}
