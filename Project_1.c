/*
Maria Elena Aviles-Baquero
September 10, 2020
CPSC 346 02
Project 1 C Program
*/

#include <stdio.h>
#include <stdlib.h>
#include "Project_1.h"

// Function Definitions

/*
This function merges two sublists into one and returns the merged list
*/
struct node* merge(struct node * head1, struct node * head2) 
{
	// Creates a new node to store the final merged list
	struct node* final = NULL;
	
	// If either list is empty, no merging occurs
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	
	// Checks to find smallest value, and sets it as the new head
	if((head1->data) <= (head2->data))
	{
		final = head1;
		final->next = merge((head1->next), head2);
	}
	else {
		final = head2;
		final->next = merge(head1, (head2->next));
	}
	
	// Recursively calling merge until the two sublist are empty
	return final;	
}

/*
This function sorts a linked list by dividing the list into two sublists then recursively calling mergesort() to sort and merge the rest of the list.
*/
struct node* mergesort(struct node** head_ref, int size)
{
	struct node* head = *head_ref;
	struct node* head1;
	struct node* head2;
	struct node* once = head; // traverses the list normally
	struct node* twice = head->next; // traverse the list quickly
	
	// if the size of the list is 0 or 1 then nothing happens
	if(head == NULL || head->next == NULL)
		return head;
	
	// Divide the original list into two
	while(twice != NULL)
	{
		twice = twice->next;
		if (twice != NULL)
		{
			once = once->next;
			twice = twice->next;
		}
	}
	
	// Assigns two list heads to the two halves of the list
	head1 = head;
	head2 = once->next;
	once->next = NULL;
	
	// Prints the size of the list passed into the function
	printf("New List: \n");
	printlist(head);
	printf("\n");

	// Recursively sorts the sublists
	return merge(mergesort(&head1, get_size(head1)), mergesort(&head2, get_size(head2)));
}

/*
This function that a head pointer and a new item and creates a new node to hold the item, and pushes it to the head of the list.
*/
void push(struct node** head, int new_item)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	
	new_node->data = new_item;
	new_node->next = *head;
	*head = new_node;
}

/*
This function prints a linked list through a node passed in.
*/
void printlist(struct node* head) 
{
	while (head != NULL) 
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

/*
This function returns the size of the list pointed to my the pointer.
*/
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
	struct node* myList = NULL;
	struct node* sortedList = NULL;
	struct node* list1 = NULL;
	struct node* list2 = NULL;
	struct node* mergedList = NULL;
	
	// Create a two sorted sublists to test merge() function
	push(&list1, 2);
	push(&list1, 1);
	push(&list2, 4);
	push(&list2, 3);
	
	// Tests merge() function
	mergedList = merge(list1, list2);
	printf("Merged List: \n");
	printlist(mergedList);
	printf("\n");
	
	
	// Creates the linked list through the use of push()
	// myList: 6 5 4 3 2 1
	push(&myList, 1);
	push(&myList, 2);
	push(&myList, 3);
	push(&myList, 4);
	push(&myList, 5);
	push(&myList, 6);
	
	// Prints the unsorted list
	printf("Unsorted Linked List: \n");
	printlist(myList);
	printf("\n");
	
	// Assigns the sorted list to sortedList
	sortedList = mergesort(&myList, get_size(myList));
	
	// Prints the sorted list
	printf("Sorted Linked List: \n");
	printlist(sortedList);
	printf("\n");
	
	// Prints the size of the list, specifically the sorted list
	printf("Size of Linked List: %d\n", get_size(sortedList));
	
	return 0;
}

// END OF PROGRAM
