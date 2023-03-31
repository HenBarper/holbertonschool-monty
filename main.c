/*
 * File: main.c
 * Auth: Ben Harper
 */

#include "monty.h"

FILE *file = NULL;

/**
 * main - The entry point function for Monty Interpreter.
 * @ac: The number of arguments.
 * @av: The pointer to an array of inputed arguments.
 * Return: Always 0 (on Success).
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "USAGE: monty file");
		return (EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", (argv[1]));
		return (EXIT_FAILURE);
	}
	return (0);
}
