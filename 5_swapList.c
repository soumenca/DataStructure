#include<stdio.h>
#include<stdlib.h>
struct Node 
{
	int data;
	struct Node *next;
};


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

int lengthList(struct Node *n)
{
	int count = 0;
	while (n != NULL)
	{
		count++;
		n = n->next;
	}
	return count;
}

int main(){
	int f = 1, n, i, middle, count = 0;
	struct Node* head = NULL;
	struct Node* head2 = NULL;
	struct Node* current=NULL;
	struct Node* temp = NULL;
	printf("\nHow many node want to create: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
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
	}
	n = lengthList(head);
	middle = n/2;
	printf("\nThe length of the list is %d and the middle is %d", n, middle);

	printf("\nThe list is ");
	printList(head);
	current = NULL;
	temp = head;
	while(temp->next != NULL){
		temp =  temp->next;
		count++;
		if(count == middle){
			head2 = temp;
			current = temp;
		}
	}
	printf("\nThe last half of the list is ");
	printList(head2);

	while(head != head2){
		temp = head;
		head = head->next;
		temp->next = current->next;
		current->next = temp;
		current = current->next;
		current = current->next;
	}
	printf("\nThe merge list is ");
	printList(head);
	return 0;
}














