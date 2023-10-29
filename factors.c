#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
 * factors - The function factorize a number
 * @buffer: pointer to the address of the number
 *
 * Return: int
 */
int factors(char *buffer)
{
	uint32_t nbr;
	uint32_t idx;

	nbr = atoi(buffer);
	idx = 1;

	while (++idx < nbr)
	{
		if (nbr % idx == 0)
		{
			printf("%d=%d*%d\n", nbr, nbr / idx, idx);
			break;
		}
	}

	return (0);
}

/**
 * main - main function
 * @ac: number of command line arguments.
 * @av: array that contains the program command line arguments.
 *
 *
 * Return: void
 */
int main(int ac, char *av[])
{
	FILE *fd;
	size_t count = 0;
	ssize_t line;
	char *buffer = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((line = getline(&buffer, &count, fd)) != -1)
	{
		factors(buffer);
	}

	free(buffer);
	fclose(fd);

	return (0);
}

