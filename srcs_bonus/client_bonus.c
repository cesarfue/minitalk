/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:47:52 by cesar             #+#    #+#             */
/*   Updated: 2023/12/11 21:50:47 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"


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

void	sendend(pid_t id)
{
	ssize_t	i;

	i = -1;
	while (++i < 8)
		if (!kill(id, SIGUSR1))
			quit("Signal not sent");
}

void	binradio(pid_t id, char *str)
{
	char			*bin;
	ssize_t			i;
	ssize_t			j;

	i = 0;
	while (str[i])
	{
		bin = to_bin((unsigned char)str[i++]);
		j = -1;
		while (bin[++j])
		{
			if (bin[j] == '0')
			{
				if (!kill(id, SIGUSR1))
					quit("Signal not sent");
			}
			else if (bin[j] == '1')
				if (!kill(id, SIGUSR2))
					quit("Signal not sent");
			usleep(10);
		}
		free(bin);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !argv[1] || !argv[2])
		quit("Invalid arguments");
	binradio(ft_atoi(argv[1]), argv[2]);
	return (0);
}