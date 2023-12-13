/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:10:15 by cesar             #+#    #+#             */
/*   Updated: 2023/12/13 08:16:07 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ps1;
	const unsigned char	*ps2;
	size_t				i;

	i = 0;
	ps1 = s1;
	ps2 = s2;
	while ((ps1 + i || ps2[i]) && i < n)
	{
		if ((unsigned char)ps1[i] != (unsigned char)ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((int)(ps1[i] - ps2[i]));
}
