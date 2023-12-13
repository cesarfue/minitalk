/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:20:14 by cefuente          #+#    #+#             */
/*   Updated: 2023/12/13 08:36:09 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_pf_strchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_pf_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

ssize_t	ft_pf_putstr(char *s, ssize_t *p_ret)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6))
			return (*p_ret += 6);
		else
			return (*p_ret = -1);
	}
	while (s[i])
		i++;
	if (write(1, &s[0], i) == (ssize_t)i)
		(*p_ret += i);
	else
		return (*p_ret = -1);
	return (0);
}

ssize_t	ft_pf_putchar(char c, ssize_t *p_ret)
{
	if (write(1, &c, 1))
		(*p_ret)++;
	else
		return (*p_ret = -1);
	return (0);
}
