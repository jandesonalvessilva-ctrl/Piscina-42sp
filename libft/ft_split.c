/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaalves- <jaalves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:14:19 by jaalves-          #+#    #+#             */
/*   Updated: 2026/06/02 13:26:44 by jaalves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	count;
	int	words;

	count = 0;
	words = 0;
	while (*s)
	{
		if (*s != c && words == 0)
		{
			words = 1;
			count++;
		}
		else if (*s == c)
			words = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *start, const char *end)
{
	size_t	len;
	char	*new_str;

	len = end - start;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, start, len + 1);
	return (new_str);
}

static void	free_split(char **result, int words)
{
	if (result == NULL)
		return ;
	while (words > 0)
	{
		free(result[words - 1]);
		words--;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	int			i;
	const char	*start;

	if (!s)
		return (NULL);
	i = 0;
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			split[i] = word_dup(start, s);
			if (!split[i++])
				return (free_split(split, i - 1), NULL);
		}
		else
			s++;
	}
	return (split[i] = NULL, split);
}
