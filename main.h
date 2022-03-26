#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct print_t - structure to define corresponding function to print.
 * @c: the type to print.
 * @func: the function associated to the type.
 */

typedef struct print_t
{
	char *c;
	int (*func)(va_list);
} pr_t;

int _printf(const char *format, ...);
int pr_char(va_list c);
int pr_string(va_list str);

#endif
