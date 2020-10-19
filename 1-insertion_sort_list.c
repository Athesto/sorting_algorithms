#include "sort.h"
/**
 * insertion_sort_list - algoritm
 * @list: ?
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *forward, *backward, *tmp1, *tmp2, *tmp3, *tmp4;

	/* is null or is empty or is only one list */
	if (!list || !*list || !(*list)->next)
		return;


	for (forward = *list; forward; forward = forward->next)
	{
		for (backward = forward; backward->prev; backward = backward->prev)
		{
			if (backward->n < backward->prev->n)
			{
				tmp1 = backward->prev->prev;
				tmp2 = backward->prev;
				tmp3 = backward;
				tmp4 = backward->next;
				if (tmp1)
					tmp1->next = tmp3;
				else
					*list = tmp3;
				tmp3->next = tmp2;
				tmp2->next = tmp4;
				if (tmp4)
					tmp4->prev = tmp2;
				tmp2->prev = tmp3;
				tmp3->prev = tmp1;
				backward = backward->next;
				print_list(*list);
			}
			else
				break;
		}
	}
}
