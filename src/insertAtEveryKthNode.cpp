/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) 
{
	struct node *i = head, *j, *newnode, *temp;
	int count;

	if (head == NULL || K <= 0)
		return NULL;

	for (i = head, j = head->next, count = 1; i != NULL; j = j->next, count++)
	{
		if (count == K)
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			newnode->num = K;	
			i->next = newnode;
			newnode->next = j;
			i = newnode;
			count = 0;
		}
		i = i->next;

		if (i == NULL)
			break;
	}
	return head;
}
