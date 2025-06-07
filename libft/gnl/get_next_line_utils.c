/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:36:06 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/12/04 20:40:38 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		while (str[i] != '\0')
		{
			i++;
		}
		return (i);
	}
	else
		return (0);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		tsize;
	char	*str;

	i = 0;
	if (!s1 || !s2)
		return (0);
	tsize = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(tsize + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (! ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i++] = 0;
	}
	return (ptr);
}
