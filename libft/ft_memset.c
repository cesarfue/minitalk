/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:10:42 by cesar             #+#    #+#             */
/*   Updated: 2023/11/15 11:20:00 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	ps = s;
	i = 0;
	while (i < n)
	{
		ps[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
