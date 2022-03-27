#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * pr_char - print a char to stdout.
 * @c: argument char to print.
 * @count: number of characters printed.
 * Return: count.
 */
int pr_char(va_list c)
{
	int count = 0;
	char ch = va_arg(c, int);

	write(1, &ch, 1);
	count += 1;
	return (count);
}

/**
 * pr_string - print a string to the stdout.
 * @str: argument string to print.
 * @count: number of characters in the string printed.
 * Return: count.
 */
int pr_string(va_list str)
{
	int count = 0;
	char *s;

	s = va_arg(str, char *);
	if (s == NULL)
	{
		return (NULL);
	}
	write(1, s, strlen(s));
	count += strlen(s);
	return (count);
}
