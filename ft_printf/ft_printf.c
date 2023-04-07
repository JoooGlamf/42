/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soojoo <soojoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:14:21 by soojoo            #+#    #+#             */
/*   Updated: 2023/04/05 10:32:32 by soojoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(const char *format, va_list ap, int i)
{
	if (format[i] == 'c')
		return (print_char(va_arg(ap, int)));
	else if (format[i] == 's')
		return (print_str(va_arg(ap, char *)));
	else if (format[i] == 'p')
		return (print_pointer(va_arg(ap, void *)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (print_int(va_arg(ap, int)));
	else if (format[i] == 'u')
		return (print_int_unsigned(va_arg(ap, unsigned int)));
	else if (format[i] == 'x' || format[i] == 'X')
		return (print_hex(format[i], va_arg(ap, int)));
	else if (format[i] == '%')
		return (print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		output;
	int		print_format_output;
	int		i;

	va_start(ap, format);
	i = 0;
	output = 0;
	while (format[i])
	{
		if (format[i] == '%')
			print_format_output = print_format(format, ap, ++i);
		else
			print_format_output = write(1, format + i, 1);
		if (print_format_output == -1)
			return (-1);
		output += print_format_output;
		++i;
	}
	va_end(ap);
	return (output);
}
