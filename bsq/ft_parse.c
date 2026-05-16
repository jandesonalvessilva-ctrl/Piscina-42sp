/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-c <ggomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:29:13 by ggomes-c          #+#    #+#             */
/*   Updated: 2026/04/22 22:29:21 by ggomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_parse_first_line(char *content, t_map *map)
{
	int	i;

	i = 0;
	map->rows = ft_atoi(content);
	if (map->rows <= 0)
		return (0);
	while (content[i] >= '0' && content[i] <= '9')
		i++;
	if (!content[i] || !content[i + 1] || !content[i + 2])
		return (0);
	map->empty = content[i];
	map->obstacle = content[i + 1];
	map->full = content[i + 2];
	return (1);
}

static int	ft_fill_row(char *content, t_map *map, int row, int *i)
{
	int	col;

	map->grid[row] = malloc(sizeof(char) * (map->cols + 1));
	if (!map->grid[row])
		return (0);
	col = 0;
	while (col < map->cols && content[*i] && content[*i] != '\n')
	{
		map->grid[row][col] = content[*i];
		col++;
		(*i)++;
	}
	map->grid[row][col] = '\0';
	if (content[*i] == '\n')
		(*i)++;
	return (1);
}

int	ft_build_grid(char *content, t_map *map)
{
	int	i;
	int	row;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	map->cols = 0;
	while (content[i + map->cols] && content[i + map->cols] != '\n')
		map->cols++;
	if (map->cols == 0)
		return (0);
	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (0);
	row = 0;
	while (row < map->rows)
	{
		if (!ft_fill_row(content, map, row, &i))
			return (0);
		row++;
	}
	return (1);
}

int	ft_validate(t_map *map)
{
	int	line;
	int	col;

	line = 0;
	while (line < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			if (map->grid[line][col] != map->empty
				&& map->grid[line][col] != map->obstacle)
				return (0);
			col++;
		}
		line++;
	}
	return (1);
}

void	ft_print(t_map *map)
{
	int	line;

	line = 0;
	while (line < map->rows)
	{
		write(1, map->grid[line], ft_strlen(map->grid[line]));
		write(1, "\n", 1);
		line++;
	}
}
