#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_rev(char *s)
{
	int i;
	int j;

	for (i = 0; s[i] != '\0'; i++)
	{
		i = i;
	}
	for (j = i - 1; j >= 0; j--)
	{
		write(1, &s[j], 1);
	}
}

char *_itoa(int n, char s[100])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	while ((n /= 10) > 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	print_rev(s);
	return (s);
}
	
/**
 * pr_char - print a char to stdout.
 * @c: argument char to print.
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
 * Return: count.
 */
int pr_string(va_list str)
{
	int count = 0;
	char *s;

	s = va_arg(str, char *);
	if (s == NULL)
	{
		s = "";
	}
	write(1, s, strlen(s));
	count += strlen(s);
	return (count);
}

/**
 * pr_integer - print a number in string format.
 * @n: argument number to print.
 * Return: count.
 */
int pr_integer(va_list i)
{
	int count = 0;
	int number = va_arg(i, int);
	char s[100];

	_itoa(number, s);
	write(1, s, strlen(s));
	count += strlen(s);
	return (count);
}
