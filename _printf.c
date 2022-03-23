#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	int i;
	va_list ap;
	char buff[100], temp[100];
	char *str;
	int j = 0;

	va_start(ap, format);

	i = 0;
	while (format[i] != '\0' && format != NULL)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c': {
				buff[j] = va_arg(ap, int);
				j++;
				break;
				}
				case 's': {
				str = va_arg(ap, char*);
				strcpy(&buff[j], str);
				j = j + strlen(str);
				break;
				}
				case 'd': {
				_itoa(va_arg(ap, int), temp, 10);
				strcpy(&buff[j], temp);
				j = j + strlen(temp);
				break;
				}
				case 'i': {
				_itoa(va_arg(ap, int), temp, 10);
				strcpy(&buff[j], temp);
				j = j + strlen(temp);
				break;
				}
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	write(1, buff, j);
	va_end(ap);
	return (j);
}
