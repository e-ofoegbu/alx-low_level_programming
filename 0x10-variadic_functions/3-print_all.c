#include "variadic_functions.h"


void print_string(va_list list)
{
	char *aux;

	aux = va_arg(list, char*);
	if (aux == NULL)
	{
		printf("(nil)");
		return;
	}

	printf("%s", aux);
}


void print_integer(va_list list)
{
	printf("%i", va_arg(list, int));
}


void print_float(va_list list)
{
	printf("%f", va_arg(list, double));
}


void print_char(va_list list)
{
	printf("%c", va_arg(list, int));
}


void print_all(const char * const fmt, ...)
{
	va_list args;
	int i, j;
	char *str = "";
	p_opt ops[] = {
		{"s", print_string},
		{"i", print_integer},
		{"f", print_float},
		{"c", print_char}
	};

	va_start(args, fmt);

	i = j = 0;
	while (fmt != NULL && fmt[i] != 0)
	{

		while (j < 4)
		{
			if (fmt[i] == *(ops[j].op))
			{
				printf("%s", str);
				ops[j].f(args);
				str = ", ";
				break;
			}

			j++;
		}
		j = 0;

		i++;
	}

	printf("\n");
	va_end(args);
}
