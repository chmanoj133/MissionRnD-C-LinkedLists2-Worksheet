/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
void merge2LinkedLists_extra_args(struct node *head1, struct node *head2, struct node **head);

struct node 
{
	int num;
	struct node *next;
};



struct node * merge2LinkedLists(struct node *head1, struct node *head2) 
{
	struct node *i = head1, *j = head2, *temp, *first, *temp2;

	if (i == NULL)
		return j;
	else if (j == NULL)
		return i;
	else
	{
		
		if (i->num > j->num)
		{
			first = j;
			j = i;
			i = first;
		}
		else
			first = i;

		while (1)
		{
			if (i->next != NULL)
			{
				if (i->next->num > j->num)
				{
					temp = i->next;
					i->next = j;
					temp2 = j->next;
					j->next = temp;
					i = j;
					j = temp2;
				}
				else
					i = i->next;
			}
			

			if (i->next == NULL)
			{
				i->next = j;
				break;
			}

			if (j == NULL)
				break;
		}

		return first;
	}
}

