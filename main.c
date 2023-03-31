/*
 * File: main.c
 * Auth: Ben Harper
 */

#include "monty.h"

FILE *fd = NULL;

/**
 * main - The entry point function for Monty Interpreter.
 * @argc: The number of arguments.
 * @argv: The pointer to an array of inputed arguments.
 * Return: Always 0 (on Success).
 */
int main(int argc, char **argv)
{
	void (*f)(stack_t **, unsigned int) = NULL;
	char *buffer = NULL, *token = NULL, *op = NULL, *n = NULL;
	size_t length = 0;
	stack_t *stack = NULL;
	const char deliminators[] = " \t\n";
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &length, fd) != -1)
	{
		token = strtok((buffer), deliminators);
		strcpy(op, token);
		f = get_func(&stack, line_number, token);
		if (strcmp(op, "push") == 0)
		{
			token = strtok(NULL, deliminators);
			if (token == NULL)
			{
				free(buffer), buffer = NULL, free_stack(&stack);
				fprintf(stderr, "L%d: usage: push integer\n", line_number), err();
			}
			strcpy(n, token);
		}
		free(buffer), buffer = NULL, f(&stack, line_number);
		if (strcmp(op, "push") == 0)
			set_n(&stack, line_number, n);
	}
	free(buffer), fclose(file), free_stack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * get_func - choses a function to run based on the op
 * @stack: the stack
 * @l: line number
 * @code: operation code
 * Return: ptr to the chosen function
 */
void (*get_func(stack_t **stack, int l, char *code))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};

	while (strcmp(code, instruction[i].opcode) != 0)
	{
		i++;
		if (i > 7)
		{
			fprintf(stderr, "L%d: unknown instructions %s\n", l, code);
			free_stack(stack);
			close_error();
		}
	}
	return (instructions[i].f);
}

/**
 * set_n - sets n value of new node
 * @stack: linked list
 * @line_num: current line
 * @num: number to add
 */
void set_n(stack_t **stack, unsigned int line_num, char *num)
{
	if (strcmp(num, "0") == 0)
		(*stack)->n = 0;
	if (strcmp(num, "0") != 0)
	{
		(*stack)->n = atoi(num);
		if ((*stack)->n == 0 || (num[0] != '-' && (*stack)->n == 1))
		{
			fprintf(stderr, "Error: L%d: usage: push integer\n", line_num);
			free_stack(stack);
			close_error();
		}
	}
}

/**
 * close_error - close file and exit
 * Return: void
 */
void close_error(void)
{
	fclose(fd);
	exit(EXIT_FAILURE);
}
