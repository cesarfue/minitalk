/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:03 by cesar             #+#    #+#             */
/*   Updated: 2023/12/12 11:18:24 by cesar            ###   ########.fr       */
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

void	binradio(pid_t id, char *str)
{
	char			*bin;
	ssize_t			i;
	ssize_t			j;

	i = -1;
	while (str[++i])
	{
		bin = to_bin((unsigned char)str[i]);
		j = -1;
		while (bin[++j])
		{
			if (bin[j] == '0')
			{
				if (kill(id, SIGUSR1) == -1)
					quit("SIGUSR1 not sent");
			}
			else if (bin[j] == '1')
				if (kill(id, SIGUSR2) == -1)
					quit("SIGUSR2 not sent");
			usleep(100);
		}
		free(bin);
	}
}

int	main(int argc, char **argv)
{
	pid_t	id;
	char	*msg;

	if (argc != 3 || !argv[1] || !argv[2])
		quit("Invalid arguments");
	id = ft_atoi(argv[1]);
	msg = argv[2];
	binradio(id, msg);
	return (0);
}






