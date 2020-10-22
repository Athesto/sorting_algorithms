#include "sort.h"
void swap_node(listint_t **list, listint_t *node, int fwd);
/**
 * cocktail_sort_list - algoritm
 * @list: ?
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *runner;
	listint_t *step;
	int fwd = 1;
	int done = 0;

	if (!list || !*list)
		return;
	runner = *list;
	while (1)
	{
		if (fwd)
		{
			step = runner->next;
			if (!step)
			{
				done = 1;
				fwd = !fwd;
				continue;
			}
			if (runner->n > step->n)
			{
				done = 0;
				swap_node(list, runner, fwd);
				print_list(*list);
			}
			else
				runner = step;
		}
		else
		{
			step = runner->prev;
			if (!step)
			{
				if (done)
					break;
				fwd = !fwd;
				continue;
			}
			if (runner->n < step->n)
			{
				done = 0;
				swap_node(list, runner, fwd);
				print_list(*list);
			}
			else
				runner = step;
		}
	}
}
/**
 * swap_node - swap nodes from list
 * @list: input list
 * @node: node to swap
 * @fwd: swap forwad (1) or backward (0)
 */
void swap_node(listint_t **list, listint_t *node, int fwd)
{
	listint_t *tmp1;
	listint_t *tmp2;
	listint_t *tmp3;
	listint_t *tmp4;

	if (fwd)
	{
		tmp2 = node;
		tmp3 = node->next;
	}
	else
	{
		tmp2 = node->prev;
		tmp3 = node;
	}


	if (tmp2)
		tmp1 = tmp2->prev;
	if (tmp3)
		tmp4 = tmp3->next;

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
}

