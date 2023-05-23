#include "lists.h"

/**
 * get_dnodeint_at_index - returns a
 * nth node of a dlistint_t linked list
 *
 * @head: head of the list
 * @index: index of nth node
 * Return: nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int o;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	o = 0;

	while (head != NULL)
	{
		if (o == index)
			break;
		head = head->next;
		o++;
	}

	return (head);
}
