/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:21:56 by cesar             #+#    #+#             */
/*   Updated: 2023/12/13 08:36:09 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t		i;
	ssize_t		ret;
	ssize_t		*p_ret;
	va_list		args;

	if (!format)
		return (-1);
	va_start(args, format);
	ret = 0;
	p_ret = &ret;
	i = 0;
	while (format[i] && ret != -1)
	{
		if (format[i] == '%' && format[i + 1])
			switch_strings(format[++i], args, p_ret);
		else if (format[i] == '%' && !format[i + 1])
			return (ret = -1);
		else
			ft_pf_putchar(format[i], p_ret);
		i++;
	}
	va_end(args);
	return (ret);
}
