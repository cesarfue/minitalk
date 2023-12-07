/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:21:06 by cesar             #+#    #+#             */
/*   Updated: 2023/12/07 16:15:39 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"


size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	endset(char *bin_str)
{
	size_t	i;
	size_t	zeros; 

	if (!bin_str)
		return (-1);
	zeros = 0;
	i = ft_strlen(bin_str);
	if (i >= 8)
	{
		i--;
		while (bin_str[i] == '0' && zeros++ < 8)
			i--;
		if (zeros == 8)
			return (1);
	}
	return (0);
}

char	*charjoin(char *str, char c)
{
	size_t	i;
	char	*tmp;

	if (str)
		tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	else if (!str)
		tmp = malloc(sizeof(char) * 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = 0;
	free(str);
	return (tmp);
}

char	from_bin_char(char *bin_char)
{
	int		ret;
	size_t	j;

	ret = 0;
	j = 0;
	printf("l72\n");
	while (j < 8)
		ret = ret * 2 + (bin_char[j++] - '0');
	return ((char)ret);
}

char	*from_bin(char *bin_str)
{
	char	*str;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	str = malloc((ft_strlen(bin_str) / 8 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (bin_str[i])
	{
		printf("l87\n");
		str[k++] = from_bin_char(&bin_str[i]);
		i += 8;
	}
	str[k] = 0;
	return (str);
}

void	radiobin(int sig)
{
	static char	*bin_str;
	char		*str;

	if (bin_str && endset(bin_str))
	{
		str = from_bin(bin_str);
		printf("str is %s\n", str);  ///////////////		
		printf("bin_str is %s\n", bin_str);  ///////////////
		free(bin_str);
		free(str);
		exit(0);
	}
	else if (sig == 10)
		bin_str = charjoin(bin_str, '0');
	else if (sig == 12)
		bin_str = charjoin(bin_str, '1');
	return ;
}

int	main(void)
{
	printf("Server PID is %i\n", getpid()); ///////////

	while (1)
	{
		signal(SIGUSR1, radiobin);
		signal(SIGUSR2, radiobin);
	}
	return (0);
}