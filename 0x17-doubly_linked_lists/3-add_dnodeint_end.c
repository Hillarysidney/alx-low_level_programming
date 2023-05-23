#include "lists.h"

/**
 * add_dnodeint_end - adds a real node at end
 * of a dlistint_t list
 *
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the real element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h;
	dlistint_t *real;

	real = malloc(sizeof(dlistint_t));
	if (real == NULL)
		return (NULL);

	real->n = n;
	real->next = NULL;

	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = real;
	}
	else
	{
		*head = real;
	}

	real->prev = h;

	return (real);
}
