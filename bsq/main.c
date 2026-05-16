/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-c <ggomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:24:05 by ggomes-c          #+#    #+#             */
/*   Updated: 2026/04/22 22:24:47 by ggomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_process_map(char *content)
{
	t_map	map;

	if (!ft_parse_first_line(content, &map))
	{
		write(1, "map error\n", 10);
		return ;
	}
	if (!ft_build_grid(content, &map))
	{
		write(1, "map error\n", 10);
		return ;
	}
	if (!ft_validate(&map))
	{
		write(1, "map error\n", 10);
		return ;
	}
	ft_algorithm(&map);
	ft_print(&map);
}

void	ft_handle_files(int argc, char **argv)
{
	char	*content;
	int		i;

	i = 1;
	while (i < argc)
	{
		content = ft_read(argv[i]);
		if (!content)
			write(1, "map error\n", 10);
		else
			ft_process_map(content);
		if (i + 1 < argc)
			write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_process_map(ft_read_stdin());
	else
		ft_handle_files(argc, argv);
	return (0);
}
