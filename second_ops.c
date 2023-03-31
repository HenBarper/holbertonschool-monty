#include "monty.h"

/**
 * push - adds an element to a stack
 * @stack: linked list stack to push to
 * @line_number: current line number of bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
	}
}

/**
 * pop - removes the first element of the stack
 * @stack: linked list stack to pop
 * @line_number: current line number of bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
}

/**
 * swap - swaps the two top elements of a stack
 * @stack: linked list stack to swap
 * @line_number: current line number of bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
}

/**
 * add - adds the first two elements of a stack, replaces both with sum
 * @stack: linked list stack to add
 * @line_number: current line number of bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
}
