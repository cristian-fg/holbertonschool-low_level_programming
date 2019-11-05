#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_listint2 - Free a list.
 * @head: The arguments.
 * Return: The new node.
 */

void free_listint2(listint_t **head)
{
	listint_t *temp = *head;

	while (*head)
	{
		temp = temp->next;
		free(*head);
		*head = temp;
	}
	*head = NULL;
}
