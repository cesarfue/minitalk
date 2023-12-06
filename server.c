/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:06 by cesar             #+#    #+#             */
/*   Updated: 2023/12/06 15:27:23 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	from_bin(char *bin_char)
{
	int		ret;

	ret = 0;
	while (*bin_char)
		ret = ret * 2 + (*bin_char++ - '0');
	return ((char)ret);
}

ssize_t	radiobin(int sig)
{
	size_t	i;
	char	bin_char[9];
	char	*str;

	i = 0;
	while (i < 8)
	{
		if (sig == 1)
			bin_char[i] = '0';
		else if (sig == 2)
			bin_char[i] = '1';
		else
			return (-1);
		i++;
	}
	i = 0;
	bin_char[8] = 0;
	str[i] = from_bin(bin_char);
	return (0);
}

int	main(void)
{
	pid_t id;
	id = getpid();
	printf("Server PID is %i\n", id);
	
	signal(SIGUSR1, radiobin(1));
	signal(SIGUSR2, radiobin(2));
	while (1)
		;
	return (0);
}