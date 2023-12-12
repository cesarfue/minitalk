/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:30:09 by cesar             #+#    #+#             */
/*   Updated: 2023/11/15 11:23:33 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;
	size_t				i;

	pdest = dest;
	psrc = src;
	i = -1;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (pdest < psrc)
	{
		while (++i < n)
			pdest[i] = psrc[i];
	}
	else
	{
		while (++i < n)
			pdest[n - i - 1] = psrc[n - i - 1];
	}
	return (dest);
}
