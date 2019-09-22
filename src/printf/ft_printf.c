#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "unistd_compat.h"
#include "ft_printf.h"

t_printf_handler g_handler_tab[] =
		{
				{"d", &printf_handler_d, "int",   sizeof(int)},
				{"s", &printf_handler_s, "char*", sizeof(char *)},
				{"c", &printf_handler_c, "char",  4/*sizeof(char)*/}
		};

t_printf_handler *get_handler(char **p)
{
	int i;
	char r[8];

	(*p)++;
	r[0] = **p;
	r[1] = 0;
	(*p)++;
	i = -1;
	while (++i < (int) (sizeof(g_handler_tab) / sizeof(t_printf_handler)))
		if (!ft_strcmp(r, g_handler_tab[i].literal))
			return (&(g_handler_tab[i]));
	return (0);
}

void ft_printf_make_print(const char *format, va_list ap)
{
	ft_printf_arg arg;
	t_printf_handler *h;
	char *ptr;
	char *ptr1;

	ptr = (char *) format;
	ptr1 = ptr;
	while ((ptr = ft_strchr(ptr, '%')))
	{
		write(1, ptr1, ptr - ptr1);
		h = get_handler(&ptr);
		arg = va_arg(ap, ft_printf_arg);
		h->f(arg);
		ptr1 = ptr;
	}
	ft_putstr(ptr1);
}

void ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	ft_printf_make_print(format, ap);
	va_end(ap);
}