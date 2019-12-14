#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t c = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		c++;
		h = h->next;
	}
	return (c);
}
