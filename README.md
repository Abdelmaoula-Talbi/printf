# _printf: C function similar to the C standard function printf.


## Prototype

_printf(const char *format, ...);

## Overview

_printf is a C function similar to the standard C function printf that produces output according to a format string. I have to notice that many options of the C standard function printf are not present in the _printf function. The flag characters, the field width, the precision and the length modifiers are not provided too.

## Usage

include "main.h"

Upon successful return, it returns the number of characters printed.
On error, it returns a negative value.

## Format specifiers

%c : prints a character to the stdout.(corresponding function: pr_char in the file pr_func.c).


%s : prints an array of characters excluding the null byte character to the stdout. (corresponding function: pr_string in the file pr_func.c).

%d and %i : print an integer in the decimal base to the stdout. (corresponding function : pr_integer in the file pr_func.c).

%%: prints a percent symbol to the stdout. (corresponding function : _printf in the _printf.c file).

## Examples

1. #include "main.h"

int main(void)
{
	char ch = 'a';
	char *s = "test";
	int nbr = 1;

	_printf("This is %c %s number %d\n", ch, s, nbr);
	return (0);
}

Output:
This is a test number 1

2. _printf("%%"); --> prints the symbol %.

3. _printf("%i", 5); --> prints 5 to the stdout.

4. _printf("%s\n", "Hello worlD"); --> prints Hello worlD followed by a new line.


## Files used for the project

 _printf.c, pr_func.c, main.h.

## Github account

Github: https://github.com/AbdelmaoulaAbdou/printf

## About

Created and compiled on Ubuntu 20.04 LTS with gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

## Author

Abdelmaoula Talbi

