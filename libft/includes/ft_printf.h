/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:46:43 by cesar             #+#    #+#             */
/*   Updated: 2023/12/12 17:43:12 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
ssize_t	switch_strings(const char c, va_list args, ssize_t *p_ret);
ssize_t	switch_decimals(const char c, va_list args, ssize_t *p_ret);
ssize_t	switch_hexa(const char c, va_list args, ssize_t *p_ret);
ssize_t	switch_else(const char c, ssize_t *p_ret);

ssize_t	ft_pf_putchar(char c, ssize_t *p_ret);
ssize_t	ft_pf_putstr(char *s, ssize_t *p_ret);
ssize_t	ft_pf_putnbr(long n, ssize_t *p_ret);
ssize_t	ft_pf_putptr(uintptr_t p_ptr, ssize_t *p_ret);
ssize_t	ft_pf_putptrlow(unsigned int x_ptr, ssize_t *p_ret);
ssize_t	ft_pf_putptrhigh(unsigned int x_ptr, ssize_t *p_ret);

size_t	ft_pf_strlen(const char *str);
size_t	ft_intlen(int n);
int		ft_pf_strchr(const char *s, char c);

#endif