#include "sort.h"
/**
 * insertion_sort_list - algoritm
 * @list: ?
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *forward; /* runner forward */
	listint_t *backward; /* runner backward */
	listint_t *node; /* evaluation node */

	/* is a valid list or is list empty or is single item list? */
	if (!list || !*list || !(*list)->next)
		return;
	backward = *list;
	forward = (*list)->next;
	while (forward)
	{
		print_list(*list);
		if (forward->n < backward->n)
		{
			node = forward;
			forward = backward;
			backward->next = node->next;
			if (node->next)
				node->next->prev = backward;
			while (backward)
			{
				if (backward->prev == NULL)
				{
					node->next = backward;
					backward->prev = node;
					node->prev = NULL;
					*list = node;
					break;
				}
				else if (node->n > backward->prev->n)
				{
					node->next = backward;
					node->prev = backward->prev;
					backward->prev->next = node;
					backward->prev = node;
					break;
				}
				backward = backward->prev;
			}
		}
		backward = forward;
		forward = forward->next;
	}
}
