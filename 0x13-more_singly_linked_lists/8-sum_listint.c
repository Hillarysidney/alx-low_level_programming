#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data (n) in a listint_t list
 * @head: head node in the linked list
 *
 * Return: sum of all data
 */
int sum_listint(listint_t *head)
{
	int sum;

	sum = 0;
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
