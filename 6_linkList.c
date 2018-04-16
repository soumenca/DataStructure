#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

void deleteNode(struct Node *head_ref, int key)
{
    struct Node *temp = head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        head_ref = temp->next;   
        free(temp);               
        return;
    }
 
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; 
    prev->next = temp->next;
    free(temp);  // Free memory
}


struct Node* createNode(){
	int value;
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter the Value for Data field: ");
	scanf("%d", &value);
	temp->data = value;
	temp->next = NULL;
	return temp;
}

void printList(struct Node *n)
{
	while (n != NULL)
	{
		printf(" %d ", n->data);
		n = n->next;
	}
}

int main()
{
	int ch, ch1, n, value, f=1;
	struct Node* head = NULL;
	struct Node* current=NULL;
	struct Node* temp = NULL;
	do{	
		
		printf("\n1. For Append 2. For Delete\nEnter your choice: ");
		scanf("%d", &ch);	
		switch(ch)
		{
			case 1:
				temp = createNode();
				if(f){
					head = temp;
					current = temp;
					f = 0;
				}
				else{
					current->next = temp;
					current = current->next;
				}
				break;
			case 2:
				printf("\nWhich element want to delete: ");
				scanf("%d",&n);
				deleteNode(head, n);
				break;
			default:
				break;
		}
		printf("\n1.For Continue 2.For exit\nEnter your choice: ");
		scanf("%d",&ch1);
	}while(ch1 == 1);

	printList(head);

	return 0;
}





	/*struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;
 
	head = (struct Node*)malloc(sizeof(struct Node)); 
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = createNode();

	head->data = 1; //assign data in first node
	head->next = second; // Link first node with second 

	second->data = 2; //assign data to second node
	second->next = third; 
	
	third->data = 3; //assign data to third node
	third->next = fourth;*/
