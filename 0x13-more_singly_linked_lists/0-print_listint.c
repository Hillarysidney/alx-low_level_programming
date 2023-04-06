#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: head of a linked list of print_listint
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t nnodes = 0;

	while (h)
	{
		printf("%d\n", h->n);
		nnodes++;
		h = h->next;
	}

	return (nnodes);
}
