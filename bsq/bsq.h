/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-c <ggomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:32:48 by ggomes-c          #+#    #+#             */
/*   Updated: 2026/04/22 22:37:59 by ggomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_best
{
	int	size;
	int	row;
	int	col;
}	t_best;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

// ft_utils.c
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2);

char	*ft_read(char *filename);
char	*ft_read_stdin(void);

int		ft_parse_first_line(char *content, t_map *map);
int		ft_build_grid(char *content, t_map *map);
int		ft_validate(t_map *map);
void	ft_print(t_map *map);

int		ft_check_square(t_map *map, int row, int col, int size);
void	ft_draw(t_map *map, int row, int col, int size);
int		ft_max_square_from_pos(t_map *map, int row, int col, int current_best);
void	ft_process_cell(t_map *map, int row, int col, t_best *best);
void	ft_algorithm(t_map *map);

#endif