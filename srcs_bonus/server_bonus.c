/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:47:20 by cesar             #+#    #+#             */
/*   Updated: 2023/12/12 11:14:34 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	radiobin(int sig, siginfo_t *info, void *ucontent)
{
	static size_t	i = 0;
	static int		ret = 0;
	int				bin;

	(void)ucontent;
	(void)info;
	if (sig == SIGUSR1)
		bin = 0;
	else if (sig == SIGUSR2)
		bin = 1;
	ret = (ret << 1) | bin;
	i++;
	if (i == 8)
	{
		if (!ret)
			quit("Received signal");
		write(1, &ret, 1);
		i = 0;
		ret = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &radiobin;
	sa.sa_flags = SA_SIGINFO;
	printf("Server PID is %i\n", getpid());
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		quit("No action taken for SIGUSR1");
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		quit("No action taken for SIGUSR2");
	while (1)
		pause();
	return (0);
}
