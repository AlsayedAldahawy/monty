#include "monty.h"
/**
 * main - main function to work on stack as monty language.
 * @argc: number of arguments.
 * @argv: arguments to be read.
 * Return: as need.
*/
int main(int argc, char *argv[])
{
char *name, *lline = NULL;
FILE *fd;
size_t n = 0;
ssize_t read_file;
unsigned int line_number = 0;
stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	name = argv[1];
	fd = fopen(name, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	while ((read_file = getline(&lline, &n, fd)) != -1)
	{
		line_number++;
		if (*lline == '#')
			continue;
		execute_monty(lline, line_number, &head);
	}
	fclose(fd);
	free(lline);
	free_nodes(&head);
	return (0);
}
