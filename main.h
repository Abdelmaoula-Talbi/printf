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
void print_rev(char *s);
int _printf(const char *format, ...);
int pr_char(va_list c);
int pr_string(va_list str);
char *_itoa(int n, char *);
int pr_integer(va_list i);

#endif
