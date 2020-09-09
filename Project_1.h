/*
Maria Elena Aviles-Baquero
September 11, 2020
CPSC 346 02
Project 1 Header
*/

#ifndef PROJECT_1_H_
#define PROJECT_1_H_

// Link node definition
struct node {
	int data;
	struct node * next;
};

// Function declarations
struct node* merge(struct node * head1, struct node * head2);
struct node* mergesort(struct node* head, int size);
void printlist(struct node* head);
int get_size(struct node* head);

#endif
