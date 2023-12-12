/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:47:20 by cesar             #+#    #+#             */
/*   Updated: 2023/12/11 21:42:49 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	radiobin(int sig, siginfo_t *info, void *ucontent)
{
	static size_t	i = 0;
	static int		ret = 0;
	int				bin;

	(void)ucontent
	if (sig == SIGUSR1)
		bin = 0;
	else if (sig == SIGUSR2)
		bin = 1;
	ret = (ret << 1) | bin;
	i++;
	if (i == 8)
	{
		write(1, &ret, 1);
		if (ret == 0)
			if (!(kill(info->si_pid, SIGUSR1)))
				quit("Signal not sent");
		i = 0;
		ret = 0;
	}
}


int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &radiobin;
	printf("Server PID is %i\n", getpid());
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, 0) == -1)
			quit("Signal not sent");
		if (sigaction(SIGUSR2, &sa, 0) == -1)
			quit("Signal not sent");
	}
	return (0);
}
