/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaalves- <jaalves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:54:03 by jaalves-          #+#    #+#             */
/*   Updated: 2026/06/02 13:27:43 by jaalves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	str_size;
	void	*ptr;
	void	*result;

	if (s1 == NULL)
		return (NULL);
	str_size = ft_strlen(s1);
	ptr = malloc(str_size + 1);
	if (ptr == NULL)
		return (NULL);
	result = ft_memcpy(ptr, s1, str_size + 1);
	return ((char *)result);
}
