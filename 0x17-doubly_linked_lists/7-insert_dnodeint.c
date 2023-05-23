#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts the real node at
 * a given position
 *
 * @h: head of a list
 * @idx: index of the real node
 * @n: value of a real node
 * Return: the address of a real node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *real;
	dlistint_t *head;
	unsigned int o;

	real = NULL;
	if (idx == 0)
		real = add_dnodeint(h, n);
	else
	{
		head = *h;
		o = 1;
		if (head != NULL)
			while (head->prev != NULL)
				head = head->prev;
		while (head != NULL)
		{
			if (o == idx)
			{
				if (head->next == NULL)
					real = add_dnodeint_end(h, n);
				else
				{
					real = malloc(sizeof(dlistint_t));
					if (real != NULL)
					{
						real->n = n;
						real->next = head->next;
						real->prev = head;
						head->next->prev = real;
						head->next = real;
					}
				}
				break;
			}
			head = head->next;
			o++;
		}
	}

	return (real);
}
