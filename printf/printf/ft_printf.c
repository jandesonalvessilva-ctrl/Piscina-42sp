/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaalves- <jaalves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:00:44 by jaalves-          #+#    #+#             */
/*   Updated: 2026/06/17 13:21:27 by jaalves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_pf(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += ft_puthex_pf(ptr, 'x');
	return (count);
}

static int	handle_format(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_putchar_pf(va_arg(*args, int)));
	if (specifier == 's')
		return (ft_putstr_pf(va_arg(*args, char *)));
	if (specifier == 'p')
		return (ft_putptr_pf(va_arg(*args, unsigned long)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_pf(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_putunbr_pf(va_arg(*args, unsigned int)));
	if (specifier == 'x')
		return (ft_puthex_pf(va_arg(*args, unsigned int), 'x'));
	if (specifier == 'X')
		return (ft_puthex_pf(va_arg(*args, unsigned int), 'X'));
	if (specifier == '%')
		return (ft_putchar_pf('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (count);
			count += handle_format(format[i], &args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
