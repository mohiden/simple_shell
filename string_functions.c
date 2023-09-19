#include "shell.h"

/**
 * long_to_string - converts a number to a string.
 * @number: number to be converten in an string.
 * @string: buffer to save the number as string.
 * @base: base to convert number
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *string, int base)
{
	int i = 0, Neg = 0;
	long c = number;
	char letters[] = {"0123456789abcdef"};

	if (c == 0)
		string[i++] = '0';

	if (string[0] == '-')
		Neg = 1;

	while (c)
	{
		if (c < 0)
			string[i++] = letters[-(c % base)];
		else
			string[i++] = letters[c % base];
		c /= base;
	}
	if (Neg)
		string[i++] = '-';

	string[i] = '\0';
	str_reverse(string);
}


/**
 * _atoi - convert a string to an integer.
 *
 * @s: pointer to str origin.
 * Return: int of string or 0.
 */

int _atoi(char *s)
{
	int t = 1;
	unsigned int number = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			t *= -1;
		if (*s == '+')
			t *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * t);
}

/**
 * count_char - count the coincidences of character in string.
 *
 * @string: pointer to str origen.
 * @c: string with  chars to be counted
 * Return: int of string or 0.
 */

int count_char(char *string, char *c)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == c[0])
			counter++;
	}
	return (counter);
}
