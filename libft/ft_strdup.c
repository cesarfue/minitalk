/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:38:12 by cesar             #+#    #+#             */
/*   Updated: 2023/11/14 12:28:34 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	size_t		out_len;
	char		*out;

	i = 0;
	out_len = ft_strlen(s);
	out = malloc(sizeof(char) * out_len + 1);
	if (!out)
		return (NULL);
	while (i < out_len)
	{
		out[i] = s[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
