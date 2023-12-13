/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:42:34 by cesar             #+#    #+#             */
/*   Updated: 2023/12/13 08:36:09 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

ssize_t	switch_strings(const char c, va_list args, ssize_t *p_ret)
{
	if (c == 'c')
		ft_pf_putchar(va_arg(args, int), p_ret);
	else if (c == 's')
		ft_pf_putstr((char *)va_arg(args, char *), p_ret);
	else
		switch_decimals(c, args, p_ret);
	return (0);
}

ssize_t	switch_decimals(const char c, va_list args, ssize_t *p_ret)
{
	if (c == 'd' || c == 'i')
		ft_pf_putnbr(va_arg(args, int), p_ret);
	else if (c == 'u')
		ft_pf_putnbr((unsigned int)va_arg(args, int), p_ret);
	else
		switch_hexa(c, args, p_ret);
	return (0);
}

ssize_t	switch_hexa(const char c, va_list args, ssize_t *p_ret)
{
	uintptr_t		p_ptr;

	if (c == 'p')
	{
		p_ptr = (uintptr_t)va_arg(args, void *);
		if (!p_ptr)
		{
			ft_pf_putstr("(nil)", p_ret);
			return (-1);
		}
		ft_pf_putstr("0x", p_ret);
		ft_pf_putptr(p_ptr, p_ret);
	}
	else if (c == 'x')
		ft_pf_putptrlow((uintptr_t)va_arg(args, void *), p_ret);
	else if (c == 'X')
		ft_pf_putptrhigh((uintptr_t)va_arg(args, void *), p_ret);
	else
		switch_else(c, p_ret);
	return (0);
}

ssize_t	switch_else(const char c, ssize_t *p_ret)
{
	if (c == '%')
		ft_pf_putchar(c, p_ret);
	return (0);
}
