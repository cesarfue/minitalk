/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:34:57 by cesar             #+#    #+#             */
/*   Updated: 2023/12/13 10:20:44 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	pid_t				id;
	int					c;
	FILE				*file;

	if (argc != 3 || !argv[1] || !argv[2])
		quit("Invalid arguments");
	id = ft_atoi(argv[1]);
	file = fopen(argv[2], "r");
	if (!file)
		quit("Failed to open file");
	while ((c = fgetc(file)) != EOF)
		binradio(id, c);
	binradio(id, '\0');
	while (1)
		sigconfig();
	fclose(file);
	return (0);
}
