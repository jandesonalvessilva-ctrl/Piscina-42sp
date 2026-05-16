/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaalves- <jaalves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 03:46:50 by jaalves-          #+#    #+#             */
/*   Updated: 2026/04/12 05:21:02 by jaalves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_grid(int grid[4][4])
{
	int line; 
	int col;
	char c;

	line = 0;
	while (line < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = grid[line][col] + '0';
			write(1, &c, 1);
			if (col < 3)
				write(1," ",1);
			col++;
		}
		write(1, "\n", 1);
		line ++;
	}
}

int main(void)
{
	int grid[4][4] =
	{
		{1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 1, 2},
		{4, 1, 2, 3}
	};
	ft_print_grid(grid);
	return(0);
}		
