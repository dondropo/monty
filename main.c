#include "monty.h"
/**
 * main - entry point
 * @argc: number of introduced arguments
 * @argv: invoked arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		reader(argv[1]);
	}
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
