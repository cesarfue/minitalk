/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:06 by cesar             #+#    #+#             */
/*   Updated: 2023/12/08 08:28:37 by cesar            ###   ########.fr       */
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
		i = 0;
		ret = 0;
	}
}


int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &radiobin;
	printf("Server PID is %i\n", getpid());
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		usleep(100);
	return (0);
}