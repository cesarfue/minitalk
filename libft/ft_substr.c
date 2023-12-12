/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:24:23 by cesar             #+#    #+#             */
/*   Updated: 2023/11/20 08:38:57 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*out;
	size_t			i;
	size_t			size;

	i = 0;
	size = ft_strlen(s);
	if (start >= size)
		len = 0;
	else if (len > (size - start))
		len = size - start;
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
