#include "lists.h"

/**
 * dlistint_len - returns number of elements in
 * a double linked list
 *
 * @h: head of a list
 * Return: the number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int start;

	start = 0;

	if (h == NULL)
		return (start);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		start++;
		h = h->next;
	}

	return (start);
}
