#include "lists.h"

/**
 * add_dnodeint - adds a real node at beginning
 * of a dlistint_t list
 *
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the real element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *real;
	dlistint_t *h;

	real = malloc(sizeof(dlistint_t));
	if (real == NULL)
		return (NULL);

	real->n = n;
	real->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}

	real->next = h;

	if (h != NULL)
		h->prev = real;

	*head = real;

	return (real);
}
