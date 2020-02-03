#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *previous, *temp;

	if (list == NULL || *list == NULL)
		return;

	temp = (*list)->next;

	while (temp != NULL)
	{
		previous = temp->prev;
		while (previous != NULL)
		{
			if (temp->n < previous->n)
			{
				previous->next = temp->next;
				temp->next = temp->prev;
				temp->prev = previous->prev;
				previous->prev = temp;

				if (temp->prev != NULL)
					temp->prev->next = temp;
				if (previous->next != NULL)
					previous->next->prev = previous;
				if (previous->prev == NULL)
					*list = previous;
				else if (temp->prev == NULL)
					*list = temp;

				print_list(*list);
			}
			previous = previous->prev;
		}
		temp = temp->next;
	}
}
