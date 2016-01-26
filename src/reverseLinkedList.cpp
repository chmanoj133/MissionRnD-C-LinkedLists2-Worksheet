/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node *reverse_SLL_tail_recursive(struct node* head, struct node *last);

struct node {
	int num;
	struct node *next;
};


// METHOD-1: WITHOUT RECURSION
// METHOD-2: WITH RECURSION-> (1). Tail Recursion
//							  (2). Non Tail Recursion


// METHOD-2.(2). Non-tail Recursion

/*
struct node * reverseLinkedList(struct node *head) 
{
	struct node *tail;

	if (head == NULL)
		return NULL;
	
	if (head->next == NULL)
		return head;

	tail = reverseLinkedList(head->next);

	head->next->next = head;
	head->next = NULL;
	return tail;
	
}
*/


// METHOD-2(1) -> Tail recursion
struct node * reverseLinkedList(struct node *head)
{
	return reverse_SLL_tail_recursive(head, head);
}

// Recursive function
struct node *reverse_SLL_tail_recursive(struct node* head, struct node *last)
{
	struct node *temp;

	if (head == NULL && last == NULL)
		return NULL;
	
	if (last != NULL)
	{
		if (&head->num == &last->num)
		{
			last = head->next;
			head->next = NULL;
		}
		if (last == NULL)
			return head;
		else
		{
			temp = last->next;
			last->next = head;
			head = last;
			last = temp;
			head = reverse_SLL_tail_recursive(head, last);
		}
	}
	return head;	
}



// METHOD-1: without recursion

/*
struct node * reverseLinkedList(struct node *head)
{
	struct node *i = head, *j, *temp;

	if (head == NULL)
		return NULL;
	j = head->next;
	head->next = NULL;
	while (j!= NULL)
	{
		temp = j->next;
		j->next = i;
		i = j;
		j = temp;
	}
	return i;
}

*/