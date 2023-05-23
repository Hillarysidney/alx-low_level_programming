#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes a node at index of a
 * dlistint_t linked list
 *
 * @head: head of a list
 * @index: index of a new node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h7;
	dlistint_t *h8;
	unsigned int o;

	h7 = *head;

	if (h7 != NULL)
		while (h7->prev != NULL)
			h7 = h7->prev;

	o = 0;

	while (h7 != NULL)
	{
		if (o == index)
		{
			if (o == 0)
			{
				*head = h7->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				h8->next = h7->next;

				if (h7->next != NULL)
					h7->next->prev = h8;
			}

			free(h7);
			return (1);
		}
		h8 = h7;
		h7 = h7->next;
		o++;
	}

	return (-1);
}
