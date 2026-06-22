/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaalves- <jaalves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:01:06 by jaalves-          #+#    #+#             */
/*   Updated: 2026/06/17 12:24:12 by jaalves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_pf(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_putnbr_pf(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += ft_putchar_pf('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_pf(n / 10);
	count += ft_putchar_pf(n % 10 + '0');
	return (count);
}

int	ft_putunbr_pf(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr_pf(n / 10);
	count += ft_putchar_pf(n % 10 + '0');
	return (count);
}

int	ft_puthex_pf(unsigned long n, char format)
{
	int		count;
	char	*base;

	count = 0;
	if (n >= 16)
		count += ft_puthex_pf(n / 16, format);
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count += ft_putchar_pf(base[n % 16]);
	return (count);
}
