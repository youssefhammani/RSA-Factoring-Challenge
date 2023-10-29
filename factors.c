#include <stdio.h>

/*
 * factors - the given number `num` into two smaller numbers
 * and prints the factorization
 * @num: The number to be factorized
*/
void factorize(int num)
{
	int i;

	for (i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			printf("%d=%d*%d\n", num, i, num / i);
			return;
		}
	}
}

/*
 * main - function that reads numbers from a file and factors each number.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 * Returns: 0 on success or 1 on error.
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("File not found.\n");
		return (1);
	}

	int num;

	while (fscanf(file, "%d", &num) == 1)
	{
		factorize(num);
	}

	fclose(file);

	return (0);
}
