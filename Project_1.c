/*
Maria Elena Aviles-Baquero
September 11, 2020
CPSC 346 02
Project 1 C Program
*/

#include <stdio.h>
#include <stdlib.h>
#include "Project_1.h"

// Function Definitions

struct node* merge(struct node * head1, struct node * head2) 
{
	struct node* final = NULL;
	
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	
	if(head1->data <= head2->data)
	{
		final = head1;
		final->next = merge(head1->next, head2);
	}
	else {
		final = head2;
		final->next = merge(head1, head2->next);
	}
	
	return final;
	
	// CHECK TO SEE IF CORRECT
	/*
	- takes two pointers as parameters, each pointing to a sorted list
	- returns a new head pointer pointing to the merged list
	struct node* newhead = merge(head1, head2);
	return newhead; (?)
	*/
}

struct node* mergesort(struct node* head)
{
	struct node* head1;
	struct node* head2;
	struct node* once = head;
	struct node* twice = head->next; 
	//struct node* tmp = head;
	//int size1 = 0, size2 = 0;
	
	// if the size of the list is 0 or 1 then nothing happens
	if(head == NULL || head->next == NULL)
		return head;
	
	// Divide the original list into two
	/*
	for(int i = 0; i <= size/2; i++)
	{
		tmp = tmp->next;
		size1++;
	}
	head2 = tmp->next;
	*/
	
	while(twice != NULL)
	{
		twice = twice->next;
		if (twice != NULL)
		{
			once = once->next;
			twice = twice->next;
		}
	}
	
	head1 = head;
	head2 = once->next;
	once->next = NULL;

	// Recursively sorts the sublists
	
	return merge(mergesort(head1), mergesort(head2));
	/*
	- takes the head of the node list and size of the list
	- Divide original list into halves
	- recursively call mergesort on each sublist
	- when all the sublists are sorted call merge
	
	can actually do merge(mergesort(head, size1), mergesort(head2, size2))
	*/
}

void printlist(struct node* head) 
{
	struct node* curr = head;
	while (curr != NULL) 
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}

int get_size(struct node* head)
{
	struct node* curr = head;
	int size = 0;
	while (curr != NULL) 
	{
		curr = curr->next;
		size++;
	}
	return size;
}



// Main Function
int main() 
{
	//struct node* myList = NULL;
	
	// find a way to make a linked list w/o making a new function
	
	printf("Unsorted Linked List: \n");
	//printList(myList);
	printf("\n");
	
	//mergesort(myList);
	
	printf("Sorted Linked List: \n");
	//printList(myList);
	printf("\n");
	
	//printf("Size of Linked List: %d\n", get_size(myList));
	
	printf("Program complete!\n");
	
	
	
	return 0;
}
