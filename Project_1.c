/*
Maria Elena Aviles-Baquero
September 11, 2020
CPSC 346 02
Project 1 C Program
*/

#include <stdio.h>
#include "Project_1.h"

// Function Definitions

/*
function title
{
	....
}
// 
*/
struct node* merge(struct node * head1, struct node * head2) 
{
	/*
	- takes two pointers as parameters, each pointing to a sorted list
	- returns a new head pointer pointing to the merged list
	struct node* newhead = merge(head1, head2);
	return newhead; (?)
	*/
}

struct node* mergesort(struct node* head, int size)
{
	/*
	- takes the head of the node list and size of the list
	*/
}

void printlist(node* head) 
{
	node* curr = head;
	while (curr != NULL) 
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}

int get_size(struct node* head)
{
	node* curr = head;
	int size = 0;
	while (curr != NULL) 
	{
		curr = curr->next;
		size++;
	}
	return size;
}



// Main Function
int main() {


	return 0;
}
