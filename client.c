/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:03 by cesar             #+#    #+#             */
/*   Updated: 2023/12/04 13:21:36 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig2(int sig)
{
	(void) sig;
	printf("Caught SIGUSR2 signal\n");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		printf("No PID provided");
	int pid = atoi(argv[1]);
	signal(SIGUSR2, handle_sig2);
	if (kill(pid, SIGUSR1) == -1)
	{
		printf("Failed to send signal to process %d\n", pid);
		return (1);
	}
	return (0);
}