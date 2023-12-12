/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:12:28 by cesar             #+#    #+#             */
/*   Updated: 2023/12/12 11:15:00 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	quit(char *quit_msg)
{
	write(STDERR_FILENO, "\nError: ", 9);
	write(STDERR_FILENO, quit_msg, ft_strlen(quit_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
