/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:06 by cesar             #+#    #+#             */
/*   Updated: 2023/12/11 15:12:35 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	radiobin(int sig)
{
	static size_t	i = 0;
	static int		ret = 0;
	int				bin;

	if (sig == SIGUSR1)
		bin = 0;
	else
		bin = 1;
	ret = (ret << 1) | bin;
	i++; 
	if (i == 8)
	{
		write(1, &ret, 1);
		if (ret == '\0')
			write(1, "Message received\n", 18);
		i = 0;
		ret = 0;
	}
}


int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &radiobin;
	printf("Server PID is %i\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
	}
	return (0);
}