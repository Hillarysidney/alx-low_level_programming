#include "lists.h"

/**
 * print_dlistint - prints all elements of a
 * dlistint_t list
 *
 * @h: head of a list
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int start;

	start = 0;

	if (h == NULL)
		return (start);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		start++;
		h = h->next;
	}

	return (start);
}
