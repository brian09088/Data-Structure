#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdbool.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

/* Function to reverse the linked list */
static void reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next = NULL;
	while (current != NULL) {
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}
	*head_ref = prev;
}

/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct Node* head)
{
	struct Node* temp = head;
	printf(">");
	while (temp != NULL) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
}

/* Function to get the middle of the linked list*/
void printMiddle(struct Node* head)
{
	int count = 0;
	struct Node* mid = head;

	while (head != NULL) {
		if (count & 1){
            mid = mid->next;}
        ++count;
		head = head->next;
	}
	printf(">");
	while (mid != NULL){
		printf(" %d", mid->data);
		mid=mid->next;}
    printf("\n");
}


int main()
{
	struct Node* head = NULL;

    int input;
    int count=0;
    while(scanf("%d",&input)!=EOF){
        push(&head,input);
        count++;}

    reverse(&head);
    printMiddle(head);

	reverse(&head);
	printList(head);
}
