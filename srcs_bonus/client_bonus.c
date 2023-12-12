/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:47:52 by cesar             #+#    #+#             */
/*   Updated: 2023/12/12 17:13:13 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	end_sig(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Message transmitted\n", 21);
		exit(0);
	}
}

char	*to_bin(int n)
{
	ssize_t		i;
	char		*str;

	i = 8;
	str = (char *)malloc(9 * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = 0;
	while (--i >= 0)
	{
		str[i] = n % 2 + '0';
		n /= 2;
	}
	return (str);
}

void	binradio(pid_t id, char c)
{
	char			*bin;
	ssize_t			j;

	bin = to_bin((unsigned char)c);
	j = -1;
	while (bin[++j])
	{
		if (bin[j] == '0')
		{
			if (kill(id, SIGUSR1) == -1)
				quit("SIGUSR1 not sent");
		}
		else if (bin[j] == '1')
		{
			if (kill(id, SIGUSR2) == -1)
				quit("SIGUSR2 not sent");
		}
		usleep(100);
	}
	free(bin);
}

void	sigconfig(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &end_sig;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		quit("No action taken for SIGUSR1");
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		quit("No action taken for SIGUSR2");
}

int	main(int argc, char **argv)
{
	pid_t				id;
	ssize_t				i;
	char				*msg;

	if (argc != 3 || !argv[1] || !argv[2])
		quit("Invalid arguments");
	id = ft_atoi(argv[1]);
	msg = argv[2];
	i = -1;
	while (msg[++i])
		binradio(id, msg[i]);
	binradio(id, '\0');
	while (1)
		sigconfig();
	return (0);
}
