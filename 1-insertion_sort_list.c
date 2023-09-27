#include "sort.h"

/**
* _swaps - swaps two nodes in a doubly
* linked list
* @a: listint_t node
* @b: listint_t node
*/
void _swaps(listint_t **a, listint_t **b)
{
	listint_t *next, *prev;

	next = (*b)->next;
	prev = (*a)->prev;
	(*b)->next = *a;
	(*b)->prev = prev;
	if (prev)
		prev->next = *b;
	(*a)->next = next;
	if (next)
		next->prev = *a;
	(*a)->prev = *b;
}

/**
* insertion_sort_list - algorithm to
* sort a doubly linked list
* @list: head of doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *first, *second, *tmp;

	if (list == NULL || *list == NULL)
		return;

	curr = *list;
	while (curr)
	{
		first = curr;
		second = curr->next;
		if (first && second && first->n > second->n)
		{
			_swaps(&first, &second);
			if (second->prev == NULL)
				*list = second;
			print_list(*list);
			tmp = second->prev;
			while (second && tmp && second->n < tmp->n)
			{
				_swaps(&tmp, &second);
				if (second->prev == NULL)
					*list = second;
				print_list(*list);
				tmp = second->prev;
			}
		}
		else
			curr = curr->next;
	}
}
