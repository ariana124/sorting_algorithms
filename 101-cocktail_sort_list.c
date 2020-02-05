#include "sort.h"


/**
 * swap_node - function that swaps nodes in a doubly linked list
 * @list: pointer to head of linked list
 * @r: right node
 * @l: left node
 *
 * Return: void
 */
void swap_node(listint_t **list, listint_t *r, listint_t *l)
{
	listint_t *p, *n;

	p = l->prev;
	n = r->next;

	if (p) /* if node exists */
		p->next = r;
	else
		*list = r;

	if (n)
		n->prev = l;

	r->prev->next = p;
}


/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to head of linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1; /* flag */
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;

	temp = *list;

	while (swapped == 1) /* while TRUE */
	{
		swapped = 0;

		while (temp->next != NULL) /* loop forward through list */
		{
			if (temp->n > temp->next->n)
			{
				swap_node(list, temp, temp->next);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;

		while (temp->prev != NULL) /* loop backwards through list */
		{
			if (temp->n < temp->prev->n)
			{
				swap_node(list, temp, temp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
