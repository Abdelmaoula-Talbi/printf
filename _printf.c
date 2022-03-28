#include "main.h"
#include <unistd.h>
#include <stddef.h>

/**
 * _printf - produces output according to format and write output to stdout.
 * @format: character string composed of zero or more directives.
 * Return: the number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	pr_t prs[] = {
		{"c", pr_char},
		{"s", pr_string},
		{"d", pr_integer},
		{"i", pr_integer},
		{NULL, NULL}
	};
	int i, j, char_count = 0;
	va_list ap;

	va_start(ap, format);
	i = 0;

	if (format == NULL)
		return (-1);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] != '%' && format[i - 1] != '%')
		{
			write(1, &format[i], 1);
			char_count++;
		}
		else if (format[i] == '%')
		{
			j = 0;
			while (prs[j].c != NULL)
			{
				if (format[i + 1] == *(prs[j].c))
				{
					char_count += prs[j].func(ap);
					break;
				}
				else if (format[i + 1] != 'c' && format[i + 1] != 's')
				{
					if (format[i + 1] == '%')
					{
						write(1, &format[i + 1], 1);
						char_count++;
						break;
					}
					else if (format[i + 1] == ' ')
					{
						write(1, &format[i + 1], 1);
						char_count++;
						break;
					}
				}
				j++;
			}
		}
	i++;
	}
	va_end(ap);
	return (char_count);
}
