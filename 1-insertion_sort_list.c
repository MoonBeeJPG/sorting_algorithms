#include "sort.h"

/**
* compare - nodes
* @n1: higher node
* @n2: lower node
* Return: True or False
*/
int compare(listint_t *n1, listint_t *n2)
{
	if (!n1 || !n2)
		return (0);
	if (n1->n > n2->n)
		return (1);
	return (0);
}

/**
* sswap - two nodes in a doubly linked list
* @i: position of first node
* @j: position of second node
*
*/
void sswap(listint_t *i, listint_t *j)
{
	if (i->prev)
		i->prev->next = j;
	if (j->next)
		j->next->prev = i;
	i->next = j->next;
	j->prev = i->prev;
	i->prev = j;
	j->next = i;
}

/**
* insertion_sort_list - sor a doubly linked list of integers
*
* @list: list of integers
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *pointer, *comp;

	if (!list || !*list || !(*list)->next)
		return;
	pointer = (*list)->next;
	while (pointer)
	{
		comp = pointer;
		pointer = comp->next;
		while (comp && comp->prev)
		{
			if (comp->prev->n > comp->n)
			{
				sswap(comp->prev, comp);
				if (!comp->prev)
					*list = comp;
				print_list((const listint_t *)*list);
			}
			else
				comp = comp->prev;
		}
	}
}
