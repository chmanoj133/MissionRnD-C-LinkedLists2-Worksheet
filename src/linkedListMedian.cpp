/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

// TWO POINTER METHOD
int linkedListMedian(struct node *head)
{
	struct node *i = head, *j = head;
	int ans = 0;

	if (i == NULL)
		return -1;
	else if (i->next == NULL)
		return i->num;
	
	while (j != NULL)
	{
		if (j->next == NULL)
		{
			ans = i->num;
			break;
		}
		else if (j->next->next == NULL)
		{
			ans = i->num + i->next->num;
			ans = ans / 2;
			break;
		}
		j = j->next->next;
		i = i->next;
	}
	return ans;
}

/*
// COUNT METHOD
int linkedListMedian(struct node *head) 
{
	int count = 0, j, flag = 0;
	int ans = 0;
	bool is_even = true;
	struct node *i;

	if (head == NULL)
		return -1;

	for (i = head; i != NULL; i = i->next)
		count++;

	if (count % 2 == 1)
		is_even = false;

	for (i = head, j = 1; i != NULL; i = i->next, j++)
	{
		if (is_even && (j == count / 2 || j == (count / 2 + 1)))
		{
			ans = i->num + ans;
			flag++;
			if (flag == 2)
				break;
		}
		if (!(is_even) && j == (count / 2) + 1)
		{
			ans = i->num;
			break;
		}
	}

	if (count % 2 == 0)
		ans = ans / 2;

	return ans;	
}

*/