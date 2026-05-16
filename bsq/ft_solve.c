/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-c <ggomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:30:53 by ggomes-c          #+#    #+#             */
/*   Updated: 2026/04/22 22:31:59 by ggomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_square(t_map *map, int row, int col, int size)
{
	int	i;
	int	j;

	i = row;
	while (i < row + size)
	{
		j = col;
		while (j < col + size)
		{
			if (map->grid[i][j] == map->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_draw(t_map *map, int row, int col, int size)
{
	int	i;
	int	j;

	i = row;
	while (i < row + size)
	{
		j = col;
		while (j < col + size)
		{
			map->grid[i][j] = map->full;
			j++;
		}
		i++;
	}
}

int	ft_max_square_from_pos(t_map *map, int row, int col, int current_best)
{
	int	size;
	int	max_possible;

	if (map->rows - row < map->cols - col)
		max_possible = map->rows - row;
	else
		max_possible = map->cols - col;
	size = max_possible;
	while (size > current_best)
	{
		if (ft_check_square(map, row, col, size))
			return (size);
		size--;
	}
	return (0);
}

void	ft_process_cell(t_map *map, int row, int col, t_best *best)
{
	int	size;

	size = ft_max_square_from_pos(map, row, col, best->size);
	if (size > best->size)
	{
		best->size = size;
		best->row = row;
		best->col = col;
	}
}

void	ft_algorithm(t_map *map)
{
	int		row;
	int		col;
	t_best	best;

	best.size = 0;
	best.row = 0;
	best.col = 0;
	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			ft_process_cell(map, row, col, &best);
			col++;
		}
		row++;
	}
	if (best.size > 0)
		ft_draw(map, best.row, best.col, best.size);
}
