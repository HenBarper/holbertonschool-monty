#include "monty.h"

/**
 * free_stack - Free the allocated memory for stack
 * @stack: ptr to the doubly linked stack representation
 * Return: void
 */

void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
