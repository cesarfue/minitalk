/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:03 by cesar             #+#    #+#             */
/*   Updated: 2023/12/07 15:29:53 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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


ssize_t	binradio(pid_t id, char *str)
{
	char			*bin;
	ssize_t			i;
	ssize_t			j;

	i = 0;
	while (str[i])
	{
		bin = to_bin((unsigned char)str[i]);
		printf("%s\n", bin);
		j = -1;
		while (bin[++j])
		{
			if (bin[j] == '0')
				kill(id, SIGUSR1);
			else if (bin[j] == '1')
				kill(id, SIGUSR2);
			usleep(10);
		}
		free(bin);
		i++;
	}
	i = -1;
	while (++i <= 8)
		kill(id, SIGUSR1);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				id;
	char		*str;

	if (argc != 3 || !argv[1] || !argv[2])
		return (-1);
	id = atoi(argv[1]);
	str = argv[2];
	if (!binradio(id, str))
		return (-1);
	return (0);
}
