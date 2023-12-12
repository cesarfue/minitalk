/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:47:20 by cesar             #+#    #+#             */
/*   Updated: 2023/12/12 16:55:11 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	radiobin(int sig, siginfo_t *info, void *ucontent)
{
	static size_t	i = 0;
	static int		ret = 0;
	int				bin;

	(void)ucontent;
	if (sig == SIGUSR1)
		bin = 0;
	else
		bin = 1;
	ret = (ret << 1) | bin;
	i++;
	if (i == 8)
	{
		if (ret == 0)
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
				quit("Client couldn't be reached");
		}
		else
			write(1, &ret, 1);
		i = 0;
		ret = 0;
	}
}

void sigconfig(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &radiobin;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		quit("No action taken for SIGUSR1");
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		quit("No action taken for SIGUSR2");

}

int	main(void)
{
	printf("Server PID is %i\n", getpid());
	while(1)
		sigconfig();
	return (0);
}
