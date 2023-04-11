#include "lists.h"

/**
 * pop_listint - deletes the head node of
 * a linked list
 * @head: head to the first element in the linked list
 *
 * Return: node data that was deleted in the element.
 */
int pop_listint(listint_t **head)
{
	int knode;
	listint_t *h;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	temp = *head;

	knode = temp->n;

	h = temp->next;

	free(temp);
	
	*head = h;

	return (knode);
}
