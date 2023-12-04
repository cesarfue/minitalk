/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:06 by cesar             #+#    #+#             */
/*   Updated: 2023/12/04 13:19:19 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	client_pid;

void	handle_sig1(int sig)
{
	(void) sig;
	printf("Caught SIGUSR1\n");
	kill(client_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	client_pid = atoi(argv[1]);
	printf("Client PID is %i\n", client_pid);
	signal(SIGUSR1, handle_sig1);
	while (1)
		;
	return (0);
	
}