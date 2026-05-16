/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaalves- <jaalves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:48:45 by jaalves-          #+#    #+#             */
/*   Updated: 2026/04/04 21:56:42 by jaalves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	lin;
	int	col;

	lin = 0;
	col = 0;
	while (lin < y)
	{
		col = 0;
		while (col < x)
		{
			if ((col == 0 || col == x - 1) && (lin == 0 || lin == (y - 1)))
				ft_putchar('o');
			else if (col == 0 || col == x - 1)
				ft_putchar('|');
			else if (lin == 0 || lin == y - 1)
				ft_putchar('-');
			else
				ft_putchar(' ');
			col++;
		}
		write(1, "\n", 1);
		lin++;
	}
}
