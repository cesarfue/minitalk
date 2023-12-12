/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:54:56 by cesar             #+#    #+#             */
/*   Updated: 2023/11/20 17:35:05 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_oversign(int x)
{
	if (x == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		x;
	long	nb;

	i = 0;
	x = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (LONG_MAX / 10 < nb || LONG_MAX - (str[i] - '0') < nb * 10)
			return (ft_oversign(x));
		nb = nb * 10 + (str[i++] - '0');
	}
	return (nb * x);
}
