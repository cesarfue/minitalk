/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 07:07:18 by cesar             #+#    #+#             */
/*   Updated: 2023/11/20 15:37:11 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **splat)
{
	size_t	i;

	i = 0;
	while (splat[i])
		free(splat[i++]);
	free(splat);
	return (NULL);
}

static char	*ft_strndup(char const *src, size_t n)
{
	size_t		i;
	char		*dest;

	i = 0;
	while (src[i] && i < n)
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	ft_countwords(char const *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static size_t	wordlen(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *str, char c)
{
	char		**splat;
	size_t		i;
	size_t		l;

	i = 0;
	l = 0;
	if (!str)
		return (NULL);
	splat = malloc(sizeof(char *) * (ft_countwords(str, c) + 1));
	if (!splat)
		return (NULL);
	while (str[i])
	{
		if (str[i] != c)
		{
			splat[l] = ft_strndup(&str[i], wordlen(&str[i], c));
			if (!splat[l++])
				return (ft_free(splat));
			i += wordlen(&str[i], c);
		}
		else
			i++;
	}
	splat[l] = NULL;
	return (splat);
}
