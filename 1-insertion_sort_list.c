#include "sort.h"

/**
 * get_length - find the length of a list
 * @list: list
 */
int get_length(listint_t *list)
{
	listint_t *curr = list;
	int length = 0;

	while (curr != NULL)
	{
		curr = curr->next;
		length++;
	}
	return (length);
}

/**
 * insertion_sort_list - sort a list using insertion sort
 * @list: linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list, *temp, *curr_prev;
	int length;

	length = get_length(*list);
	if (length < 2)
		return;
	while (curr != NULL)
	{
		while (curr->next != NULL && curr->n > curr->next->n)
		{
			temp = curr->next;
			curr->next = temp->next;
			temp->prev = curr->prev;
			if (curr->prev != NULL)
			{
				curr_prev = curr->prev;
				curr_prev->next = temp;
			}
			if (temp->next)
				temp->next->prev = curr;
			temp->next = curr;
			curr->prev = temp;
			if (temp->prev)
				curr = temp->prev;
			else
				*list = temp;
			print_list(*list);
		}
		curr = curr->next;
	}
}
