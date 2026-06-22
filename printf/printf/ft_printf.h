/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaalves- <jaalves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:00:20 by jaalves-          #+#    #+#             */
/*   Updated: 2026/06/17 11:00:21 by jaalves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_pf(int n);
int	ft_putunbr_pf(unsigned int n);
int	ft_puthex_pf(unsigned long n, char format);

#endif
