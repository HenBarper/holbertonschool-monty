/*
 * File: main.c
 * Auth: Ben Harper
 */

#include "monty.h"

/**
 * main - The entry point function for Monty Interpreter.
 * @ac: The number of arguments.
 * @av: The pointer to an array of inputed arguments.
 * Return: Always 0 (on Success).
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		return (EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", (av[1]));
		return (EXIT_FAILURE);
	}
	return (0);
}
