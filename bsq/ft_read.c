/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-c <ggomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:27:13 by ggomes-c          #+#    #+#             */
/*   Updated: 2026/04/22 22:28:32 by ggomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_read(char *filename)
{
	char	buffer[1024];
	char	*result;
	char	*temp;
	int		fd;
	int		bytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	result = ft_strjoin("", "");
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, 1023);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		temp = result;
		result = ft_strjoin(temp, buffer);
		free(temp);
	}
	close(fd);
	return (result);
}

char	*ft_read_stdin(void)
{
	char	buffer[1024];
	char	*result;
	char	*temp;
	int		bytes;

	result = ft_strjoin("", "");
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(0, buffer, 1023);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		temp = result;
		result = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (result);
}
