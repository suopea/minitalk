/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuopea <ssuopea@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:47:33 by ssuopea           #+#    #+#             */
/*   Updated: 2025/05/29 15:57:19 by ssuopea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	select_substitution(const char flag, va_list *args);
static int	print_char(char c);
static int	print_string(char *s);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed_total;
	int		printed_last;

	i = -1;
	printed_total = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[++i])
	{
		if (str[i] != '%')
			printed_last = write(1, str + i, 1);
		else
		{
			printed_last = select_substitution(str[i + 1], &args);
			i++;
		}
		if (printed_last == -1)
			return (-1);
		printed_total += printed_last;
	}
	va_end(args);
	return (printed_total);
}

static int	select_substitution(const char flag, va_list *args)
{
	if (flag == 'c')
		return (print_char((char) va_arg(*args, int)));
	if (flag == 's')
		return (print_string((char *) va_arg(*args, int *)));
	if (flag == 'd' || flag == 'i')
		return (print_base(va_arg(*args, int), "0123456789"));
	if (flag == 'u')
		return (print_base(va_arg(*args, unsigned), "0123456789"));
	if (flag == 'x')
		return (print_base(va_arg(*args, unsigned), "0123456789abcdef"));
	if (flag == 'X')
		return (print_base(va_arg(*args, unsigned), "0123456789ABCDEF"));
	if (flag == 'p')
		return (print_pointer((unsigned long long) va_arg(*args, void *)));
	if (flag == '%')
		return (write(1, "%", 1));
	return (-1);
}

static int	print_char(char c)
{
	return (write(1, &c, 1));
}

static int	print_string(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}
