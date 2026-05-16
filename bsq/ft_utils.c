/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-c <ggomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 22:14:47 by ggomes-c          #+#    #+#             */
/*   Updated: 2026/04/22 22:26:54 by ggomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result_atoi;

	i = 0;
	result_atoi = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result_atoi = result_atoi * 10 + (str[i] - '0');
		i++;
	}
	return (result_atoi);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(result, s1);
	ft_strcpy(result + ft_strlen(s1), s2);
	return (result);
}
