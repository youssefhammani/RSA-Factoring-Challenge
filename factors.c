#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * factorize - Function to factorize the number into two smaller numbers
 * @num: Variable stored the number from the file
 *
 * Return:;
 */
void factorize(uint64_t num)
{
	uint64_t p, q;

	for (p = 2; p * p <= num; p++)
	{
		if (num % p == 0)
		{
			q = num / p;
			printf("%llu=", (unsigned long long)num);
			printf("%llu*%llu\n", (unsigned long long)p, (unsigned long long)q);
			return;
		}
	}
	printf("1=1*%llu\n", (unsigned long long)num);
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
	if (ac != 2)
	{
		fprintf(stderr, "Usage: factors <filename>\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(av[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	uint64_t num;

	while (fscanf(file, "%lu", &num) == 1)
	{
		factorize(num);
	}
	fclose(file);

	return (0);
}
