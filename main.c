#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char *buffer = NULL;
	ssize_t characters = 0;
	size_t bufsize = 0, line_counter = 0;

	if (argc == 2)
	{		
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			fputs("Is not a file\n",stderr);
			exit(EXIT_FAILURE);
		}
		while ((characters = getline(&buffer, &bufsize, file)))
		{
			
			if (characters == EOF)
			{
				free(buffer);
				break;
			}
			line_counter++;
			validate_buffer(buffer, line_counter);
			break;
		}
		printf("El archivo tiene %ld", line_counter);
		fclose(file);
	}
	else
	{
		fputs("USAGE: monty file\n",stderr);
		exit (EXIT_FAILURE);
	}
	return (0);
}