#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/**
 * is_prime - Checks if a number is prime.
 *
 * @num: The number to check.
 * Return: 1 if not prime 0 if prime.
 */
int is_prime(uint64_t num)
{
	if (num < 2)
		return (0);
	if (num < 4)
		return (1);
	if (num % 2 == 0 || num % 3 == 0)
		return (0);

	uint64_t i = 5;

	while (i * i <= num)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return (0);
		i += 6;
	}

	return (1);
}

/**
 * find_prime_factors - Find the prime factors of a number
 *
 * @num: The number for which to find prime factors
 */
void find_prime_factors(uint64_t num)
{
	uint64_t p;

	for (p = 2; p * p <= num; ++p)
	{
		if (num % p == 0 && is_prime(p) && is_prime(num / p))
		{
			printf("%lu=%lu*%lu\n", num, num / p, p);
			return;
		}
	}
	printf("Couldn't find prime factors within limits for %lu\n", num);
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
		fprintf(stderr, "Usage: rsa <number>\n");
		exit(EXIT_FAILURE);
	}

	uint64_t num = atoll(av[1]);

	find_prime_factors(num);

	return (0);
}
