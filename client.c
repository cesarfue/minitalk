/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:03 by cesar             #+#    #+#             */
/*   Updated: 2023/12/06 13:15:48 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*to_bin(int n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)malloc(9 * sizeof(char));
	if (!str)
		return (NULL);
	str[8] = 0;
	while (i < 8)
	{
		str[i++] = n % 2 + '0';
		n /= 2;
	}
	return (str);
}

ssize_t	binradio(pid_t pid, const char *str)
{
	const char		*bin;
	ssize_t			i;
	ssize_t			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		bin = to_bin((unsigned char)str[i]);
		while (bin[j])
		{
			if (bin[j] == '0')
				signal(SIGUSR1, pid);
			else if (bin[j] == '1')
				signal(SIGUSR2, pid);
			j++;
		}
		free(bin);
		j = 0;
		i++;
	}
	i = -1;
	while (++i <= 8)
		signal(SIGUSR1, pid);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	const char		*str;

	if (argc != 3 || !argv[1] || !argv[2])
		return (-1);
	pid = atoi(argv[1]);
	str = argv[2];
	if (!binradio(pid, str))
		return (-1);
	return (0);
}
